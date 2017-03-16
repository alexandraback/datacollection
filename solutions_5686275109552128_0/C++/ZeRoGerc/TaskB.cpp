#include <iostream>

using namespace std;

int T, n;
int a[1010];

bool check(int time) {
    for (int k1 = 0; k1 < time; k1++) {
        int need = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > time - k1) {
                need += a[i] / (time - k1);
                if (a[i] % (time - k1) == 0) {
                    need--;
                }
            }
        }
        if (need <= k1) {
            return true;
        }
    }
    
    return false;
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    cin >> T;
    
    for (int I = 0; I < T; I++) {
        cin >> n;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        if (mx == 0) {
            printf("Case #%d: 0\n", I + 1);
            continue;
        }
        
        int l = -1, r = 1001;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (!check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        printf("Case #%d: %d\n", I + 1, r);
    }
}