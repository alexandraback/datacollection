#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(v) (int)v.size()
#define all(c) (c).begin(), (c).end()

typedef long long int ll;

// %I64d for ll in CF

#define NMAX 10

int n, m;
int code[NMAX];
bool adjMat[NMAX][NMAX];
bool purchased[NMAX][NMAX];

void print(vector<int> &cities) {
	for (int i = 0; i < n; i++) {
		printf("%d", code[cities[i]]);
	}
}

bool solve(int i, vector<int> &cities, int next) {
	if (next == n) {
		return true;
	}

	//printf("visiting %d\n", i);

	if (adjMat[i][cities[next]]) {
		purchased[cities[next]][i] = true;
		//printf("purchase to %d\n", cities[next]);
		return solve(cities[next], cities, next + 1);
	}

	bool res = false;
	for (int j = 1; j <= n; j++) {
		if (purchased[i][j]) {
			purchased[i][j] = false;
			//printf("return to %d\n", j);
			res |= solve(j, cities, next);
			purchased[i][j] = true;
		}
	}

	return res;
}

bool check(vector<int> &cities) {
	memset(purchased, false, sizeof purchased);
	return solve(1, cities, 1);
}

int main() {
	int t;
	scanf("%d", &t);
	int test = 1;
	while (t--) {
		scanf("%d %d", &n, &m);

		vector<pair<int, int> > v;
		int code0[n + 1];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &code0[i]);
			v.push_back(make_pair(code0[i], i));
		}

		sort(all(v));
		int root = v[0].second;

		int newpos[n + 1];
		for (int i = 1; i <= n; i++) {
			newpos[v[i - 1].second] = i;
			code[i] = code0[v[i - 1].second];
		}

		memset(adjMat, false, sizeof adjMat);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);

			int u1 = newpos[u];
			int v1 = newpos[v];
			adjMat[u1][v1] = adjMat[v1][u1] = 1;
		}

		vector<int> cities;
		printf("Case #%d: ", test);
		for (int i = 1; i <= n; i++) cities.push_back(i);
		do {
			if (check(cities)) {
				print(cities);
				break;
			}
		}
		while (next_permutation(all(cities)));

		printf("\n");
		test++;
	}
	return 0;
}
