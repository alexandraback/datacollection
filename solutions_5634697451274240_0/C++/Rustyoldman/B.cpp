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
string n ;
cin >> n ;
int flips = 0 ;

bool happy = true ;
for ( int i = 0 ; i < n.size() ; ++i )
   if ( n[i] != '+' )
      happy = false ;

while ( ! happy )
   {
   int p ;
   ++flips ;
   for ( p = 0 ; p < n.size() && n[p] == n[0] ; ++p )
      { }

   string fs ;
   for ( int i = p-1 ; i >= 0 ; --i )
      if ( n[i] == '-' )
         fs.push_back('+') ;
      else
         fs.push_back('-') ;
   for( int i = p ; i < n.size() ; ++i )
      fs.push_back(n[i]) ;
n = fs ;
 happy = true ;
for ( int i = 0 ; i < n.size() ; ++i )
   if ( n[i] != '+' )
      happy = false ;
   }

cout << "Case #" << case_number << ": " ;
cout << flips ;
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
