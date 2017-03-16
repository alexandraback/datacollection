/*
 * Author: blackBird
 * Email: saketbharamberocks@gmail.com
 */
#include <cstdio>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <climits>

using namespace std ;

typedef long long ll ;
typedef pair<int,int> ii ;
typedef vector<int> VI ;
typedef vector<ii > VII ;
typedef vector<VI > VVI ;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FOR0(i,a) for(int i=0;i<(a);i++)
#define FOR1(i,a) for(int i=1;i<(a);i++)
#define REP(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define TRAVERSE(it,s) for(typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define ENDL putchar(10)
#define PB push_back
#define MP make_pair
#define SZ size

#define FILL(a,x) memset(a,x,sizeof a)
#define ALL(c) (c).begin(),(c).end()
#define PRESENT(c,x) (find(ALL(c),x) != (c).end())

#define INF 1e9
#define ESP 1e-10

#define MININ(a) *min_element(a.begin(), a.end())
#define MININ_A(a,n) *min_element(a, a+n)
#define MAXIN(a) *max_element(a.begin(), a.end())
#define MAXIN_A(a,n) *max_element(a, a+n)

#define P(x) cout << x
#define PE(x) cout << x << endl
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SLL ({long long _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lld",&_x); _x;})
#define SC getchar()
#define SS(n) scanf("%s",n)

int N;
double sum ;
int s[ 2222 ] ;

bool eliminates ( int ind, double sc, double y ) {
       double r = 1-y ;
       for ( int i = 0 ; i < N ; i ++ ) {
           if ( i != ind ) {
                y = max(0.0, (sc-s[i])/sum + ESP);
                r -= y ;
                if ( r < 0 ) { return false ; }
           }
       }
       if ( r == 0.0 ){ return false ; }
       return true ;
}

void solve ( void ) {
     N = SI ;
     sum = 0 ;
     for ( int i =0 ;i < N ; i ++ ) {
         s[i] = SI ;
         sum += s[i] ;
     }
     
     double l,h,m ;
     for ( int i = 0 ; i < N ; i ++ ) {
         double y = 1.0;
         for ( l=0.0,h=1.0,m=0.5 ; l < h-ESP ; m = (l+h)*0.5 ) {
//             cout << l <<  " " << m << " " << h << endl;
             if ( eliminates(i, s[i]+sum*m, m) ) {
                  l = m+ESP ;
             } else {
                  h = m-ESP ;
                  y = min(y,m);
             }
         }
         printf("%0.6lf ", 100.0*y);
     }
     ENDL;
}

int main () {
	int Kases = SI ;
	Kases ++ ;
	FOR1(kase, Kases) {
		printf("Case #%d: ", kase);
		solve();
	}
//	system("PAUSE");
	return 0 ;
}
















