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
int n , xg , yg ;
cin >> xg >> yg ;

string answer = "" ;

int x = 0 ;
int y = 0 ;
int boing = 1 ;

//cout << xg << " " << yg << enld ;
while ( x != xg || y != yg )
   {
   //cout << boing << " " << x << " " << y << endl ;
   //cout << "   " <<" " << (xg-x) << " " << (yg-y) << endl ;
   
   if ( abs ( xg-x ) > abs(yg-y) )
      {
      //cout << "abs x > abs y " ;
      
      if ( abs(xg-x) >= boing )
         {
         if ( xg-x < 0 )
            {
            //cout << "case 1" << endl ;
            x -= boing ;
            answer += "W" ;
            }
         else
            {
            //cout << "case 2" << endl ;
            x += boing ;
            answer += "E" ;
            }
         }
      else
         {
         if ( xg-x > 0 )
            {
            //cout << "case 3" << endl ;
            x -= boing ;
            answer += "W" ;
            boing ++ ;
            x += boing ;
            answer += "E" ;
            }
         else
            {
            //cout << "case 4" << endl ;
            x += boing ;
            answer += "E" ;
            boing ++ ;
            x -= boing ;
            answer += "W" ;
            }
         }
      }
   else
      {
      //cout << "abs x < abs y " ;
      if ( abs(yg-y) >= boing )
         {
         //cout << "abs y <= boing " ;
         if ( yg-y < 0 )
            {
            //cout << "case 5" << endl ;
            y -= boing ;
            answer += "S" ;
            }
         else
            {
            //cout << "case 6" << endl ;
            y += boing ;
            answer += "N" ;
            }
         }
      else
         {
         //cout << "abs y > boing " ;
         if ( yg-y > 0 )
            {
            //cout << "case 7" << endl ;
            y -= boing ;
            answer += "S" ;
            boing ++ ;
            y += boing ;
            answer += "N" ;
            }
         else
            {
            //cout << "case 8" << endl ;
            y += boing ;
            answer += "N" ;
            boing ++ ;
            y -= boing ;
            answer += "S" ;
            }
         }
      }
   ++boing ;
   }


boing = 1 ;
y = x = 0 ; 
for ( int i = 0 ; i < answer.size() ; i ++ )
   {
   if ( answer[i] == 'N' ) y+=boing ;
   if ( answer[i] == 'S' ) y-=boing ;
   if ( answer[i] == 'E' ) x+=boing ;
   if ( answer[i] == 'W' ) x-=boing ;
   boing ++ ;
   }
if ( x != xg || y != yg )
   cout << "error " << x << " " << y << endl ;

cout << "Case #" << case_number << ": " ;
cout << answer ;

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
