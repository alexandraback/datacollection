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

int one [2000] ;
int two [2000] ;
int score [2000] ;
long long byone [1000] ;
long long bytwo [1000] ;
// ****************************************************************************
void do_case ( int case_number )
// ****************************************************************************
{
int n ;
cin >> n ;
for ( int i = 0 ; i < n ; i ++ )
   cin >> one[i] >> two[i] ;

for ( int i = 0 ; i < n ; i ++ )
   byone[i] = one[i]*9000000 + (2002-two[i])*3000 + i ;
for ( int i = 0 ; i < n ; i ++ )
   {
   bytwo[i] = two[i]*9000000 + (2002-one[i])*3000 + i ;
   }
for ( int i = 0 ; i < n ; i ++ )
   score[i] = 0 ;

sort(byone,byone+n) ;
sort(bytwo,bytwo+n) ;


int have = 0 ;
int op = n-1 ;
int tp = 0 ;
int moves = 0 ;

while ( tp < n )
   {
   // cout << "move " << moves << " have " << have << endl ;
   
   // cout << "     " <<   ( bytwo[tp]/9000000 ) << endl ;
   
   if ( bytwo[tp]/9000000 <= have )
      {
      int index = (int) bytwo[tp]%3000 ;
      // if ( score[index] < 2 )
      //    cout << "          using2 [" << index << "] cost " << bytwo[tp]/9000000 << " score = " << 2-score[index] << endl ;
      if ( score[index] == 0 )
         {
         have += 2 ;
         ++ moves ;
         }
      else if ( score[index] == 1 )
         {
         have += 1 ;
         ++ moves ;
         }
      score[index] = 2 ;
      ++ tp ;
      }
   else 
      {
      op = n-1 ;
      bool found = 0 ;
      while ( op >= 0 ) 
         {
         //            cout << "1s " <<  2002-bytwo[op]/3000%3000 << endl ;
         if ( 2002-bytwo[op]/3000%3000 <= have )
            {
            
            int index = (int) bytwo[op]%3000 ;
            if ( score[index] == 0 )
               {
               have += 1 ;
               //      cout << "          using1 [" << index << "] cost " << 2002-bytwo[op]/3000%3000 << " score = " << 1-score[index] << endl ;
               score [index] = 1 ;
               ++ moves ;
               found = 1 ;
               break ;
               }
            }
            -- op ;
         }
      if ( ! found )
         {
         moves = -1 ;
         break ;
         }
      }
   }



if ( moves > -1 && have == n+n )
   cout << "Case #" << case_number << ": " << moves ;
else
   cout << "Case #" << case_number << ": " << "Too Bad" ;
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
