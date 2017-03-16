#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

static const int MAXN = 55;

int main() {
	int t;
	ifstream f("input.txt");
	ofstream g("output.txt");
	f >> t;
	for(int x = 1; x <= t; x++) {
		int n, m;
		f >> n >> m;
		vector<string> zip(n);
		vector<int> ord(n);
		bool G[MAXN][MAXN];
		memset(G, 0, sizeof(G));
		for(int i = 0; i < n; i++) {
			f >> zip[i];
			ord[i] = i + 1;
		}
		int a, b;
		for(int i = 0; i < m; i++) {
			f >> a >> b;
			G[a][b] = G[b][a] = true;
		}
		string ans(n * 5, '9');
		do {
			bool ok = true;
			stack<int> dfs;
			dfs.push(ord[0]);
			int nxt = 1;
			while(!dfs.empty()) {
				int tp = dfs.top();
				if(nxt < n && G[tp][ord[nxt]]) {
					dfs.push(ord[nxt]);
					nxt++;
				}
				else {
					dfs.pop();
				}
			}
			if(nxt == n) {
				string s = "";
				for(int i = 0; i < n; i++) {
					s += zip[ord[i] - 1];
				}
				if(s < ans)	ans = s;
			}
		} while(next_permutation(ord.begin(), ord.end()));
		g << "Case #" << x << ": " << ans << endl;
	}
	f.close();
	g.close();
	return 0;
}
