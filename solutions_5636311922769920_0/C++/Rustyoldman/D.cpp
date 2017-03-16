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

long long raze ( long long b , long long e )
{
long long a = 1 ;
for ( int i = 0 ; i < e ; ++i )
   a *= b ;
return a ;
} ;
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int k , c , s ;
cin >> k >> c >> s ;

if ( c == 1 )
   {
   if ( s < k )
      {
      cout << "Case #" << case_number << ": IMPOSSIBLE" << endl ;
      return ;
      }
   else
      {
      cout << "Case #" << case_number << ":" ;
      for ( int i = 1 ; i <= k ; ++i )
         cout << " " << i ;
      cout << endl ;
      return ;
      }
   }


if ( (k+1)/c > s )
   {
   cout << "Case #" << case_number << ": IMPOSSIBLE" << endl ;
   return ;
   }


cout << "Case #" << case_number << ": " ;

for ( int b = 0 ; b < k ; b+= c )
   {
   int d = 2 ;
   if ( b+1 >= k ) d = 1 ;
   
   long long v = 0 ;
   for ( int i = 0 ; i < c ; ++i )
      {
      v *= k ;
      if ( b+i < k )
         v += b + i ;
      else
         v += k-1 ;
      }

   cout << " " << v + 1 ;
   }


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
