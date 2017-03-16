#include <bits/stdc++.h>
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

int dprintf(const char *err, ...) { 
	if (debug) {
		va_list pvar;
		va_start(pvar, err);
		return vfprintf(stderr, err, pvar);
	}
	return 0;
}


int match[4000];
int seen[4000];

bool aug(vi *G, int u) {
	seen[u] = true;
	for (auto v: G[u]) {
		if (match[v] < 0 ||
			(!seen[match[v]] && aug(G, match[v]))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int lookup(msi &D, char *s) {
	int &r = D[s];
	if (!r) r = D.size();
	return r-1;
}

void solve(int P) {
	int N;
	map<string, int> L, R;
	vi adj[4000];
	
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char s1[2000], s2[2000];
		scanf("%s%s", s1, s2);
		int a = lookup(L, s1), b = lookup(R, s2);
		adj[a].push_back(N+b);
		adj[N+b].push_back(a);
		//		printf("%d %d\n", a, N+b);
	}
	int ans = N-L.size()-R.size();
	memset(match, -1, sizeof(match));
	for (int i = 0; i < L.size(); ++i) {
		memset(seen, 0, sizeof(seen));
		ans += aug(adj, i);
	}
	printf("Case #%d: %d\n", P, ans);
}

int main(void) {
	init();
	for (int i = 1; i <= CASES; ++i) {
		solve(i);
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
