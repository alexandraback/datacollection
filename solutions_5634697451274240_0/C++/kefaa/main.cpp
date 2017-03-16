#include <functional>
#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <numeric>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <cassert>
#include <bitset>
#include <vector>
#include <math.h>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T>
T nextInt() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if (ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * p;
}

const int maxN = (int)2 + 10;
const int mod = (int)1e9 + 7;
const int INF = (int)1e9 + 5;
const ll LLINF = (ll)1e18 + 5;

int dp[1 << maxN][maxN];

int solve(int mask, int n) {
    return dp[mask][n];
}

int calcDp(const string s) {
    int x = 0;
    int n = s.length();
    for (int i = 0 ; i< n; ++i) {
        int v = (s[i] == '-' ? 1 : 0);
        x += v << i;
    }
  //  cout << x << ' ';
    return solve(x, n);
}

void bfs(int n) {
    int v = 0;
    queue <int> q;
    dp[v][n] = 0;
    q.push(v);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
     //   cout << v << '\n';
        for (int i = 0; i < n; ++i) {
            int cur = v;
            for (int j = 0; j <= i / 2; ++j) {
                int a = (v >> j) & 1;
                int b = (v >> (i - j)) & 1;
                if (a == b) continue;
                cur ^= 1 << j;
                cur ^= 1 << (i - j);
            }
            cur ^= (1 << (i + 1)) - 1;
           // cout << cur << '\n';
            if (dp[cur][n] == -1) {
                dp[cur][n] = dp[v][n] + 1;
                q.push(cur);
            }
        }
    }
   // cout << '\n';

}

void solve(string s) {
    int res = 0;
    int n = s.length();
  //  cout << s << '\n';
    cout << calcDp(s) << '\n';
    return;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '-') {
            if (s[0] == '+') {
                res++;
                s[0] = '-';
            }
            res++;
            reverse(s.begin(), s.begin() + i + 1);
            for (int j = 0; j <= i; ++j) {
                if(s[j] == '+') s[j] = '-';
                else s[j] = '+';
            }
        }
    }
    cout << res << '\n';
}

int main() {

    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    for (int n = 1; n <= 10; ++n) {
        bfs(n);
    }
    int t;
    t = nextInt<int>();
    for (int i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        printf("Case #%d: ", i);
        solve(s);
    }
    return 0;
}
