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

	int perm[10];
	vi ans;
	for (int i = 0; i < N; ++i) perm[i] = i+1;
	do {
		vi stack;
		vi seq;
		stack.push_back(perm[0]);
		seq.push_back(val[perm[0]]);
		for (int i = 1; i < N; ++i) {
			while (!stack.empty() && !adj[stack.back()][perm[i]]) stack.pop_back();
			if (stack.empty()) break;
			stack.push_back(perm[i]);
			seq.push_back(val[perm[i]]);
		}
		if (seq.size() == N) {
			if (ans.empty() || seq < ans) ans = seq;
		}
	} while (next_permutation(perm, perm+N));
	
	print("Case #%d: ", P);
	for (int i: ans) print("%d", i);
	print("\n");
}

int main(void) {
  init();
  for (int i = 1; i <= CASES; ++i) solve(i);
  return 0;
}
