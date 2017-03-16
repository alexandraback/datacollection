#include <iostream>
#include <string>
#include <memory.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <queue>
#include <list>

using namespace std;
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define forn(i,n) for(int i=0;i<n;++i)
int n; int arr[200005];
int dp[20005];
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int ans = 1005;
    for (int i = 1; i <= 1000; ++i) {
        int res = i;
        for (int j = 0; j < n; ++j)
            if (arr[j] <= i) continue;
            else {
                int cur = arr[j] / i;
                if (arr[j] % i != 0) cur++;
                cur--;
                res += cur;
            }
        ans = min(ans, res);
    }
    cout << ans << endl;
}
int main() {
    //freopen("input.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int num = 0;
    while (T--) {
        num++;
        cout << "Case #" << num << ": ";
        solve();
    }
    return 0;
}
