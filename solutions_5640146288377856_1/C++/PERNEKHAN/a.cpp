#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <windows.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

void Solve(){
	int R, C, W;
	scanf("%d%d%d", &R, &C, &W);
	int ans = (R-1)*(C/W);
	ans += C/W + (W-1) + (C%W != 0);
	printf("%d\n", ans);
}

int main () {
	#ifdef LOCAL
	freopen(file".in", "r", stdin);
	freopen(file".out", "w", stdout);
	#endif

	int T;
	scanf("%d", &T);

	for (int i=0;i<T;i++){
	    printf("Case #%d: ", i + 1);
		Solve();
	}




	#ifdef LOCAL
	cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	return 0;
}

