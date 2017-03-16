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
int n ;
cin >> n ;

double naomi [1000] ;
double ken [1000] ;
int used [1000] ;

for ( int i = 0 ; i < 1000 ; ++i )
   used[i] = 0 ;

for ( int i = 0 ; i < n ; ++i )
   cin >> naomi[i] ;
for ( int i = 0 ; i < n ; ++i )
   cin >> ken[i] ;

int dec = 0 ;
int war = 0 ;

sort ( naomi , naomi+n ) ;
sort ( ken , ken+n ) ;

int ken_low = 0 ;
int ken_high = n-1 ;
for ( int i = 0 ; i < n ; ++i )
   {
   int play = -1 ;
   for ( int k = 0 ; k < n ; ++k )
      {
      if ( used[k] == 0 && play == -1 )
         play = k ;
      if ( used[k] == 0 && ken[k] > naomi[i] )
         {
         play = k ;
         break ;
         }
      }
   if ( ken[play] < naomi[i] )
      war ++ ;
   used[play] = 1 ;
   }

ken_low = 0 ;
ken_high = n-1 ;

for ( int i = 0 ; i < n ; ++i )
   {
   if ( naomi[i] > ken[ken_low] )
      {
      dec ++ ;
      ken_low ++ ;
      }
   else
      {
      ken_high -- ;
      }
   }

cout << "Case #" << case_number << ": " ;
cout << dec << " " << war ;
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
