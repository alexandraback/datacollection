#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long LL;
#define CLR(a,b) memset(a,b,sizeof(a))
const int N = 2000+5;
int n;

int f[N];
int vis[N];

void solve()
{
    unordered_map<int, int> two;
    int one = 0;
    for (int i = 0; i < n; ++i) {
        CLR(vis, -1);
        int pre = i;
        int cur = f[i];
        vis[i] = 0;
        int len = 1;
        while (true) {
            if (vis[cur] != -1) {
                if (pre == f[cur]) {
                    // two
                    two[cur] = max(two[cur], len - 1);
                } else {
                    int circle = len - vis[cur];
                    // one
                    one = max(one, circle);
                }
                break;
            } else {
                vis[cur] = len;
                len ++;
                pre = cur;
                cur = f[cur];
            }
        }
    }
    /*
    cout << "one : " << one << endl;
    for (auto& ite : two) {
        cout << ite.first << " : " << ite.second << endl;
    }
     */
    int ans = 0;
    for (auto& ite : two) {
        ans += ite.second;
    }
    ans = max(ans, one);
    printf("%d\n", ans);
}

int main()
{
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/input.txt", "r", stdin);
    freopen("/Users/lizhen/Documents/Project/Cpp/cpp/cpp/output.txt", "w", stdout);
    int T, cas = 0;
    scanf("%d", &T);
    while (T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &f[i]);
            f[i] --;
        }
        solve();
    }
    return 0;
}