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
#define ESP 1e-6

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

int s[ 5555 ] ;

void solve ( void ) {
     int N = SI ;
     FOR0(i,N){s[i] = SI ; }
     map<int, int> M ;
     int limit = 1 << N ;
     for ( int i = 1 ; i < limit ; i ++ ) {
         int sum = 0 ;
         for ( int j = 0 ; j < N ; j ++ ) {
             if ( (i>>j)&1 ) {
                  sum += s[j] ;
             }
         }
         if ( M[sum] == 0 ) {
              M[sum] = i ;
         } else {
                ENDL ;
                int m = M[sum] ;
                for ( int a = 0 ; a < N ; a ++ ) {
                    if ( (m>>a)&1 ) {
                         cout << s[a] << " " ;
                    }
                }
                ENDL ;
                for ( int a = 0 ; a < N ; a ++ ) {
                    if ( (i>>a)&1 ) {
                         cout << s[a] << " " ;
                    }
                }
                ENDL ;
                return ;
         }
     }
     cout << "Impossible" << endl ;
     return ;
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
















