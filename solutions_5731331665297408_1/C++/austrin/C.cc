#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

bool debug = false;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef map<string, int> msi;
typedef set<string> ss;
typedef set<pii> spii;

const double pi = 2.0*acos(0.0);

int CASES;

void init() {
  assert(scanf("%d", &CASES) == 1);
}

int print(const char *err, ...) {
  va_list pvar;
  va_start(pvar, err);
  vfprintf(stderr, err, pvar);
  return vfprintf(stdout, err, pvar);
}

int dprint(const char *err, ...) { 
  if (debug) {
    va_list pvar;
    va_start(pvar, err);
    return vfprintf(stderr, err, pvar);
  }
  return 0;
}


bool adj[100][100];
int val[100];

bool done[100];
bool vis[100];
int N, M;

void dfs(int u) {
	vis[u] = true;
	for (int v = 1; v <= N; ++v)
		if (adj[u][v] && !done[v] && !vis[v]) {
			dfs(v);
		}
}

bool connected() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= N; ++i) 
		if (!done[i]) { 
			dfs(i); 
			break; 
		}
	int seen = 0;
	for (int i = 1; i <= N; ++i) seen += done[i] || vis[i];
	return seen == N;
}

void solve(int P) {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d", val+i+1);
	memset(adj, 0, sizeof(adj));
	memset(done, 0, sizeof(done));
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a][b] = adj[b][a] = true;
	}

	int minv = 1;
	for (int i = 1; i <= N; ++i) if (val[i] < val[minv]) minv = i;

	vi seq;
	vi stack;
	stack.push_back(minv);
	seq.push_back(minv);
	int seen[100];
	int cov[100];
	set<pii> avail;
	memset(cov, 0, sizeof(cov));
	for (int u = 1; u <= N; ++u) {
		seen[u] = false;
		if (adj[minv][u]) {
			avail.insert(pii(val[u], u));
			++cov[u];
		}
	}
	seen[minv] = true;
	dprint("start from %d\n", minv);
	while (!avail.empty()) {
		dprint("new loop, %d avail:\n", avail.size());
		for (auto a: avail) 
			dprint(" %d,%d\n", a.first, a.second);
		for (auto a: avail) {
			dprint("   try avail %d (zip %d)\n", a.second, a.first);
			for (int i = 1; i <= stack.size(); ++i) {
				if (adj[stack[stack.size()-i]][a.second]) break;
				dprint("   would lead us to return from %d\n", stack[stack.size()-i]);
				done[stack[stack.size()-i]] = true;
			}
			if (connected()) {
				dprint("       -> taken!\n");
				while (done[stack.back()]) {
					int v = stack.back(); stack.pop_back();
					for (int u = 1; u <= N; ++u) {
						if (!seen[u] && adj[u][v] && --cov[u] == 0)
							avail.erase(pii(val[u], u));
					}
				}
				for (int u = 1; u <= N; ++u)
					if (!seen[u] && adj[a.second][u]) {
						avail.insert(pii(val[u], u));
						++cov[u];
					}
				seq.push_back(a.second);
				seen[a.second] = true;
				stack.push_back(a.second);
				avail.erase(a);
				break;
			}
			for (int i = 1; i <= stack.size(); ++i) {
				if (adj[stack[stack.size()-i]][a.second]) break;
				done[stack[stack.size()-i]] = false;
			}
		}
	}
	
	print("Case #%d: ", P);
	for (int i: seq) print("%d", val[i]);
	print("\n");
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
