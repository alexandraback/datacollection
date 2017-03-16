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
int cons [138] ;
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int n ;
string name ;

cin >> name ;
cin >> n ;
long long sn = name.size() ;

long long ncount = 0 ;

long long a = 0 ;
int count = 0 ;
// cout << endl ;
// cout << name << " " << n << endl ;
for ( int p = 0 ; p < sn ; p ++ )
   {
   if ( cons[name[p]])
      count++ ;
   else
      count = 0 ;
   
   // cout << count << " " ;
   if ( count >= n )
      {
      // cout << name[p] << (p-a)*(sn-p-n-1) << endl ;

      long long f = (p-a-n+2) ;
      long long rem = sn-p ;
      // cout << "    a = " << a 
      //      << " p = " << p
      //      << " f = " << f 
      //      << " rem = " << rem 
      //      << endl ;
      ncount += f * (sn-p) ;
      a = p-n+2 ;
      }


   }


cout << "Case #" << case_number << ": " ;
cout << ncount ;
cout << endl ;
}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
int n ;
for ( int i = 0 ; i < 128 ; i ++ )
   cons [i] = 1 ;
cons['a'] = 0 ;
cons['e'] = 0 ;
cons['i'] = 0 ;
cons['o'] = 0 ;
cons['u'] = 0 ;

cin >> n ; getchar() ;
for ( int i = 1 ; i <= n ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
