#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <memory>
#include <complex>
using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

#define FOR(i,a,b)	for(int i=(a);i<(int)(b);++i)
#define FORe(i,a,b)	for(int i=(a);i<=(int)(b);++i)
#define REP(i,b)	FOR(i,0,b)
#define REP1(i,b)	FORe(i,1,b)
#define ALL(c)		(c).begin(),(c).end()
#define LET(v,x)	typeof(x) v = x
#define FROMTO(it,b,e)	for(LET(it,(b));it!=(e);++it)
#define FOREACH(it,c)	FROMTO(it,(c).begin(),(c).end())

ll gcd(ll a, ll b){
	if (a && b) for(ll x; b; b = x){
		x = a % b;
		a = b;
	}
	return a;
}
ll gcd(ll a[], int n){
	return n > 0 ? accumulate(a + 1, a + n, a[0], (ll(*)(ll,ll))gcd) : 0LL;
}

ll lcm(ll a, ll b){
	return (a && b) ? a / gcd(a, b) * b : 0LL;
}
ll lcm(ll a[], int n){
	return n > 0 ? accumulate(a + 1, a + n, a[0], (ll(*)(ll,ll))lcm) : 0LL;
}

#define SCAN(p,f)	scanf("%" #f " ",p)
#define GET(t,x,f)	t x;SCAN(&x,f)
#define GETi(x)		GET(int,x,d)
#define GETl(x)		GET(ll,x,lld)
#define GETc(x)		GET(char,x,c)
#define GETf(x)		GET(float,x,f)
#define GETd(x)		GET(double,x,lf)

char grid[20][20];
void fill(int N, int M, int n, int m){
	if(!(0<=n&&n<N)) return;
	if(!(0<=m&&m<M)) return;
	if(grid[n][m] != 0) return;
	grid[n][m] = -1;
	fill(N, M, n-1, m);
	fill(N, M, n+1, m);
	fill(N, M, n, m-1);
	fill(N, M, n, m+1);
}

int countup(int N, int M){
	REP(n,N){
		fill(N, M, n, 0);
		fill(N, M, n, M-1);
	}
	REP(m,M){
		fill(N, M, 0, m);
		fill(N, M, N-1, m);
	}
	int ret=0;
	REP(n,N){
		REP(m,M){
			if(grid[n][m] != -1) ret++;
		}
	}
	return ret;
}
int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETi(N);
		GETi(M);
		GETi(K);
		int ret=(N-1+M-1)*2;
		int p=1<<(N*M);
		
		REP(i,p){
			int stone=0;
			REP(n,N){
				REP(m,M){
					grid[n][m] = (i & (1<<(n+m*N))) ? 1 : 0;
					stone     += (i & (1<<(n+m*N))) ? 1 : 0;
				}
			}
			int area = countup(N, M);
			if(area>=K && ret>stone){
				ret=stone;
			}
		}
		
		
		
		printf("Case #%d: %d\n", ttt, ret);
	}
	return 0;
}
