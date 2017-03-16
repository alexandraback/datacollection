#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>
#include <unordered_map>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-10;
const int inf = 1000000000;

const int N = 100005;
const int mo = 1000000000 + 7;

int n, cnt[10005];

void work()
{
    cin >> n;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i + 1 < n * 2; ++i)
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            ++cnt[x];
        }
    vector<int> ans;
    for (int i = 0; i <= 2500; ++i)
        if (cnt[i] % 2 == 1)
            ans.pb(i);
    assert(sz(ans) == n);
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i + 1 < n) cout << ' ';
        else cout << endl;
    }
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}
