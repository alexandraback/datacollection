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
int chest_count ;
int keys [301] ;
int booty [301][401] ;
char unused [301] ;
int history [301] ;
int open [301] ;

int memo [20000000] ;
int mask ;



// ****************************************************************************
int curse ( int level ) 
// ****************************************************************************
{

if ( level == chest_count ) return 1 ;

for ( int i = 1 ; i <= chest_count ; ++ i )
   if ( unused [i] && keys[open[i]] > 0 )
      {
      int bit = (1<<i) ;
      mask |= bit ;
      if ( memo[mask] )
         {
         mask &= (~bit ) ;
         continue ;
         }

      history [level] = i ; 
      --keys[open[i]] ;
           

      // cout << "trying " ;
      // for ( int d = 0 ; d <= level ; d ++ )
      //    cout << history[d] << " " ;

      unused[i] = 0 ;

      for ( int quay = 0 ; booty[i][quay] > 0 ; ++quay )
         {
         // cout << " +" << booty[i][quay] << " " ;
         ++ keys[booty[i][quay]] ;
         }
      
      // for ( int hk = 1 ; hk < 300 ; ++ hk )
      //    if ( keys[hk] > 0 )
      //       cout << keys[hk] << "-" << hk << " " ;
      
      // cout << endl ;
      if ( level == chest_count - 1 ) return 1 ;
      
      if ( curse ( level+1 ) )
         return 1 ;

      memo [ mask ] = 1 ;
      mask &= (~bit ) ;
      unused[i] = 1 ;
      for ( int quay = 0 ; booty[i][quay] > 0 ; ++quay )
         -- keys[booty[i][quay]] ;
      ++keys[open[i]] ;
      }
return 0 ;
}
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int start_keys ;

cin >>  start_keys >> chest_count ;

for ( int i = 0 ; i < 300 ; ++ i )
   keys[i] = 0 ;
for ( int i = 0 ; i < start_keys ; ++ i )
   {
   int k ;
   cin >> k ;
   ++keys[k] ;
   }


for ( int c = 1 ; c <= chest_count ; c++ )
   {
   int op ;
   cin >> op ;
   open[c] = op ;
   int kc ;
   cin >> kc ;
   for ( int ck = 0 ; ck < kc ; ++ck )
      {
      int k ;
      cin >> k ;
      booty[c][ck] = k ;
      }
   booty[c][kc] = 0 ;
   }

mask = 0 ;
for ( int i = 0 ; i < 20000000 ; ++i )
   memo[i] = 0 ;


// for ( int c = 1 ; c <= chest_count ; c++ )
//    {
//    cout << "key " << open[c] << " opens chest " << c << " which contains keys " ;
//    for ( int j = 0 ; booty[c][j] > 0 ; ++j )
//       cout << booty[c][j] << " " ;
//    cout << endl ;
//    }

   

for ( int i = 0 ; i <= 300 ; ++ i )
   unused[i] = 1 ;




cout << "Case #" << case_number << ": " ;

if ( curse ( 0 ) ) 
   {
   cout << history[0] ;
   for ( int i = 1 ; i < chest_count ; i ++ )
      cout << " " << history[i] ;
   }

else
cout << "IMPOSSIBLE" ;

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
