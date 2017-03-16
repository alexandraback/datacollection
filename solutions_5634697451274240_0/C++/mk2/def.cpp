#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = 2e9;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;

vector<vector<int>> edges(1024);

int flip(int x, int num){
	int fpmask = (1 << num) - 1;
	int flp = (~(x & fpmask) ) & fpmask;
	return flp | (x & (~fpmask));
}

int dist[1024];

void bfs(){
	queue<int> trx;
	fill(dist + 1, dist + 1024, INF);
	trx.push(0);
	while(!trx.empty()){
		int cr = trx.front();
		trx.pop();
		for(auto to : edges[cr]){
			if(dist[to] == INF){
				dist[to] = dist[cr] + 1;
				trx.push(to);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	freopen("attempt0.in", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
	int cs;
	cin >> cs;
	for(int i = 0; i < (1024); i++){
		for(int fp = 1; fp <= 10; fp++){
			edges[i].push_back(flip(i, fp));
		}
	}
	bfs();
	for(int ccs = 1; ccs <= cs; ccs++){
		cout << "Case #" << ccs << ": ";
		string s;
		cin >> s;
		int k = 0;
		for(unsigned i = 0; i < s.size(); i++){
			k += int(s[i] == '-') << i;
		}
		cout << dist[k] << "\n";
	}
	return 0;
}
