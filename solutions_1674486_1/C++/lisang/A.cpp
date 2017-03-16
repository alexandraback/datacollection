#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i,x,y) for(LL i=x; i<=y; i++)
#define REP(i,n) for(LL i=0; i<n; i++)

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define SZ(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-10;
const double pi = acos(-1.0);
double sum = 0;

bool res = false;

void Dfs(vector<vector<int> >& g, vector<bool>& u, int v) {
	u[v] = true;
	REP(i, SZ(g[v])) {
		int to = g[v][i];
		if (u[to]) {
			res = true;
		} else {
			Dfs(g, u, to);
		}
	}
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("outputA.txt", "w", stdout);
	int TESTS;
	scanf("%d\n", &TESTS);

	REP(test, TESTS) {
		printf("Case #%lld: ", test + 1);		
		res = false;
		int n;
		cin >> n;
		vector<vector<int> > g(n);
		REP(i, n) {
			int c;
			cin >> c;
			REP(j, c) {
				int tmp;
				cin >> tmp;
				--tmp;
				g[i].push_back(tmp);
			}
		}
		vector<bool> u(n, false);
		REP(i, n) {
			vector<bool> p(n, false);
			if (!u[i]) {
				Dfs(g, p, i);
			}
			REP(j, n) {
				if (p[j]) {
					u[j] = p[j];
				}
			}
		}
		if (res) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}