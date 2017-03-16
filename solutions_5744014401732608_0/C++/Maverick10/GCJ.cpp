#include<bits/stdc++.h>
#include<ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)  (ll)v.size()
#define UNVISITED -1
#define CLR(a,v) memset(a,v,sizeof a)
#define PC(x) __builtin_popcount(x)

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ii> vii;

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

const int MAX = 10;
bool adjMatrix[MAX][MAX];
int b, m;
int cnt;
void dfs(int x) {
	if (x == b) {
		++cnt;
		return;
	}
	if (cnt == m)
		return;
	for (int i = b; i > x && cnt < m; --i) {
		adjMatrix[x][i] = 1;
		dfs(i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		cnt = 0;
		CLR(adjMatrix, 0);
		scanf("%d%d", &b, &m);
		if (m > (1 << (b - 2)))
			printf("Case #%d: IMPOSSIBLE\n", c);
		else {
			printf("Case #%d: POSSIBLE\n", c);
			dfs(1);
			for (int i = 1; i <= b; ++i) {
				for (int j = 1; j <= b; ++j)
					cout << adjMatrix[i][j];
				cout << endl;
			}
		}
	}
}
