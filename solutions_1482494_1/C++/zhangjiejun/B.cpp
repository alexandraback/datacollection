#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[2000], b[2000], beat[2000];;

int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int curt = 0; curt < t; ++curt) {
        printf("Case #%d: ", curt + 1);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        memset(beat, 0, sizeof beat);
        int earn = 0, ans = 0, change = 1;
        while (change) {
            change = 0;
            for (int i = 0; i < n; ++i) {
                if (beat[i] != 2 && a[i] <= earn && b[i] <= earn) {
                    ++ans;
                    earn += 2 - beat[i];
                    beat[i] = 2;
                    change = 1;
                    break;
                }
            }
            if (change) continue;
            int maxb = -1, pick = -1;
            for (int i = 0; i < n; ++i) {
                if (beat[i] == 0 && a[i] <= earn && b[i] > maxb) {
                    maxb = b[i];
                    pick = i;
                }
            }
            if (maxb == -1) break;
            beat[pick] = 1;
            ++ans;
            ++earn;
            change = 1;
        }
        if (earn == 2*n) {
            printf("%d\n", ans);
        } else {
            printf("Too Bad\n");
        }
    }
    return 0;
}
