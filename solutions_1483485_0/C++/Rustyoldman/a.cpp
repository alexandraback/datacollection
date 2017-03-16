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
char cmap [256] ;
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int n ;
string g  ;
getline ( cin , g ) ;

string e ; e.resize ( g.size() ) ;
for ( int i = 0 ; i < g.size() ; i ++ )
   {
   e[i] = cmap[g[i]] ;
   }



cout << "Case #" << case_number << ": " << e ;
cout << endl ;
}
// ****************************************************************************
void putin ( string in , string out )
// ***************************************************************************
{
for ( int i = 0 ; i < in.size() ; i ++ )
   cmap[in[i]] = out[i] ;
}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
string in1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi" ;
string in2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" ;
string in3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv" ;
string out1 = "our language is impossible to understand" ;
string out2 = "there are twenty six factorial possibilities" ;
string out3 = "so it is okay if you want to just give up" ;
string gout = "aozq" ;
string gin = "yeqz" ;

for  ( int i = 0 ; i < 256 ; i ++ )
   cmap[i] = '-' ;

putin ( in1 , out1 ) ;
putin ( in2 , out2 ) ;
putin ( in3 , out3 ) ;
putin ( gin , gout ) ;
//sort( cmap+'a' , cmap+'z'+1 ) ;
//for ( int i = 'a' ; i <= 'z' ; i ++ )
//   cout << cmap[i] ;
//cout << endl ;


int n ;
cin >> n ; getchar() ;
for ( int i = 1 ; i <= n ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
/*
*/
