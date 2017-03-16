#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <deque>
using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------

#define MAXN 150

int C, D, V;
int c[MAXN];

void solve() {

	sort(c, c + D);
	c[D] = V + 1;

	int ans = 0;
	int index = 0;
	int panelty = 0;

	while (panelty < V) {

		for( ;c[index] > panelty + 1; ans++) {
			panelty += panelty + 1;
		}

		panelty += c[index];
		index++;

	}


	printf("%d\n", ans);
	fflush(stdout);
}

int main() {
	int cases;
	int caseid = 1;

	freopen("input", "r", stdin);
//freopen("output", "w", stdout);
	scanf("%d", &cases);
	while (cases--) {
		printf("Case #%d: ", caseid++);
		scanf("%d%d%d", &C, &D, &V);
		for (int i = 0; i < D; i++)
			scanf("%d", &c[i]);

		solve();
		//printf("%llu\n", DP(N));
	}
	return 0;
}

