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

int t;
int n;
char s[10000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int test = 1; test <= t; ++test) {
        scanf("%d%s", &n, s);
        int cnt = 0, ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (cnt < i) ++cnt, ++ans;
            cnt += s[i] - '0';
        }
        printf("Case #%d: %d\n", test, ans);
    }
	return 0;
}
