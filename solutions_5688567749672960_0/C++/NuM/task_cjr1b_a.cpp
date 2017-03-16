#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int maxn = 1000010;


int rev(int x) {
	int res = 0;
	while (x) res = res * 10 + x % 10, x /= 10;
	return res;
}

int dp[maxn];

void solve(int n) {
	printf("%d\n", dp[n]);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	forn(i, maxn) dp[i] = i;
	for(int i = 1; i < maxn; ++i) {
		int r = rev(i);
		if (r > i && r < maxn) dp[r] = min(dp[r], dp[i] + 1);
		if (i + 1 < maxn) dp[i + 1] = min(dp[i + 1], dp[i] + 1);
	}
	int T; scanf("%d", &T);
	for (int tn = 1; tn <= T; ++tn) {
		int x; scanf("%d", &x);
		printf("Case #%d: ", tn);
		solve(x);
	}
	return 0;
}