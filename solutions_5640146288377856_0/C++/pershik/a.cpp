#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>

#define NAME "test-small"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define ve vector<int>
#define pb push_back

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define fs first
#define sc second

using namespace std;

typedef long long li;
typedef long long ll;
typedef long long lint;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#else
#endif
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i + 1);
    }
    return 0;
}

const int MAXN = 25;

int n, m, l;
int dp[MAXN][MAXN][MAXN];

int solve(int lt, int rt, int l) {
    cerr << lt << ' '<< rt << ' ' << l << endl;
    if (l == 0)
        return 0;
    if (rt + lt == l)
        return 0;
    if (dp[lt][rt][l] != -1)
        return dp[lt][rt][l];
    int res = INF;

    for (int i = 1; i <= lt; i++) {
        if (i > l)
            break;
        int r1 = solve(lt - i, max(rt - i, 0), l - i);
        int r2 = 1 + solve(i - 1, rt, l);
        res = min(res, max(r1, r2));
    }
    for (int i = 1; i <= rt; i++) {
        if (i > l)
            break;
        int r1 = solve(max(lt - i, 0), rt - i, l - i);
        int r2 = 1 + solve(lt, i - 1, l);
        res = min(res, max(r1, r2));
    }

    return dp[lt][rt][l] = res;
}

void solve(int test_number) {
    memset(dp, 255, sizeof(dp));
    cin >> n >> m >> l;
    int res = 0;

    int rem = m;
    if (rem > l) {
        while (rem >= l) {
            res += (n - 1);
            rem -= l;
        }
    } else {
        res = n - 1;
    }

    //cout << res << endl;

    rem = m;
    if (rem > l) {
        int pts = m / l;
        int r1 = solve(l - 1, m % l, l - 1) + pts - 1;
        int r2 = -INF;
        if (pts > 1)
            r2 = solve(l - 1, l - 1, l - 1) + pts - 2;
        //cout << r1 << ' ' << r2 << endl;
        res += max(r1, r2);
    } 

    cout << "Case #" << test_number << ": " << res + l << endl;
}

