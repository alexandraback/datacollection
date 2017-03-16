#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;

int dx[ 8 ] = { -1, -1, -1, 0, 1, 1,  1,  0 };
int dy[ 8 ] = { -1,  0,  1, 1, 1, 0, -1, -1 };

char a[ 100 ][ 100 ];
char b[ 100 ][ 100 ];

bool swapped;

void print()
{
   int i, j;
   if( !swapped )
   {
      for( i = 0; i < n; ++i )
      {
         for( j = 0; j < m; ++j )
            cout << a[ i ][ j ];
         cout << endl;
      }
   }
   else
   {
      for( j = 0; j < m; ++j )
      {
         for( i = 0; i < n; ++i )
            cout << a[ i ][ j ];
         cout << endl;
      }
   }
}

void solve()
{
   int i, j;
   swapped = false;
   if( n < m )
   {
      swap( n, m );
      swapped = true;
   }

   for( i = 0; i < n; ++i )
   for( j = 0; j < m; ++j )
      a[ i ][ j ] = '.';

   // n > m;
   if( m == 1 )
   {
      a[ 0 ][ 0 ] = 'c';
      int i;
      for( i = 1; i <= k; ++i )
         a[ n - i ][ 0 ] = '*';
      for( ; i < m; ++i )
         a[ n - i ][ 0 ] = '.';
      print();
      return;
   }

   string impossible = "Impossible";

   if( m == 2 )
   {
      if( k == 2 * n - 1 )
      {
         for( i = 0; i < n; ++i )
            a[ i ][ 0 ] = a[ i ][ 1 ] = '*';
         a[ 0 ][ 0 ] = 'c';
         print();
         return;
      }
      if( k > 2 * ( n - 2 ) || k % 2 == 1 )
      {
         cout << impossible << endl;
         return;
      }
      for( i = 0; i < n - k / 2; ++i )
         a[ i ][ 0 ] = a[ i ][ 1 ] = '.';
      for( ; i < n; ++i )
         a[ i ][ 0 ] = a[ i ][ 1 ] = '*';
      a[ 0 ][ 0 ] = 'c';
      print();
      return;
   }

   int down = ( n - 3 ) * m;
   if( down >= k )
   {
      for( i = n - 1; i >= 3 && k > 0; --i )
      for( j = m - 1; j >= 0 && k > 0; --j )
      {
         a[ i ][ j ] = '*';
         --k;
      }
      if( j == 0 )
      {
         a[ i + 1 ][ 1 ] = '.';
         a[ i ][ m - 1 ] = '*';
      }
      for( i = 0; i < n; ++i )
      for( j = 0; j < m; ++j )
      if( a[ i ][ j ] != '*' )
         a[ i ][ j ] = '.';
      a[ 0 ][ 0 ] = 'c';
      print();
      return;
   }
   for( i = 3; i < n; ++i )
   for( j = 0; j < m; ++j )
      a[ i ][ j ] = '*';
   k -= down;
   for( j = m - 1; k > 0 && j >= 3; --j )
   {
      if( k >= 3 )
      {
         a[ 0 ][ j ] = a[ 1 ][ j ] = a[ 2 ][ j ] = '*';
         k -= 3;
      }
      else
      {
         if( k == 2 )
            a[ 2 ][ j ] = a[ 2 ][ j - 1 ] = '*';
         else
            a[ 2 ][ j ] = '*';
         k = 0;
      }
   }
   if( k == 1 )
      a[ 2 ][ 2 ] = '*';
   else if( k == 3 )
      a[ 2 ][ 0 ] = a[ 2 ][ 1 ] = a[ 2 ][ 2 ] = '*';
   else if( k == 5 )
      a[ 2 ][ 0 ] = a[ 2 ][ 1 ] = a[ 2 ][ 2 ] = a[ 1 ][ 2 ] = a[ 0 ][ 2 ] = '*';
   else if( k == 8 )
   {
      for( i = 0; i < 3; ++i )
      for( j = 0; j < 3; ++j )
         a[ i ][ j ] = '*';
      a[ 0 ][ 0 ] = 'c';
   }
   else if( k != 0 )
   {
      cout << impossible << endl;
      return;
   }
   for( i = 0; i < n; ++i )
   for( j = 0; j < m; ++j )
   if( a[ i ][ j ] != '*' )
      a[ i ][ j ] = '.';
   a[ 0 ][ 0 ] = 'c';
   print();
}

bool in( int i, int j )
{
   return i >= 0 && i < n && j >= 0 && j < m;
}

bool mines_around( int i, int j )
{
   int x, y;
   for( int t = 0; t < 8; ++t )
   {
      x = i + dx[ t ];
      y = j + dy[ t ];
      if( in( x, y ) && b[ x ][ y ] == '*' )
         return true;
   }
   return false;
}

bool saints_around( int i, int j )
{
   int x, y;
   for( int t = 0; t < 8; ++t )
   {
      x = i + dx[ t ];
      y = j + dy[ t ];
      if( in( x, y ) && b[ x ][ y ] == '#' )
         return true;
   }
   return false;
}

void fill_goods( int i, int j )
{   
   b[ i ][ j ] = '#';
   int x, y;
   for( int t = 0; t < 8; ++t )
   {
      x = i + dx[ t ];
      y = j + dy[ t ];
      if( in( x, y ) && b[ x ][ y ] == '.' && !mines_around( x, y ) )
      {
         fill_goods( x, y );
      }
   }
}

bool good()
{
   int cnt = 0, i, j;
   for( i = 0; i < n; ++i )
      for( j = 0; j < m; ++j )
         if( b[ i ][ j ] == '*' )
            ++cnt;
         else
            b[ i ][ j ] = '.';
   if( cnt != k )
      return false;

   if( k == n * m - 1 )
      return true;

   for( i = 0; i < n; ++i )
      for( j = 0; j < m; ++j )
         if( b[ i ][ j ] == '.' && !mines_around( i, j ) )
         {
            fill_goods( i, j );
            j = m;
            i = n;
         }
   for( i = 0; i < n; ++i )
      for( j = 0; j < m; ++j )
      {
         if( b[ i ][ j ] == '.' && !mines_around( i, j ) )
            return false;
         if( b[ i ][ j ] == '.' && !saints_around( i, j ) )
            return false;
      }
   return true;
}

bool fix_row( int i )
{
   if( i == n )
      return good();
   for( int mask = 0; mask < ( 1 << m ); ++mask )
   {
      for( int j = 0; j < m; ++j )
         if( mask & ( 1 << j ))
            b[ i ][ j ] = '*';
         else
            b[ i ][ j ] = '.';
      if( fix_row( i + 1 ))
         return true;
   }
   return false;
}

void bruteforce()
{
   if( fix_row( 0 ))
   {
      int i, j;
      for( i = 0; i < n; ++i )
         for( j = 0; j < m; ++j )
            if( b[ i ][ j ] == '#' )
            {
               b[ i ][ j ] = 'c';
               i = n;
               j = m;
            }
      for( i = 0; i < n; ++i )
      {
         for( j = 0; j < m; ++j )
            if( b[ i ][ j ] == '#' )
               cout << '.';
            else
               cout << b[ i ][ j ];
         cout << endl;
      }
   }
   else
      cout << "Impossible" << endl;
}

int main()
{
   freopen( "c-small-1.in", "r", stdin );
   freopen( "c-small-1.out", "w", stdout );
   int t;
   cin >> t;
   for( int i = 1; i <= t; ++i )
   {
      cin >> n >> m >> k;
      cout << "Case #" << i << ":" << endl;
      solve( );
   }
}