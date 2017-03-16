#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char c[1000100];
int  s[1000100], n, len;
int  f[1000100];
void init() {
    memset(f, 0, sizeof(f));
    scanf("%s%d", c + 1, &n);
    len = (int)strlen(c + 1);
    s[0] = 0;
    for (int i = 1; i <= len; i++) {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
            s[i] = 0;
        else s[i] = 1;
    }
}


void solve() {
    /*long ans = 0;
    for (int i = 1; i <= len; i++) {
        int l = i, r = len, mid, need = s[i - 1] + n;
        while (r - l > 1) {
            mid = (l + r) >> 1;
            if (s[mid] < need) l = mid + 1;
                else r = mid;
        }
        if (s[l] >= need) ans += len - l + 1;
        else if (s[r] >= need) ans += len - r + 1;
    }
    cout << ans << endl;*/
    int sum = 0;
    for (int i = 1; i <= len; i++) {
        f[i] = f[i - 1];
        if (s[i]) {
            sum++;
            if (sum == n) {
                f[i] += i - n + 1;
            }
        } else sum = 0;
    }
    cout << f[len] << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        init();
        printf("Case #%d: ", i);
        solve();
    }
}

