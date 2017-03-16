#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T = 0, n;
    static int a[2000], b[2000], earn[2000];
    static bool p1[2000], p2[2000];
    int left, total, star, idx;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i], &b[i]);
        left = n;
        total = 0;
        star = 0;
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        while (left > 0) {
            for (int i = 0; i < n; i++) {
                if (star >= b[i] && !p2[i]) {
                    earn[i] = p1[i] ? 1 : 2;
                } else {
                    earn[i] = 0;
                }
            }
            idx = max_element(earn, earn + n) - earn;
            if (earn[idx] != 0) {
                total++;
                star += earn[idx];
                p2[idx] = true;
                left--;
                //printf("%dB ", idx);
                continue;
            }

            for (int i = 0; i < n; i++) {
                if (star >= a[i] && !p2[i] && !p1[i]) {
                    earn[i] = 3000 + b[i];
                } else {
                    earn[i] = 0;
                }
            }
            idx = max_element(earn, earn + n) - earn;
            if (earn[idx] != 0) {
                total++;
                star += 1;
                p1[idx] = true;
                //printf("%dA ", idx);
                continue;
            }
            break;
        }
        if (left != 0) {
            printf("Case #%d: Too Bad\n", t);
        } else {
            printf("Case #%d: %d\n", t, total);
        }
    }
}
