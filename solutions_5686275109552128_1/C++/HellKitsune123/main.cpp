#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n, a[1000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        scanf("%d", &n);
        REP(i, n) scanf("%d", a + i);
        int ans = 1000;
        for (int cnt = 1; cnt <= 1000; ++cnt) {
            int cur = cnt;
            REP(i, n) cur += (a[i] - 1) / cnt;
            ans = min(ans, cur);
        }
        printf("Case #%d: %d\n", test, ans);
    }
	return 0;
}
