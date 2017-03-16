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

#define SCAN(p,f)	scanf("%" #f " ",p)
#define GET(t,x,f)	t x;SCAN(&x,f)
#define GETi(x)		GET(int,x,d)
#define GETl(x)		GET(ll,x,lld)
#define GETc(x)		GET(char,x,c)
#define GETf(x)		GET(float,x,f)
#define GETd(x)		GET(double,x,lf)

int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETl(A);
		GETl(B);
		GETl(K);
		ll ret=0;
		REP(a,A){
			REP(b,B){
				if((a&b)<K) ret++;
			}
		}
		printf("Case #%d: %lld\n", ttt, ret);
	}
	return 0;
}
