#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
const int N = 2222;
int g[N][N];
int v[N], m[N], m1[N];
int dfs(int a) {
    if (a < 0) return 1;
    if (v[a]) return 0;
    v[a] = 1;
    int i;
    for (i = 0; i < N; ++i) if (g[a][i]) {
	    if (dfs(m1[i])) {
		m[a] = i; m1[i] = a;
		return 1;
	    }
	}
    return 0;
}
int dfsexp(int a) {
    for (int i = 0; i < N; ++i) v[i]= 0;
    return dfs(a);
}
int bm() {
    int res = 0;
    for (int i = 0; i < N; ++i) {
	m[i] = m1[i] = -1;
    }
    for (int i = 0; i < N; ++i) if (m[i] < 0) res += dfsexp(i);
    return res;
}
int T;
map<string, int> mpa, mpb;
string sa, sb;
int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
	memset(g, 0, sizeof(g));
	mpa.clear(); mpb.clear();
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	    cin >> sa >> sb;
	    if (mpa.find(sa) == mpa.end()) mpa[sa] = cnt++;
	    if (mpb.find(sb) == mpb.end()) mpb[sb] = cnt++;
	    g[mpa[sa]][mpb[sb]] = g[mpb[sb]][mpa[sa]] = 1;
	}
	int x = bm() / 2;
	printf("Case #%d: %d\n", t, n - cnt + x);
    }
    return 0;
}
