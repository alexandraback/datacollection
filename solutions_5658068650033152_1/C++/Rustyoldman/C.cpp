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
void do_case ( int case_number )
// ****************************************************************************
{
int n , m , k ;
cin >> n >> m >> k ;
int mink = k ;
if ( n > m ) // n will be smaller
   {
   int t = n ;
   n = m ;
   m = t ;
   }


for ( int i = 3 ; i <= n ; ++i )
   for ( int j = 3 ; j <= m ; ++j )
      {
      int ex = k-i*j ;
      
      if ( ex > -5 && ex < i+j+2 ) 
         {
         //         cout << i << " " << j << " " << ex << " " << i*2+j*2-4 + ex << endl ;
         mink = min ( mink ,  i*2+j*2-4 + ex ) ;
         }
      }
      
for ( int h = 3 ; h <= n ; h++ )
   for ( int w = h ; w <= m ; w++ )
      {
      for ( int c = 1 ; c <= h/2 ; c++ ) // take out c from corner
         {
         for ( int p = 0 ; p <= 4 ; p++ ) // on p corners
            {
            if ( ( n%2==0 ) && c == h/2 && p>2 ) break ;
            
            int s = h*2+w*2-4  -c*p - (c-1)*(4-p) ;
            int m = h*w - p*(c*c+c)/2 - ( (4-p)*((c-1)*(c-1)+c-1) ) / 2 ;

            if ( m >= k && s < mink )
               {
               // cout << h << " " << w << " " << c << " " << p 
               //      << " " << m << " " << s << endl ;
               mink = min ( mink , s ) ;
               }
            }
         }
      }

cout << "Case #" << case_number << ": " << mink ;
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
