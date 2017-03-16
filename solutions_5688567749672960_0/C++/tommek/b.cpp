#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,v) for(decltype((v).begin())it=(v).begin();it!=(v).end();++it)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SIZE(x) ((int)(x).size())
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
const int MX = 1e6 + 5;
const int INF = 1e9 + 5;

LL dist[MX];
VI adj[MX];

int revNumb(int x) {
	int res = 0;
	while(x) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main(int argc, char* argv[])
{
	for(int i = 0; i < 1e6; ++ i)
	{
		adj[i].PB(i+1);
		adj[i].PB(revNumb(i));
	}

	REP(i,MX) dist[i] = INF;
	dist[0] = 0;

//	REP(i,100) {
//		printf("%d: ", i);
	///	FOREACH(it, adj[i])
	//		printf("%d ", *it);
	///	puts("");
	///}

	queue<int> Q;
	Q.push(0);

	while(!Q.empty()) {
		int u = Q.front(); Q.pop();

	//	printf("%d\n", u);

		FOREACH(it, adj[u])
			if(dist[*it] > dist[u] + 1) {
				dist[*it] = dist[u] + 1;
				Q.push(*it);
			}
	}

	int cases; scanf("%d", &cases); for(int ccc = 1; ccc <= cases; ++ ccc) {
		LL n; scanf("%lld", &n);
		printf("Case #%d: %lld\n", ccc, dist[n]);
	}
	return 0;
}
