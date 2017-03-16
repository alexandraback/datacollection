#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define forab(i, a, b) for (int i = a; i < int(b); ++i)
#define fordab(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab (i, 0, n)
#define ford(i, n) fordab (i, 0, n)
#define forv(i, a) forn (i, a.size())
#define pb push_back

vector<int> g[1100];
bool used[1100];

void dfs(int v) {
	used[v] = true;
	forv (i, g[v]) {
		if (!used[g[v][i]]) {
			dfs(g[v][i]);
		}
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	forn (q, t) {
		int n;
		cin >> n;
		forn (i, n) {
			g[i].clear();
		}
		forn (i, n) {
			int k;
			cin >> k;
			forn (j, k) {
				int x;
				cin >> x;
				g[i].pb(x - 1);
			}
		}
		bool was = false;
		forn (i, n) {
			forn (j, n) {
				if (i == j) {
					continue;
				}
				forn (k, n) {
					used[k] = false;
				}
				used[i] = true;
				int num = -1;
				forv (k, g[i]) {
					dfs(g[i][k]);
					if (used[j]) {
						num = k;
						break;
					}
				}
				if (num == -1) {
					continue;
				}
				forn (k, n) {
					used[k] = false;
				}
				used[i] = true;
				forv (k, g[i]) {
					if (k == num) {
						continue;
					}
					dfs(g[i][k]);
					if (used[j]) {
						was = true;
						break;
					}
				}
				if (was) {
					break;
				}
			}
			if (was) {
				break;
			}
		}
		cout << "Case #" << q + 1 << ": ";
		cout << (was ? "Yes" : "No");
		cout << endl;
	}
}
