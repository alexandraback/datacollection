#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int t, l, r;
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cin >> l >> r;
        cout << "Case #" << tt << ": ";
        if (l > 0) {
            for (int i = 1; i <= l; ++i) 
                printf("WE");
        } else {
            for (int i = 1; i <= -l; ++i)
                printf("EW");
        }
        if (r > 0) {
            for (int i = 1; i <= r; ++i) 
                printf("SN");
        } else {
            for (int i = 1; i <= -r; ++i)
                printf("NS");
        }
        printf("\n");
    }
    return 0;
}
