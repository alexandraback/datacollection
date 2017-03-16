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
// ***********************************************************************
int gcd ( int a , int b )
// ***********************************************************************
{
if ( a == 0 ) return b ;
return gcd ( b%a , a ) ;
}
// ***********************************************************************
typedef char Line [1000] ;
char sbad[1000][1000] ;
char sresult[1000][1000] ;
Line * bad ;
Line * result ;
// ***********************************************************************
bool trace ( int sx , int sy , int ex , int ey , int & c )
// ***********************************************************************
{
int dx = ex-sx ;
int dy = ey-sy ;
int step = gcd ( max(1,abs(dx)) , max(1,abs(dy))) ;
if ( dx == 0 || dy == 0 ) 
   step = max ( abs(dx), abs(dy) ) ;

dx /= step ;
dy /= step ;

for ( int s = 1 ; s < step ; s ++ )
   {
   if ( bad[sy+s*dy][sx+s*dx] != ' ' )
      {
      // cout << "trace " << sx << " " << sy << " " << ex << " " << ey << " "
      //      << "miss" << endl ;
      return 0 ;
      }
   }
c++ ;
// cout << "trace " << sx << " " << sy << " " << ex << " " << ey << " "
//      << c << " step " << step << endl ;
return 1 ;
}
// ***********************************************************************
void do_case ( int case_number )
// ***********************************************************************
{
int h , w , d ;
cin >> h >> w >> d ;
//cout << h << " " <<  w << " " <<  d << endl ;
string b [100] ;
for ( int y = 0 ; y < h ; y ++ )
   cin >> b[y] ;
// for ( int y = 0 ; y < h ; y ++ )
//    cout << b[y] << endl ;


for ( int i = 0 ; i < 1000 ; i ++ )
   for ( int j = 0 ; j < 1000 ; j ++ )
      sresult [i][j] = sbad[i][j] = ' ' ;

bad = (Line*) (&sbad[500][500]) ;
result = (Line*) (&sresult[500][500]) ;
                      
int mx = -1 ; 
int my = -1 ;
for ( int y = 0 ; y < h ; y ++ )
   for ( int x = 0 ; x < w ; x ++ )
      if ( b[y][x] == 'X' )
         {
         mx = x ;
         my = y ;
         }
// cout << "mx = " << mx << " my = " << my << endl ;

int c = 0 ;
int R = w+w-mx-mx-3 ;
int L = mx+mx-1 ;
int U = my+my-1 ;
int D = h+h-my-my-3 ;
int W = w+w-4 ;
int H = h+h-4 ;
int d2 = d*d*4 ;
int sx = mx+mx-1 ;
int sy = my+my-1 ;

for ( int x = -400 ; x <= 400 ; x ++ )
   if ( x % W == 0 )
      for ( int y = -400 ; y <= 400 ; y++ )
         if ( y % H == 0 )
            {
            bad[y][x] = '@' ;
            if ( ((x/W)&1) == 0 && ((y/H)&1) == 0 )
               {
               if ( y+sy < 500 && x+sx < 500 )
                  bad[y+sy][x+sx] = 'm' ;
               if ( y+sy < 500 && x-sx > -500 )
                  bad[y+sy][x-sx] = 'm' ;
               if ( y-sy > -500 && x+sx < 500 )
                  bad[y-sy][x+sx] = 'm' ;
               if ( y-sy > -500 && x-sx > 500 )
                  bad[y-sy][x-sx] = 'm' ;
               }
            }
bad[sy][sx] = 'x' ;
result[sy][sx] = 'x' ;
// for ( int x = -d*2-1+sx ; x <= d*2+1+sx ; x ++ )
//    cout << "--" ; cout << endl ;
// for ( int y = -d-d+sy-1 ; y <= d+d+sy+1 ; y++ )
//    {
//    for ( int x = -d-d+sx-1 ; x <= d+d+sx+1 ; x ++ )
//       cout << (bad[y][x] ) << " " ;
//    cout << endl ;
//    }
// for ( int x = -d*2-1 ; x <= d*2+1 ; x ++ )
//    cout << "--" ; cout << endl ;



for ( int y = -400 ; y <= 400 ; y++ )
   for ( int x = -400 ; x <= 400 ; x ++ )
      if ( bad[y][x] == 'm' )
         {
         if ( (y-sy)*(y-sy)+(x-sx)*(x-sx) <= d2 )
            {
            if ( trace ( sx , sy , x , y , c ) )
               result[y][x] = 'M' ;
            else
               result[y][x] = '.' ;
            }
         }
for ( int y = -400 ; y <= 400 ; y++ )
   for ( int x = -400 ; x <= 400 ; x ++ )
      if ( bad[y][x] == '@' )
         {
         if ( (y-sy)*(y-sy)+(x-sx)*(x-sx) <= d2/4 )
            {
            if ( trace ( sx , sy , x , y , c ) )
               result[y][x] = 'C' ;
            else
               result[y][x] = '.' ;
            }
         }


// for ( int y = -d*2-1+sy ; y <= d*2+1+sy ; y++ )
//    {
//    for ( int x = -d*2-1+sx ; x <= d*2+1+sx ; x ++ )
//       cout << (result[y][x] ) << " " ;
//    cout << endl ;
//    }
// cout << "L " << L << " R " << R << " U " << U << " D " << D 
//      << " W " << W << " H " << H << " d2 " << d2 << endl ;

cout << "Case #" << case_number << ": " << c ;
cout << endl ;
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
