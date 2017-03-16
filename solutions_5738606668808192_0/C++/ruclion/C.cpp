#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

const int maxn = 1000;

int a[maxn];
int n, num;

void solve() {
    a[0] = 1;
    a[n - 1] = 1;
    for(int s = 0; s < num; s++) {
        for(int i = 1; i < n / 2; i++) {
            int j = i - 1;
            if((1 << j) & s) {
                a[i] = 1;
            }
            else {
                a[i] = 0;
            }
        }
        a[n / 2 - 1] = 1;
        for(int i = n / 2 - 1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        for(int i = n / 2 - 1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        for(int i = 2; i <= 10; i++) {
            ll ans = 0;
            for(int j = n / 2 - 1; j >= 0; j--) {
                ans = ans * (ll)i + a[j];
            }
            printf(" %lld", ans);
        }
        printf("\n");
    }
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("Cout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d:\n", i);
        scanf("%d%d", &n, &num);
        solve();
    }

    return 0;
}
