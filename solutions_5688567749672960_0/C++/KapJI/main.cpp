#include <cassert>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;
typedef pair<int, int> st;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e6 + 100;

int dp[MAXN + 100];

int get_rev(int n) {
	stringstream ss;
	ss << n;
	string s = ss.str();
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

void precalc() {
	for (int i = 1; i < MAXN; ++i) {
		dp[i] = INF;
	}
	dp[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (dp[cur + 1] == INF) {
			dp[cur + 1] = dp[cur] + 1;
			q.push(cur + 1);
		}
		int rev = get_rev(cur);
		if (rev < MAXN && dp[rev] == INF) {
			dp[rev] = dp[cur] + 1;
			q.push(rev);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    precalc();
    FOR(i, t) {
    	int n;
    	scanf("%d", &n);
        printf("Case #%d: %d\n", i + 1, dp[n]);
    }
	return 0;
}

