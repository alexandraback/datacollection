#include <iostream>
#include <cstdio>
using namespace std;
int a[2000],b[2000];
int n;
bool ook(int x, int y) {
    for (int i = 0; i < n; i++)
        a[i]=b[i];
    for (int i = 0; i < n; i++) {
        if (a[i] <= y) continue;
        if (a[i] % y == 0)
            x -= (a[i] / y) - 1;
        else
            x -= (a[i] / y);
        if (x < 0) return false;
    }
    return true;
}
bool ok(int T){
    for (int i = 0; i < T; i++)
        if (ook(i, T-i))
        return true;
    return false;
}
int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++) {
        cin >> n;
        for (int i =0 ; i < n; i++)
            cin >> b[i];
        int l = 1, r = 1005;
        while (l + 1< r) {
            int mid = (l + r) / 2;
            if (ok(mid)){
                r = mid;
            } else
            {
                l = mid + 1;
            }
        }
        while (r > 0 && ok(r - 1)) r--;
        printf("Case #%d: %d\n", o, r);
    }
}
