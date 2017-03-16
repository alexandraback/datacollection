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

#define ABS(a) ((a)<0?-(a):(a))
#define SQ(x) (x)*(x)
#define INF 0x7ffffff00
#define ESP 1e-6

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)
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

double p[ 1111 ] ;

double keep_typing ( int a, int b ) { 
       int x = b-a+1 ;
       int y = x + b + 1 ;
       double pr = 1.0 ; 
       FOR0(i,a) { pr *= p[i] ; } 
       return (double)(pr*x + (1-pr)*y) ;
}

double backspace ( int n, int a, int b ) { 
       double pr = 1.0 ;
       FOR0(i,a-n) { 
                   pr *= p[i];
       }
       int x = 2*n + (b-a+1) ;
       int y = x + b + 1 ;
       return (double)(pr*x + (1-pr)*y) ;
}

void solve ( void ) {
     int A = SI ;
     int B = SI ;
     FOR0(i,A){ cin >> p[i] ; } 
     double ma = keep_typing(A,B) ;
     FOR0(i,A) {
               double mb = backspace(i, A, B);
               ma = min(ma, mb);
     }
     ma = min(ma, B+2.0);
     printf("%0.6lf\n",ma);
     return;
}

int main () {
	int Kases = SI ;
	Kases ++ ;
	FOR1(kase, Kases) {
		printf("Case #%d: ", kase);
		solve();
	}
	return 0 ;
}
