
#include <bits/stdc++.h>

using namespace std;

#define EACH(i,c) for(__typeof((c).begin()) i = (c).begin();i!=(c).end();i++)
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define dbg(e)  cout<<(#e)<<" : "<<e<<endl
#define set(v,i) memset(v,i,sizeof(v))
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
#define REP(i,n) FOR(i,0,n)
#define pb  push_back
#define mp make_pair

typedef long long ll;

int graph[55][55],N;

void correct(ll ways, int node) {
	//cout << "correct(" << ways << "," << node << ")" << endl;
	if(node <=  2) return;
	if(node >= 3 && 1ll << (node-3) > ways) {
		for(int j = N-node+2; j < N; j++)
			graph[N-node][j] = 0;
		correct(ways, node-1);
		return;
	}
	ll now = 1ll << (node-2);
	if(ways == now) return;
	graph[N-node][N-1] = 0;
	//dbg(ways);
	int i;
	for(i = 0; (1ll << i) <= ways; i++) {
		graph[N-node][N-2-i] = ((ways & (1ll << i)) > 0);
	}
	//for(; N-2-i >= 0; i++) graph[N-node][i] = 0; 
	/*
	if(ways == now) return;
	graph[N-node][N-1] = 0;
	now--;
	if(now == ways) return;
	ll pow2 = 1;
	int ind = N-2;
	while(true) {
		now -= pow2;
		graph[N-node][ind] = 0;
		ind--;
		pow2 <<= 1;
		if(ways == now) return;
		if(ways < now && ways > now - pow2) break;
	}
	correct(now-ways, node-1);*/
}

ll solve(int node) {
	if(node == N-1) return 1;
	ll cnt = 0;
	REP(i,N) if(graph[node][i]) cnt += solve(i);
	return cnt;
}

int main() {
	int tt;
	cin >> tt;
	REP(test,tt) {
		ll B, M;
		cin >> B >> M;
		N = B;
		cout << "Case #" << test + 1 << ": ";
		if(1ll << (B-2) < M) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		REP(i,B) REP(j,B) if(j > i) graph[i][j] = 1;
		correct(M,B);
		cout << "POSSIBLE" << endl;
		REP(i,B) {
			REP(j,B) cout << graph[i][j];
			cout << endl;
		}
		/*
		ll cntways = solve(0);
		if(M != cntways) {
			dbg(cntways);
			cout << "CCC : " << test + 1 << endl;
		}*/
		//assert(M == cntways);
	}
}

