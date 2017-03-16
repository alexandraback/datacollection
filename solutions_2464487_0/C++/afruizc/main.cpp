#include <cstdio>

int T;
int r, t, total_r;

int main() {
    scanf("%d", &T);
    for (int c=1 ; c<=T ; c++) {
        scanf("%d %d", &r, &t);
        total_r = r-1;
        int ans = 0;
        while (t > 0) {
            total_r += 2;
            int restar = ((total_r*total_r) - ((total_r-1)*(total_r-1)));
            if (restar <= t) {
                t -= restar;
                ans++;
            }
            else {
                t = 0;
            }
        }

        printf("Case #%d: %d\n", c, ans);
    }
}