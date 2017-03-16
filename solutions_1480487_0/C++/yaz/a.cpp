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

static const double EPS = 1e-10;
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

int sss[200];
bool check(int N, int X, int pos, double v){
	double my = sss[pos] + X * v;
	REP(i,N){
		if(i==pos)continue;
		if(sss[i] < my){
			v += (my - sss[i]) / X;
			if(v >= 1-EPS){
				return true;
			}
		}
	}
	return false;
}

double detect(int N, int X, int pos, double left, double right){
	double mid = (left + right) / 2;
	if(abs(left - right) < EPS) return mid;
	if(check(N, X, pos, mid)){
		right = mid;
	}else{
		left = mid;
	}
	return detect(N, X, pos, left, right);
}

int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETi(N);
		int X = 0;
		REP(i,N){
			GETi(S);
			sss[i]=S;
			X+=S;
		}
		printf("Case #%d:", ttt);
		REP(i,N){
			printf(" %.6f", 100 * detect(N, X, i, 0, 1));
		}
		printf("\n");
	}
	return 0;
}
