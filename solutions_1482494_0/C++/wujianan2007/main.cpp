#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 1005
#define INF 999999999
int t, n;
int a[MAXN][2];
bool b[MAXN][2];

int main() {
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1];
        memset(b, 0, sizeof (b));
        int rem = 0;
        int ans = 0;
        bool wa = 0;
        while (1) {
            int cur = INF, p;
            for (int j = 0; j < n; j++) {
                if (!b[j][1] && rem >= a[j][1] && cur > a[j][1]) {
                    cur = a[j][1];
                    p = j;
                }
            }
            if (cur != INF) {
                rem++;
                if (!b[p][0]) rem++;
                b[p][0] = b[p][1] = 1;
                ans++;
            } else {
                int mm = 0;
                for (int j = 0; j < n; j++) {
                    if (!b[j][0] && rem >= a[j][0] && mm <= a[j][1]) {
                        cur = a[j][0];
                        p = j;
                        mm = a[j][1];
                    }
                }
                if (cur != INF) {
                    rem++;
                    b[p][0] = 1;
                    ans++;
                } else break;
            }
        }
        for (int i = 0; i < n; i++)
            if (!b[i][1]) wa = 1;
        printf("Case #%d: ", cas);
        if (!wa) cout << ans << endl;
        else cout << "Too Bad\n";
    }
    return 0;
}