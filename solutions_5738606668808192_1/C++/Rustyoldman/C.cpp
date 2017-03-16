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
int n , j ;
cin >> n >> j ;
int digit [33] ;
cout << "Case #" << case_number << ": " ;
cout << endl ;
int proof [10] ;

int cc = 0 ;
long long jc = 1 + (1<<(n-1)) ;

while ( cc < j )
   {
   long long div = 0 ;
   long long tdiv = 0 ;
   bool ok = true ;
   for ( long long base = 2 ; ok && base < 11 ; ++base )
      {
      int limit = 0 ;
      double sq = sqrt(base) ;
      double dlim = 1 ;
      for ( int i = 1 ; i < n ; ++i )
          {
          dlim *= sq ;
          if ( dlim > 1000000 )
            {
            dlim = 1000000 ;
            break ;
            }
         }
       limit = (int) dlim ;
 //      cout << limit << "L " ;
       for ( tdiv = 1 ; tdiv < limit ; tdiv += 2 )
          {
          div = tdiv ;
          if( tdiv == 1 ) div = 2 ;
          int rem = 0 ;
          for ( int p = n-1 ; p >= 0 ; --p )
             {
             rem = (rem*base) + ((jc&(1LL<<p))!=0) ;
             rem %= div ;
             }
         if ( rem == 0 )
             {
             proof[base] = div ;
             break ;
             }
         }
      if ( tdiv >= limit )
         {
         jc += 2 ;
         ok = false ;
         break ;
         }
      }
//cout << endl ;
   if ( ok )
      {
      for ( int p = n-1 ; p >= 0 ; --p )
         cout << ((jc&(1LL<<p))!= 0 ) ;
      for ( int i = 2 ; i < 11 ; ++i )
         cout << " " << proof[i] ;
      cout << endl ;
      jc += 2 ;
      cc ++ ;
      }
   }
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
