#include<cassert>
#include<set>
#include<math.h>
#include<stack>
#include<limits.h>
#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#define REP(i,n) for(i=0;i<n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n) 
#define sd(n) scanf("%lf",&n)
#define pll(n) printf("%l64d",n) 
#define ss(str) scanf("%s",str)
#define sf(n) scanf("%lf",&n)
#define pb push_back
#define LL long long int 
#define pi pair<int,int> 
#define fi first
#define se second
#define FOR(i,a,b) for(i = a ; i < b ; i++ )
using namespace std ;
int P[ 1000 ] ;
vector< int > ans1 ;
vector< int > ans2 ;
vector< int > x ;
bool rec( int in ){
   if( in == 20 ){
      int s1 = 0 ;
      int s2  = 0;
      for( int i = 0 ; i < 20 ; i++ ){
	 if( P[i] == 0 ) s1 = s1 + x[i] ;
	 if( P[i] == 1 ) s2 = s2 + x[i] ;
      }
      if( s1 == s2 ){

	 for( int i = 0 ; i < 20 ; i++ ){
	    if( P[i] == 0 ) ans1.push_back( x[i] ) ;
	    if( P[i] == 1 ) ans2.push_back( x[i] ) ;
	 }
	 return true ;
      }
      return false ;
   }
   for( int j = 0 ; j < 3 ; j++ ){
     P[in] = j ;
     if( rec( in+1 ) ) return true ;
   }
   return false ;
}
int main(int argc, char *argv[])
{
   int cases = 0 ;
   int t ;
   si(t);
   while(t--){
      cases++ ;
      int n ;
      ans1.clear() ;
      ans2.clear() ;
      vector< int >X;
      si( n ) ;
      for( int i = 0 ; i < n ; i++ ){
	 X.push_back( 0 ) ;
	 si( X[i] ) ;
      }
      x = X ;
      printf("Case #%d: ", cases);
      if( rec( 0 ) ){
	cout << endl ;
	for( int i = 0 ;i < ans1.size() ; i++ ) cout << ans1[i] << " " ;
	cout << endl ;
	for( int i = 0 ;i < ans2.size() ; i++ ) cout << ans2[i] << " " ;
	cout << endl ;
      }
      else{
	cout <<"Impossible\n";
      }
   }
   return 0 ;
}
