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

int C[100][100];
int F[100][100];
bool ret[100][100];

double able(int H, int N, int M, int n1, int m1, int n2, int m2, double t){
	if(n1 < 0 || m1 < 0 || n1 >= N | m1 >= M) return -1;
	if(n2 < 0 || m2 < 0 || n2 >= N | m2 >= M) return -1;
	if(C[n2][m2] - F[n1][m1] < 50) return -1;
	if(C[n2][m2] - F[n2][m2] < 50) return -1;
	if(C[n1][m1] - F[n2][m2] < 50) return -1;
	if(C[n2][m2] - H + 10*t >= 50-EPS) return 0;
	return (H - C[n2][m2]) / 10.0 - t + 5;
}

#define qT(q)	(-(q).first)
#define qN(q)	((q).second.first)
#define qM(q)	((q).second.second)
int N_DELTA[] = {-1,+1,0,0};
int M_DELTA[] = {0,0,-1,+1};

int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETi(H);
		GETi(N);
		GETi(M);
		REP(i,N){
			REP(j,M){
				GETi(c);
				C[i][j] = c;
				ret[i][j] = false;
			}
		}
		REP(i,N){
			REP(j,M){
				GETi(f);
				F[i][j] = f;
			}
		}
		printf("Case #%d:", ttt);
		priority_queue<pair<double,pair<int,int> > > que;
		que.push(make_pair(0.0,make_pair(0,0)));
		while(!que.empty()){
			LET(q,que.top());
			que.pop();
			if(qN(q) == N-1 && qM(q) == M-1){
				printf(" %.6f\n", qT(q));
				break;
			}
			if(ret[qN(q)][qM(q)]) continue; else ret[qN(q)][qM(q)]=true;
			REP(i,4){
				double a = able(H,N,M,qN(q),qM(q),qN(q)+N_DELTA[i],qM(q)+M_DELTA[i],qT(q));
				if(a<0) continue;
				double t = qT(q) + a;
				if(abs(t) > EPS){
					t += (H-10*t - F[qN(q)][qM(q)] >= 20) ? 1 : 10;
				}
				que.push(make_pair(-t,make_pair(qN(q)+N_DELTA[i],qM(q)+M_DELTA[i])));
			}
		}
	}
	return 0;
}
