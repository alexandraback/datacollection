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
#define x first
#define y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 1000, INF = 1000*1000*1000;
const ld  eps = 1e-9;

bool solve(int test) {
	printf("Case #%d: ", test + 1);
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	int ans = 0;
	for(int i = 0; i < a; i++)
		for(int j = 0; j < b; j++)
			if ((i & j) < k)
				ans++;
	printf("%d\n", ans);
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