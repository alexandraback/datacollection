// ****************************************************************************
// Code developed starting from Rustyoldman's Google Code jam template
// May 8, 2016
// I am coding from a campground in Colorado at 3AM for this contest.
// I didn't remember to load any of my library code onto this new laptop
// before starting this trip. I reconstructed this boilerplate by downloading
// a previous GCJ round's submission and editing out the solution.
//
// This should be interesting.
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
vector<int> primes ;
bool sl [50][50] ;
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
  int build ;
  long long m ;

  cin >> build >> m ;
  for ( int i = 0 ; i < build ; ++i )
    for ( int j = 0 ; j < build ; ++j )
      sl[i][j] = 0 ;

  int bits = 1 ;
  long long v = 1 ;

  while ( v < m )
    {
      ++bits ;
      v += v+1 ;
    }
//    cout << m << " bits = " << bits << endl ;

  bool power2 = (v/2+1 == m ) && ( bits + 1 <= build ) ;
//   cout << power2 << endl ;
  if ( m != 1 && bits + 2 > build && ! power2 )
    {
      cout << "Case #" << case_number << ": " ;
      cout <<  "IMPOSSIBLE" ;
      cout << endl ;
      return ;
    }

  for ( int b = 1 ; b < build-1 ; ++b )
    for ( int d = 0 ; d < b ; ++d )
      sl[b][d] = 1 ;

  long long bval = 1 ;
  int bpos = 1 ;

//   cout << "v = " << v << " m = " << m << endl ;

  if ( v/2+1 == m )
    {
      for ( int i = 0 ; i < bits ; ++i )
	sl[build-1][i] = 1 ;
    }
  else
    {
      for ( int i = 0 ; i < 51 ; ++i )
	{
	  if ( ! ( (bval & m ) == 0 ) )
	    sl[build-1][bpos] = 1 ;
	  bval += bval ;
	  bpos ++ ;
	}
    }






cout << "Case #" << case_number << ": " ;
 cout <<  "POSSIBLE" << endl ;
 for ( int i = build-1 ; i >= 0 ; --i )
   {
   for ( int j = build-1 ; j >= 0 ; --j )
     cout << sl[i][j] ;
   cout << endl ;
   }
}
// ****************************************************************************
int main ( int argc , char ** argv )
// ****************************************************************************
{
int n ;
cin >> n ; getchar() ;

//  primes.push_back(2) ;
//  for ( int i = 3 ; i < 1000000000 ; i+=2 )
//    {
//      if ( i % 10000000 == 3 ) 
//        cout << i << " " << primes.size() << endl ;
//      bool prime = 1 ;
//      for ( int j = 1 ; j < primes.size() && primes[j]*primes[j] <= i ; ++j )
//        if ( i%primes[j] == 0 )
// 	 {
// 	   prime = 0 ;
// 	   break ;
// 	 }
//      if ( prime )
//        primes.push_back ( i ) ;
//    }
//  ofstream pr ( "primes.txt" ) ;
//    pr << primes.size() << endl ;
//  for ( int i = 0 ; i < primes.size() ; ++i )
//    pr << primes[i] << endl ;
//  pr.close() ;

//  ifstream pr ( "primes.txt" ) ;
//  int np ; 
//  pr >> np ;
//  primes.resize(np) ;
//  for ( int i = 0 ; i < np ; ++i )
//    pr >> primes[i] ;
//  pr.close() ;

 //  cout << primes.size() << " primes precalculated" << endl ;
for ( int i = 1 ; i <= n ; i ++ )
   do_case ( i ) ;
}
// ****************************************************************************
