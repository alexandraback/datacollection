// ****************************************************************************
// Code developed starting from Rustyoldman's Google Code jam template
// GCJ 2013 round 1A, problem B
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
long long start , regain , tasks ;
long long value [100000] ;
long long spent [100000] ;
long long sofar [100][100] ;
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{

cin >> start >> regain >> tasks ;
for ( int i = 0 ; i < tasks ; ++i )
   {
   cin >> value[i] ;
   }

for ( int t = 0 ; t < tasks ; t ++ )
   for ( int e = 0 ; e <= start ; e ++ )
      sofar [t][e] = 0 ;


for ( int e = regain ; e <= start ; ++e )
   sofar[0][e] = (start-e+regain)*value[0] ;

for ( int t = 1 ; t < tasks ; ++t )
   for ( int e = regain ; e <= start ; ++e )
      {
      for ( int pe = regain ; pe <= start ; ++pe )
         {
         if ( e - regain <= pe )
            {
            //            cout << pe << " " << ( pe-e+regain ) * value[t] + sofar [t-1][pe] << " " ;
            if ( ( pe-e+regain ) * value[t] + sofar [t-1][pe] > sofar[t][e] )
               sofar[t][e] = ( pe+regain-e ) * value[t] + sofar [t-1][pe] ;
            }
         }
      //cout << endl ;
      }

//    cout << endl ;
// for ( int t = 0 ; t < tasks ; t ++ )
//    {
//    cout << "t = " << t << " : " ;
//    for ( int e = 0 ; e <= start ; ++e )
//       cout << sofar[t][e] << " " ;
//    cout << endl ;
//    }

cout << "Case #" << case_number << ": " ;
cout << sofar [tasks-1][regain] ;
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
