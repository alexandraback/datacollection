#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
int a[maxn];

int main() {
    freopen("B-large.in", "r", stdin);
    //freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++) {
        int n;
        cin >> n;
        int maxv = -1;
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
            maxv = max(maxv, a[i]);
        }

        int ans = maxv;
        
        for(int i = 1 ; i <= maxv ; i++) {
            int p = 0;
            for(int j = 0 ; j < n ; j++) {
                if(a[j] > i) {
                    if(a[j] % i == 0) p += a[j] / i - 1;
                    else p += a[j] / i;
                }
            }
            ans = min(ans, p + i);
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}
