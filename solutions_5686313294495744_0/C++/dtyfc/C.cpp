#include <bits/stdc++.h>
using namespace std;
map <string, int> D1, D2;
bool shown[1005];
vector <int> V[1005];
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.ou", "w", stdout);

	int T, n, cases = 0;
	cin >> T;
	while(T--) {
		cin >> n;
		int idx1 = 0, idx2 = 0;
		D1.clear();
		D2.clear();
		memset(shown , 0, sizeof(shown));
		for(int i = 0; i < 1005; i++) V[i].clear();
		for(int i = 0; i < n; i++) {
			string p, q;
			cin >> p >> q;
			//cout << p << "##" << q << endl;
			int u, v;
			if(D1[p] > 0) {
				u = D1[p]; 
			} else {
				D1[p] = ++idx1;
				u = D1[p];
			}
			if(D2[q] > 0) {
				v = D1[p]; 
			} else {
				D2[q] = ++idx2;
				v = D2[q];
			}
			V[u].push_back(v);
		}
		int ans = 0;
		for(int i = 1; i <= idx1; i++) {
			int cnt = 0;
			for(int j = 0; j < V[i].size(); j++) {
				if(!shown[V[i][j]]) {
					cnt++;
					shown[V[i][j]] = 1;
				}
			}
			ans += max(1, cnt);	
		}
		printf("Case #%d: %d\n", ++cases, n - ans);
	}
	return 0;
}
