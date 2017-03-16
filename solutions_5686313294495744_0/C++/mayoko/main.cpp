#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int MAXN = 1111;
string former[MAXN], after[MAXN];
int dp[16][1<<16];
int N;

int dfs(int now, int state) {
    int& ret = dp[now][state];
    if (ret >= 0) return ret;
    ret = 0;
    int tmp = 0;
    bool f = false, a = false;
    for (int i = 0; i < N; i++) if ((state>>i)&1) {
        if (i==now) continue;
        if (former[i] == former[now]) f = true;
        if (after[i] == after[now]) a = true;
    }
    if (a&&f) tmp = 1;
    ret = tmp;
    for (int i = 0; i < N; i++) if (((state>>i)&1)==0) {
        ret = max(ret, dfs(i, state|1<<i)+tmp);
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> former[i] >> after[i];
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < N; i++) ans = max(ans, dfs(i, 1<<i));
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " ;
        solve();
    }
    return 0;
}
