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

int ms[100];
int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETi(A);
		GETi(N);
		REP(i,N){
			GETi(x);
			ms[i] = x;
		}
		sort(ms,ms+N);
		int f=0,a=A;
		REP(i,N){
			if(a>ms[i]){
				a+=ms[i];
				f=i+1;
			}else{
				break;
			}
		}
		int ret=0;
		if(f==N){
		}else if(a<=1){
			ret=N-f;
		}else if(N-f==1){
			ret=1;
		}else{
			int offset=0;
			ret=offset+N-f;
			while(1){
				int fin=0;
				while(a<=ms[f]){
					a+=a-1;
					offset++;
					if(offset>ret){
						fin=1;
						break;
					}
				}
				if(fin) break;
				FOR(i,f,N){
					if(a>ms[i]){
						a+=ms[i];
						f=i+1;
					}else{
						break;
					}
				}
				if(ret>offset+N-f)ret=offset+N-f;
				if(N-f<=1){
					break;
				}
			}
		}
		printf("Case #%d: %d\n", ttt, ret);
	}
	return 0;
}
