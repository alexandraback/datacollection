#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[1000];
long long C,D;
long long V;

int main() {
    freopen("C-large.in","r",stdin);
    freopen("Clarge.out","w",stdout);
    //freopen("C.in","r",stdin);
    int T;
    cin >> T;
    int ans;
    for (int o = 1; o <= T; o++) {
        cin >> C >> D >> V;
        for (int i = 0; i < D; i++)
            cin >> a[i];
        sort(a,a+D);
        int ans = 0;
        long long now = 1;
        for (int i = 0; i < D; i++) {
            if (a[i] <= now) {
                now += a[i] * C;
            } else {
                ans++;
                now += now * C;
                i--;
            }
            if (now > V) break;
        }
        while (now <= V) {
            ans ++;
            now += now * C;
        }
        printf("Case #%d: %d\n", o, ans);
    }
}
