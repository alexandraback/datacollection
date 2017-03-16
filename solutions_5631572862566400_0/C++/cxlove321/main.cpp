#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n, a[N], vis[N], ispair[N], b[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t, cas = 0;
    cin >> t;
    while (t --) {
        cout << "Case #" << (++ cas) << ": ";
        cin >> n;
        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
        }
        memset (ispair , 0 , sizeof (ispair));
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = i + 1 ; j <= n ; j ++) {
                if (a[i] == j && a[j] == i) {
                    ispair[i] = ispair[j] = 1;
                    ans = 2;
                }
            }
        }
        memset (b, 0, sizeof (b));
        for (int i = 1 ; i <= n ; i ++) {
            if (ispair[i]) continue;
            int now = i , len = 1;
            vis[i] = 1;
            memset (vis , 0 , sizeof (vis));
            while (true) {
                int nxt = a[now];
                if (nxt == i) {
                    ans = max (ans , len);
                    break;
                }
                if (vis[nxt] == 1) {
                    break;
                }
                if (ispair[nxt] == 1) {
                    b[nxt] = max(b[nxt], len);
                    break;
                }
                vis[nxt] = 1;
                len ++;
                now = nxt;
            }
        }
        int ret = 0;
        for (int i = 1; i <= n ; i ++) {
            if (ispair[i]) ret += 1 + b[i];
        }
        cout << max (ret , ans )<< endl;
    }

	return 0;
}
	
