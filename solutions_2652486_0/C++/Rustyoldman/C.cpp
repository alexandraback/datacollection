// ****************************************************************************
// Code developed starting from Rustyoldman's Google Code jam template
// GCJ 2013 round 1A, problem C
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
int reps , cards , maxnum , samples ;
cin >> reps >> cards>> maxnum >> samples ;

int samp [10] ;
cout << "Case #" << case_number << ": " ;
cout << endl ;


for ( int r = 0 ; r < reps ; r ++ )
   {
   for ( int i = 0 ; i < samples ; i ++ )
      cin >> samp[i] ;

   sort ( samp , samp+samples ) ;
   
   int present [6] ;
   for ( int i = 0 ; i < 6 ; i ++ )
      present [i] = 0 ;
   for ( int i = 0 ; i < samples; ++i )
      {
      if ( samp[i]%3 == 0 )
         {
         present[3] = max(present[3],1);
         }
      if ( samp[i]%9 == 0 )
         {
         present[3] = max(present[3],2);
         }
      if ( samp[i]%27 == 0 )
         {
         present[3] = 3;
         }
      if ( samp[i]%2 == 0 )
         {
         present[2] = max(present[2],1 );
         }
      if ( samp[i]%4 == 0 )
         {
         present[2] = max(present[2],2 );
         }
      if ( samp[i]%8 == 0 )
         {
         present[2] = max(present[2],3 );
         }

      if ( samp[i]%16 == 0 )
         {
         present[4] = 1 ;
         }
      if ( samp[i]%32 == 0 )
         {
         present[4] = 2 ;
         }
      if ( samp[i]%64 == 0 )
         {
         present[4] = 3 ;
         }
      if ( samp[i]%5 == 0 )
         {
         present[5] = max(present[5],1) ;
         }
      if ( samp[i]%25 == 0 )
         {
         present[5] = max(present[5],2) ;
         }
      if ( samp[i]%125 == 0 )
         {
         present[5] = 3 ;
         }
      }
   
   for ( int i = 0 ; i < samples; ++i )
      {
      if ( samp[i]%4 == 0 && present[3]+present[5] > 1 )
         present[4] = 1 ;
      if ( samp[i]%16 == 0 && present[3]+present[5] > 0 )
         present[4] = 2 ;
      }

   // for ( int i = 0 ; i < samples ; i ++ )
   //    cout << samp[i] << " " ;
   // cout << " : " ;
   

   int c = 0 ;
   for ( int i = 5 ; i > 1 ; --i )
      {
      for ( int j = 0 ; j < present[i] ; ++j )
         {
         if ( c < 3 )
            cout << i ;
         c++ ;
         }
      }
   for ( int i = c ; i < 3 ; ++i )
      cout << 2 ;
   cout << endl ;
   }

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
