//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

string Name[8];
bool e[8][8];

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int t, cas = 1; cin >> t;
	while(t--) {
		cout << "Case #" << cas++ << ": ";
		memset(e, 0, sizeof e);
		int n, m; cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> Name[i];
		for(int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; --u, --v;
			e[u][v] = e[v][u] = 1;
		}
		vector <int> p(n), par(n);
		for(int i = 0; i < n; i++) p[i] = i;
		bool start = 0;
		string Zlatan = "";
		do {
			bool ok = 1;
			string Messi = Name[p[0]];
			par[p[0]] = -1;
			for(int i = 1; i < n; i++) {
				int curr = p[i - 1];
				bool foundParent = 0;
				while(curr != -1) {
					if(e[curr][p[i]]) {
						par[p[i]] = curr;
						foundParent = 1;
						break;
					}
					curr = par[curr];
				}
				if(!foundParent) {
					ok = 0;
					break;
				}
				Messi += Name[p[i]];
			}
			if(ok) {
				if(!start) {
					Zlatan = Messi;
				}
				else {
					Zlatan = min(Zlatan, Messi);
				}
				start = 1;
			}
		} while(next_permutation(p.begin(), p.end()));
		cout << Zlatan << '\n';
	}
	return 0;
}