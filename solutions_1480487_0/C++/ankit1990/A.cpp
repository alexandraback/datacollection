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
int main(int argc, char *argv[])
{
   int cases = 0 ;
   int t ;
   si(t);
   while(t--){
      cases++ ;
      int n ;
      si(n);
      vector< double > x ;
      vector< pair< double, int > > y ;
      double total = 0 ;
      for( int i = 0 ; i < n ; i++ ){
	 x.push_back( 0.0 ) ;
	 scanf("%lf",&x[i]);
	 total += x[i] ;
	 y.push_back( make_pair( x[i], i ) ) ;
      }
      sort( y.begin() , y.end() ) ;
      printf("Case #%d: " , cases );
      for( int i = 0 ; i < n ; i++ ){
	 double hi = 1.0 ;
	 double lo = 0 ;
	
	 while( hi - lo  > 1e-9 ){
	    double mi = (lo + hi )/2.0 ;
	    double iscore = x[i] + mi*total ;
	    double ishare = 1.0 - mi;
	    for( int j = 0 ; j < y.size() ; j++ ){
	       if( y[j].second == i ) continue ;
	       //get jth score from the vector.
	       double jscore = x[ y[j].second ] ;
	       double jshare = (iscore - jscore)/total ;
	       if( jshare > 0 ) 
	       ishare = ishare - jshare ;
	    }

	    if( ishare >= 0.0 ){
	       lo = mi ;
	    }
	    else{
	       hi = mi ;
	    }
	 }
	 if( i == n - 1 )
	 printf("%.6f",hi*100.0 );
	 else
	 printf("%.6f ",hi*100.0 );
      }
      cout << endl ;
   }
   return 0 ;
}
