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
int a , b ;
cin >> a >> b ;
map<int,int> cmin ;

int c = 0 ;
int d = 1 ;
int base = 1 ;
if ( a > 9 ) { d ++ ; base *= 10 ; } ;
if ( a > 99 ) { d ++ ; base *= 10 ; } ;
if ( a > 999 ) { d ++ ; base *= 10 ; } ;
if ( a > 9999 ) { d ++ ; base *= 10 ; } ;
if ( a > 99999 ) { d ++ ; base *= 10 ; } ;
if ( a > 999999 ) { d ++ ; base *= 10 ; } ;
if ( a > 9999999 ) { d ++ ; base *= 10 ; } ;
if ( a > 99999999 ) { d ++ ; base *= 10 ; } ;
//cout << "base = " << base << " d = " << d << endl ;

for ( int n = a ; n <= b ; n ++ )
   {
   int min = n ;
   int s = n ;
   for ( int t = 1 ; t < d ; t ++ )
      {
      s = s/10+s%10*base ;
      if ( s >= a && s <= b && s < min ) min = s ;
      }
   cmin[min] ++ ;
   //   cout << n << " " << min << " " << cmin[min] << endl ;
   }

map<int,int>::iterator it ;
for ( it = cmin.begin() ; it != cmin.end() ; ++it )
   {
   //   cout << (it->first) << " " << it->second << endl ;
   
   c += (it->second) * (it->second-1) / 2 ;
   }



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
