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
double score ( int me , vector<int> all )
// ****************************************************************************
{
// cout << endl ;
// for ( int i = 0 ; i < all.size() ; i ++ )
//    cout << all[i] << " " ;
// cout << endl ;
sort(all.begin() , all.end() ) ;
// for ( int i = 0 ; i < all.size() ; i ++ )
//    cout << all[i] << " " ;
// cout << endl ;
int tot = 0 ;
for ( int i = 0 ; i < all.size() ; i ++ )
   {
   tot += all[i] ;
   }

//cout << "total " << tot << " me = " << me << endl ;

double best = 0.0 ;
if ( me == tot ) return 0 ;
for ( int n = 1 ; n <= all.size() ; n ++ )
   {
   while ( n < all.size() && all[n-1] == all[n] )
      n++ ;
   ///   cout << " testing " << n << " up to " << all[n-1] << endl ;
   int sum = 0 ;
   for ( int i = 0 ; i < n ; i ++ )
      sum += all[i] ;
   sum += tot ;
   double same = sum / (double) n ;

   double res = tot ;
   
   if ( same >= all[n-1]-0.0000001 )
      best = max(0.0,(same-me)/tot) ;
   
   
   // cout << "same = " << same << " best precent = " << best << " current percent = " << (same-me)/tot <<  endl ;
   //    cout << "   n = " <<  n << " same = " << same << " me = " << me << " " << (same-me)/tot << endl ;
   }
return best ;
}
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int n ;
cin >> n ;
vector<int> p ( n ) ;
for ( int i = 0 ; i < n ; i ++ )
   cin >> p[i] ;





cout << "Case #" << case_number << ":" ;
cout.precision(10) ;
vector<double> d ( n ) ;

for ( int i = 0 ; i < n ; i ++ )
   {
   d[i] = score ( p[i] , p )*100 ;
   // cout << endl ;

   // int tot = 0 ;
   // for ( int j = 0 ; j < n ; j ++ ) tot += p[j] ;

   // double goal = p[i]+tot*d[i]/100 ;
   // cout << "tot = " << tot << " goal = " << goal << endl ;
   
   // int rem = 0 ;
   // for ( int j = 0 ; j < n ; j ++ )
   //    if ( p[j] < goal )
   //       rem += goal - p[i] ;
   
   // cout << " rem " << rem << endl ;
   
   }
for ( int i = 0 ; i < n ; i ++ )
   cout << " " << d[i] ;


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
