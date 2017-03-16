#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define forv(i, v) for(int i=0;i<v.size();++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 100 * 1000 + 13, INF = 1000*1000*1000;
const ld  eps = 1e-9;

bool solve(int test) {
	ld c, f, x;
	cin >> c >> f >> x;
	ld ans = 1e18;
	ld curTime = 0;
	ld curRate = 2.0;
	forn(i, N) {
		ans = min(ans, curTime + x / curRate);
		curTime += c / curRate;
		curRate += f;
	}
	printf("Case #%d: ", test + 1);
	printf("%.10lf\n", double(ans));
	return false;
}

int main () {	
#ifdef IKAR
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	forn(i, n)
		solve(i);
	return 0;
}