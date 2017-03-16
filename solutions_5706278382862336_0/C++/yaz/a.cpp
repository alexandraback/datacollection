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
		GETl(P);
		GETc(c);
		GETl(Q);
		ll ret=0;

		ll head = Q;
		while(!(head & 1)) head >>= 1;
		if((P/head)*head==P){
			P/=head;
			Q/=head;
			while((P>1) && (Q>1)){
				P>>=1;
				Q>>=1;
			}
			while(Q>>=1) ret++;
			if(1<=ret && ret<=40){
				printf("Case #%d: %lld\n", ttt, ret);
				continue;
			}
		}
		printf("Case #%d: impossible\n", ttt);
	}
	return 0;
}
