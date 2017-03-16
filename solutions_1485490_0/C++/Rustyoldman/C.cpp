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
long long boxc [100] ;
int boxi [100] ;
long long toyc [100] ;
int toyi [100] ;

long long dp [101][101] ;
bool done [101][101] ;
int nbox ; int ntoy;
long long curse ( int b , int t , long long bc , long long tc ) ;

// ****************************************************************************
long long cursei ( int b , int t , long long bc , long long tc )
// ****************************************************************************
{
long long ans ;
if ( done[b][t] && bc == boxc[b] && tc == toyc[t] ) return dp[b][t] ;
if ( b == nbox || t == ntoy ) 
   {
   done[b][t] = 1 ;
   dp[b][t] = 0 ;
   return 0 ;
   }

if ( boxi[b] == toyi[t] )
   {
   long long use = min ( bc,tc ) ;
   //   cout << use << " matches " << enld ;
   if ( bc == use && tc == use )
      {
      ans = use+curse(b+1,t+1, boxc[b+1] , toyc[t+1]) ;
      dp[b][t] = ans ;
      done[b][t] = 1 ;
      return ans ;
      }
   else if ( bc == use )
      {
      ans = use+curse(b+1,t, boxc[b+1] , tc-use) ;
      return ans ;
      }
   else
      {
      ans = use+curse(b,t+1, bc-use , toyc[t+1]) ;
      return ans ;
      }
   }
else
   {
   ans = max ( curse(b+1,t,boxc[b+1],tc) , curse (b, t+1 , bc , toyc[t+1]) ) ;
   if ( tc = toyc[t] && bc == boxc[b] )
      {
      dp[b][t] = ans ;
      done[b][t] = 1 ;
      }
   return ans ;
   }
}

// ****************************************************************************
long long curse ( int b , int t , long long bc , long long tc )
// ****************************************************************************
{
long long ans = cursei(b,t, bc ,tc ) ;
//cout << "curse " << b << " " << t << " = " << ans << endl ;
return ans ;
}
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
cin >> nbox >> ntoy ;
for ( int i = 0 ; i < nbox ; i ++ )
   cin >> boxc[i] >> boxi[i] ;
for ( int i = 0 ; i < ntoy ; i ++ )
   cin >> toyc[i] >> toyi[i] ;


// for ( int i = 0 ;i < nbox ; i ++ )
//    cout << boxc[i] << " " << boxi[i] << " " ;
// cout << endl ;
// for ( int i = 0 ;i < ntoy ; i ++ )
//    cout << toyc[i] << " " << toyi[i] << " " ;
// cout << endl ;

for ( int i = 0 ;i <= nbox ; i ++ )
   for ( int j = 0 ; j <= ntoy ; j ++ )
      {
      dp[i][j] = 0 ;
      done[i][j] = 0 ;
      }

long long ans = curse ( 0 , 0 , boxc[0] , toyc[0]) ;

// for ( int i = 0 ;i < nbox ; i ++ )
//    {
//    for ( int j = 0 ; j < ntoy ; j ++ )
//       cout << dp[i][j] << " " ;
//    cout << enld ;
//    }




cout << "Case #" << case_number << ": " ;
cout << ans ;
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
