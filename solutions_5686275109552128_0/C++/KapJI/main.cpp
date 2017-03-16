#include <cassert>
#include <iostream>
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
const int MAXN = 1500;


int solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int ans = 0;
    FOR(i, n) {
        scanf("%d", &a[i]);
        ans = max(ans, a[i]);
    }
    //sort(a.rbegin(), a.rend());
    for (int t = 1; t < ans; ++t) {
        for (int special = 0; special < t; ++special) {
            int rt = t - special;
            int left = special;
            FOR(i, n) {
                int parts = (a[i] + rt - 1) / rt;
                // fprintf(stderr, "parts %d, rt %d, a[i] %d\n", parts, rt, a[i]);
                left -= parts - 1;
            }
            if (left >= 0) {
                return t;
            }
        }
    }
    return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    FOR(i, t) {
        printf("Case #%d: %d\n", i + 1, solve());
    }
	return 0;
}

