#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <bitset>
#include <fstream>
using namespace std;

	#define cin fin
	#define cout fout
	ifstream fin("A-small-attempt5.in");
	ofstream fout("A.out");

	int N;
	bool adj[1001][1001];
	bool visit[1001];
	vector<int> topo;

void dfs(int i) {
	if (visit[i]) return;
	visit[i] = true;
	for (int j=1; j<=N; ++j)
	    if (adj[i][j])
			dfs(j);
	topo.push_back(i);
}

	int L, R, U, D, A;
	int u[1001], d[1001];
	bitset<1001> anc[1001], canc;

int main() {
	int cn = 1;
	int cs; cin >> cs;
	while (cs--) {
		memset(adj, false, sizeof(adj));

		cin >> N;
		for (int a=1; a<=N; ++a) {
			int n; cin >> n;
			while (n--) {
				int b; cin >> b;
				adj[b][a] = true;
			}
		}

		memset(visit, false, sizeof(visit));
		topo.clear();
		for (int i=1; i<=N; ++i) dfs(i);

		bool ans = false;
		for (int i=1; i<=N; ++i) anc[i].reset();
		for (int i=1; i<=N; ++i) anc[i][i] = 1;
		for (int i=topo.size()-1; i>=0; --i)
			for (int j=1; j<=N; ++j)
			    if (adj[topo[i]][j]) {
					canc = anc[j] & anc[topo[i]];
					if (canc.any()) {ans = true; goto END;}
					anc[j] |= anc[topo[i]];
				}

END:
		cout << "Case #" << cn++ << ": ";
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	system("pause");
	return 0;
}
