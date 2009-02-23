/* Copyright (C) 2007 - 2008 MySQL AB, 2008 - 2009 Sun Microsystems, Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "PreparedStatementTest.h"

namespace testsuite
{
namespace regression
{

  void PreparedStatementTest::testStmtClose()
  {
    pstmt.reset( conn->prepareStatement( "select ?" ) );

    pstmt->setString( 1, "dummy" );

    pstmt->executeQuery();

    pstmt->close();

    // Application crashed on the destructor if close was closed before.
    // prepared statement had to contain any parameter.
    pstmt.reset();
  }


  void PreparedStatementTest::setUp()
  {
    super::setUp();

    dbmd.reset(conn->getMetaData());
  }
}
}
