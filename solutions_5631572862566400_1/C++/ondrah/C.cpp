#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#ifndef ONLINE_JUDGE
	#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#else
	#define DEBUG(x) do {} while(0);
#endif

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, A, N) for(int (i) = (A); (i) < (N); (i)++)
#define REP(i, N) for(int (i) = 0; (i) < (N); (i)++)

using namespace std;
typedef long long ll;
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

int n,m;
int T;
int F[1111];
vector<int> rev[1111];
int dfs(int u, int prev = -1, int len = 0) {
	int ans = len;
	for(auto x : rev[u]) {
		if(x == prev)
			continue;
		ans = max(ans, dfs(x, u, len+1));
	}
	return ans;
}

void solve() {
	scanf("%d", &n);
	REP(i, 1111) rev[i].clear();
	REP(i, n) {
		scanf("%d", F+i);
		F[i]--;
		rev[F[i]].push_back(i);
	}
	int ans = 0;
	for(int start = 0; start < n; start++) {
		map<int, int> visited;
		visited[start] = 0;
		int curr = start;
		int t = 1;
		do {
			//printf("%d ", curr+1);
			visited[curr] = t;
			t++;
			curr = F[curr];
		} while(visited.find(curr) == visited.end());
		ans = max(ans, t-visited[curr]);
	//	printf("for start=%d end is at %d, t=%d, cans=%d\n", start, curr, t, t-visited[curr]);
	}
	int cans = 0;
	REP(i, n) {
		int j = F[i];
		if(F[j] == i) {
			cans += dfs(i, j) + dfs(j, i) + 2;
		}
	}
	ans = max(ans, cans/2);
	printf("%d", ans);

}

int main() {
	scanf("%d", &T);
	REP(testc, T) {
		printf("Case #%d: ", testc+1);
		solve();
		printf("\n");
	}
	return 0;
}
