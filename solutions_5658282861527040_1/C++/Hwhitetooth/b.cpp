#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

const int N = 40 + 10;
const int MOD = 1000000000 + 7;

int A, B, K;
int a[N], b[N], c[N];
int vis[N][2][2][2];
long long f[N][2][2][2];

long long dfs(int len, int p1, int p2, int p3)
{
    if (len == -1) {
        return p1 && p2 && p3;
    }
    if (vis[len][p1][p2][p3]) {
        return f[len][p1][p2][p3];
    }
    long long ret = 0;
    for(int s1 = 0; s1 < 2; ++ s1) {
        if (s1 > a[len] && p1 == false) continue;
        for(int s2 = 0; s2 < 2; ++ s2) {
            if (s2 > b[len] && p2 == false) continue;
            int s3 = s1 & s2;
            if (s3 > c[len] && p3 == false) continue;
            ret += dfs(len - 1, p1 || s1 < a[len], p2 || s2 < b[len], p3 || s3 < c[len]);
        }
    }
    vis[len][p1][p2][p3] = true;
    f[len][p1][p2][p3] = ret;
    return ret;
}

void solve()
{
    cin >> A >> B >> K;
    memset(vis, 0, sizeof vis);
    memset(f, 0, sizeof f);
    memset(a, 0, sizeof a);
    for(int i = 0; i < N; ++ i) {
        a[i] = A & 1;
        A /= 2;
    }
    memset(b, 0, sizeof b);
    for(int i = 0; i < N; ++ i) {
        b[i] = B & 1;
        B /= 2;
    }
    memset(c, 0, sizeof c);
    for(int i = 0; i < N; ++ i) {
        c[i] = K & 1;
        K /= 2;
    }

    cout << dfs(N - 1, 0, 0, 0) << endl;
}

int main()
{
    int test; cin >> test;
    int tot = 0;
    for( ; test --; ) {
        ++ tot;
        printf("Case #%d: ", tot);
        solve();
    }
    return 0;
}