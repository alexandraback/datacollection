#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) do { if(1) fprintf(stderr, __VA_ARGS__); } while(0)
#define DBGDO(X) do { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; } while(0)

int TC;
const int maxN = 100;
int N, E;

int zip[maxN];
struct Graph {
	vector<set<int>> adj;
	map<int,set<int>> levels;
	set<pii> possible;
	int lvl;
};

int main() {
	cin >> TC;
	FOR(tc,1,TC+1) {
		cout << "Case #" << tc << ": ";
		cin >> N >> E;

		FOR(i,0,N) cin >> zip[i];

		Graph G;
		G.adj.resize(N);
		G.lvl = 0;
		FOR(e,0,E) {
			int a, b; cin >> a >> b;
			a--; b--;
			G.adj[a].insert(b);
			G.adj[b].insert(a);
		}

		pii best (INT_MAX, -1);
		FOR(i,0,N) best = min(best, pii(zip[i], i));
		G.possible.insert(best);
		G.levels[best.second].insert(0);

		FOR(i,0,N) {
			bool found = false;

#if 0
			if (tc == 3) {
				DBG("---- tc %d, i %d ----\n", tc, i);
				for (const auto &po : G.possible) {
					DBG("\tpossible: %d -> %d\n", po.first, po.second);
				}
			}
#endif

			for (const auto &po : G.possible) {
				int z, node; tie(z, node) = po;

				for (int L : G.levels[node]) {
					Graph J = G;
					J.lvl = L;
					
					// delete obsolete entry points
					set<int> del;
					for (auto &ml : J.levels) {
						while (!ml.second.empty() && *ml.second.rbegin() > J.lvl) {
							ml.second.erase(prev(ml.second.rbegin().base()));
						}
						if (ml.second.empty()) del.insert(ml.first);
					}
					for (int d : del) {
						J.levels.erase(d);
						J.possible.erase(pii(zip[d], d));
					}

					// insert new entry points
					for (int to : J.adj[node]) {
						J.possible.insert(pii(zip[to], to));
						J.levels[to].insert(J.lvl + 1);
					}

					// remove chosen node
					for (int to : J.adj[node])
						J.adj[to].erase(node);
					J.adj[node].clear();
					J.levels.erase(node);
					J.possible.erase(pii(zip[node], node));

					vector<bool> mark (N, false);

					function<int(int)> dfs = [&](int n) -> int {
						if (mark[n]) return 0;
						int res = 1;
						mark[n] = true;
						for (int to : J.adj[n])
							if (!mark[to])
								res += dfs(to);
						return res;
					};

					int check = 0;
					for (const auto &po : J.possible) {
						check += dfs(po.second);
					}

#if 0
					if (tc == 3 && node != 13) {
						DBG("---- tc %d, node %d, i %d, check %d ----\n", tc, node, i, check);
						DBG("\tpossible:");
						for (const auto &po : J.possible)
							DBG(" %d", po.second);
						DBG("\n");
						FOR(i,0,N) {
							DBG("\tadj[%d]:", i);
							for (int to : J.adj[i]) DBG(" %d", to);
							DBG("\n");
						}
					}
#endif

					if (check == N - i - 1) {
						G = J;
						cout << z;
						found = true;
						break;
					}
				}
				if (found) break;
			}
			assert(found);
		}

		cout << endl;
	}
}
