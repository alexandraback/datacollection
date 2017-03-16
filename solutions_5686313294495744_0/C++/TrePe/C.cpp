#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n;
char fw[20][40], sw[20][40];
int m;

int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%s%s", fw[i], sw[i]);
        int bm = 0;
        for (m = 0; m < (1 << n); m++) {
            set<string> wasf, wass;
            int cnt = 0;
            for (i = 0; i < n; i++) {
                if (m & (1 << i)) {
                    wasf.insert(fw[i]);
                    wass.insert(sw[i]);
                }
            }
            for (i = 0; i < n; i++) {
                if (m & (1 << i)) continue;
                cnt++;
                if (wasf.find(fw[i]) == wasf.end()) break;
                if (wass.find(sw[i]) == wass.end()) break;
            }
            if (i < n) continue;
            if (cnt > bm) bm = cnt; 
        }
        printf("%d\n", bm);
    }
    return 0;
}
