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
int m2 [1001][1001] ;
int n ;
int reach [1001] ;
int diamond ;

// ****************************************************************************
void curse ( int pos )
// ****************************************************************************
{
if ( diamond )
   return ;
if ( reach [pos] )
   {
   diamond = 1 ;
   return ;
   }
reach[pos] = 1 ;

for ( int next = 1 ; next <= n ; next ++ )
   if ( m2[pos][next] )
      curse ( next ) ;
}
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
cout << "Case #" << case_number << ": " ;
cin >> n ;
for ( int i = 1 ; i <= n ; i ++ )
   {
   int k ;
   cin >> k ;
   for ( int j = 1 ; j <= n ; j ++ )
      m2[i][j] = 0 ;
   
   for ( int j = 0 ; j < k ; j ++ )
      {
      int c ;
      cin >> c ;
      m2[i][c] = 1 ;
      }
   }


diamond = 0 ;
for ( int start = 1 ; start <= n ; start ++ )
   {
   for ( int i = 1 ; i <= n ; i ++ )
      reach[i] = 0 ;
   curse(start) ;
   if ( diamond )
      {
      cout << "Yes" << endl ;
      return ;
      }
   }

   

cout << "No" << endl ;
}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
int nn ;
cin >> nn ; getchar() ;
for ( int i = 1 ; i <= nn ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
