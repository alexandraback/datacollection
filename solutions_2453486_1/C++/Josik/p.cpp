#include <algorithm>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

char board[ 10 ][ 10 ];
char winner;

void checkDiag1 ( void )
{
  char symb = 'A';
  for ( int j = 0; j < 4; j++ )
  {
    if ( board[ j ][ j ] == '.' ) return;
    else if ( board[ j ][ j ] != 'T' )
    {
      if ( symb == 'A' ) symb = board[ j ][ j ];
      else if ( symb != board[ j ][ j ] ) return; 
    }
  }
  winner = symb; 
}

void checkDiag2 ( void )
{
  char symb = 'A';
  for ( int j = 0; j < 4; j++ )
  {
    if ( board[ j ][ 3 - j ] == '.' ) return;
    else if ( board[ j ][ 3 - j ] != 'T' )
    {
      if ( symb == 'A' ) symb = board[ j ][ 3 - j ];
      else if ( symb != board[ j ][ 3 - j ] ) return; 
    }
  }
  winner = symb; 
}

void checkRow ( int i )
{
  char symb = 'A';
  for ( int j = 0; j < 4; j++ )
  {
    if ( board[ i ][ j ] == '.' ) return;
    else if ( board[ i ][ j ] != 'T' )
    {
      if ( symb == 'A' ) symb = board[ i ][ j ];
      else if ( symb != board[ i ][ j ] ) return; 
    }
  }
  winner = symb;
}

void checkCol ( int j )
{
  char symb = 'A';
  for ( int i = 0; i < 4; i++ )
  {
    if ( board[ i ][ j ] == '.' ) return;
    else if ( board[ i ][ j ] != 'T' )
    {
      if ( symb == 'A' ) symb = board[ i ][ j ];
      else if ( symb != board[ i ][ j ] ) return; 
    }
  }
  winner = symb;
}

int main ( int argc, char * argv [] )
{
  int cases;
  cin >> cases; cin . get();
  for ( int i = 1; i <= cases; i++ )
  {
    winner = 'A';
    int loaded = 0;
    for ( int j = 0; j < 4; j++ )
    {
      for ( int k = 0; k < 4; k++ )
      {
        board[ j ][ k ] = cin . get();
        if ( board[ j ][ k ] != '.' ) ++loaded;
      }
      cin . get();
    }
    cin . get();
    
    for ( int j = 0; j < 4; j++ )
    {
      checkRow( j );
      checkCol( j );
    }
    checkDiag1();
    checkDiag2();
    
    cout << "Case #" << i << ": ";
    switch ( winner )
    {
      case 'A':
        if ( loaded == 16 ) cout << "Draw" << endl;
        else cout << "Game has not completed" << endl;
        break;
      case 'O':
        cout << "O won" << endl;
        break;
      case 'X':
        cout << "X won" << endl;
      default:
        break;
    }
  }
  
  return 0;
}