// ****************************************************************************
// Code developed starting from Rustyoldman's Google Code jam template
// ****************************************************************************
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cstdlib>
#define enld endl
using namespace std ;
// ****************************************************************************
int getchar ( )
// ****************************************************************************
{
if ( cin.eof() )
   return -1 ;
int ch = cin.get() ;
if ( cin.fail() )
   return -1 ;
return ch ;
}
// ****************************************************************************
string tokenstartchars 
= "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
string tokenchars 
= ".0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
// ****************************************************************************
string gettoken ( )
// ****************************************************************************
{
int ch ;

ch = cin.get() ;

while ( ! cin.eof () && (ch == ' ' || ch == '\n') )
   ch = getchar ( ) ;

if ( ch == -1 )
   return "ERROR" ;

string ans = "" ;
if ( tokenstartchars.find( (char) ch ) != string::npos ) 
   {
   while ( tokenchars.find ( (char) ch ) != string::npos)
      {
      ans.push_back((char) ch) ;
      ch = getchar ( ) ;
      }
   cin.putback((char)ch) ;
   return ans ;
   }

ans = "" ;
ans.push_back ( (char) ch ) ;
return ans ;
}
// ****************************************************************************
double getdouble ( ) 
// ****************************************************************************
{
double a ;
cin >> a ;
return a ;
}
// ****************************************************************************
int getint ( ) 
// ****************************************************************************
{
while ( cin.peek ( ) == ' ' || cin.peek ( ) == '\n' )
   getchar ( ) ;
int sign = 1 ;
if ( cin.peek ( ) == '-' )
   {
   sign = -1 ;
   getchar ( ) ;
   }
string toke = gettoken ( ) ;
if ( sign == -1 && toke == "2147483648" )
   return -2147483648 ;

return sign * atoi ( toke.c_str() ) ;
}
// ****************************************************************************
int r , c , m , out [50][50] ;
int flip = 0 ;
// ****************************************************************************
void print ( ) 
// ****************************************************************************
{
if ( !flip )
for ( int row = 0 ; row < r ; ++row )
   {
   for ( int col = 0 ; col < c ; ++col )
      {
      printf ( "%c" , out [ row ] [ col ] ) ;
      }
   cout << endl ;
   }
else
   for ( int col = 0 ; col < c ; ++col )
   {
for ( int row = 0 ; row < r ; ++row )
      {
      printf ( "%c" , out [ row ] [ col ] ) ;
      }
   cout << endl ;
   }
}
// ****************************************************************************
void fill_mines ( int rm , int cm)
// ****************************************************************************
{
for ( int col = 0 ; col < c ; ++col )
   for ( int row = 0 ; row < r ; ++row )
         out [ row ] [ col ] = '.' ;
            
for ( int col = 0 ; col < cm ; ++col )
   for ( int row = 0 ; row < rm ; ++row )
      {
      if ( m > 0 )
         {
         out [ row ] [ col ] = '*' ;
         }
      --m ;
      }
out [ r-1 ] [ c-1 ] = 'c' ;
}
// ****************************************************************************
void dig_hole ( int rh , int ch)
// ****************************************************************************
{
for ( int col = 0 ; col < c ; ++col )
   for ( int row = 0 ; row < r ; ++row )
         out [ row ] [ col ] = '*' ;
            
int hole = r*c-m ;
   for ( int row = 0 ; row < rh ; ++row )
for ( int col = 0 ; col < ch ; ++col )
      {
      if ( hole > 0 ) 
         out [ row ] [ col ] = '.' ;
      -- hole ;
      }
   out [ 0 ] [ 0 ] = 'c' ;
}
// ****************************************************************************
void fillr ( )
// ****************************************************************************
{
   int count = 0 ;
      for ( int col = 0 ; col < c ; ++col )
   for ( int row = 0 ; row < r ; ++row )
         {
         if ( count < m )
            out [ row ] [ col ] = '*' ;
         else 
            out [ row ] [ col ] = '.' ;
         ++ count ;
         }
   out [ r-1 ] [ c-1 ] = 'c' ;
}
// ****************************************************************************
void fill ( )
// ****************************************************************************
{
   int count = 0 ;
   for ( int row = 0 ; row < r ; ++row )
      for ( int col = 0 ; col < c ; ++col )
         {
         if ( count < m )
            out [ row ] [ col ] = '*' ;
         else 
            out [ row ] [ col ] = '.' ;
         ++ count ;
         }
   out [ r-1 ] [ c-1 ] = 'c' ;
}
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
cin >> r >> c >> m ;
cout << "Case #" << case_number << ":" << endl ; 
int hole = r*c - m ;

flip = 0 ;
if ( r > c )
   {
   int t = r ;
   r = c ;
   c = t ;
   flip = 1 ;
   }

if ( r == 1 || m == r*c-1 )
   {
   fill_mines ( r , c ) ;
   print ( ) ;
   return ;
   }

for ( int rh = 2 ; rh <= r ; ++rh )  // fill with mines then dig out empties
   for ( int ch = 2 ; ch <= c ; ++ch )
      {
      int right_border = c - ch ;
      int lower_border = r - rh ;
      int excess = rh * ch - hole ;
      if ( rh*ch == hole || 
           ( rh > 2 && excess > 0 && excess < ch - 1 ) )
         {
      //cout << hole << " " << rh << "x" << ch << " r " << right_border << " l " << lower_border 
           //<< " e " << excess << endl ;
         dig_hole ( rh , ch ) ;
         print ( ) ;
         return ;
         }
      }

for ( int rm = 1 ; rm <= r-2 ; ++rm )    // fill with mines (assume not whole side)
   for ( int cm = 1 ; cm <= c-2 ; ++cm ) // so right and lower borders are > 1
      if ( rm*cm >= m )
         {
      //cout << m << " " << rm << "x" << cm << " r " << endl ;
         fill_mines ( rm , cm ) ; // should go right to left
         print ( ) ;
         return ;
         }


cout << "Impossible" << endl ;
}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
int n ;
cin >> n ; getchar() ;
for ( int i = 1 ; i <= n ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
