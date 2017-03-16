#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T;
    cin >> T;
    int n; string s;
    for (int o = 1; o <= T; o++) {
        cin >> n >> s;
        int ans = 0; int now = 0;
        for (int i = 0; i <= n; i++) {
            if (now >= i) {
                now += s[i] - 48;
            } else {
                while (now<i) {ans++;now++;}
                now += s[i] - 48;
            }
        }
        printf("Case #%d: %d\n", o, ans);
    }
}
