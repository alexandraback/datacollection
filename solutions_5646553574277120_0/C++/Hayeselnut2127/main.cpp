#include <cstdio>

int T, C, D, V;
int d, next_d = 1;
long long sum;
int y;

int main () {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &T);
    
    for (int x = 1; x <= T; x++) {
        scanf("%d %d %d", &C, &D, &V);
        for (int i = 0; i < D; i++) {
            scanf("%d", &d);
            if (sum < d) {
                while (sum < d) {
                    sum += next_d;
                    next_d *= C + 1;
                    y++;
                }
            }
            sum += d;
        }
        if (sum < V) {
            while (sum < V) {
                sum += next_d;
                next_d *= C + 1;
                y++;
            }
        }
        sum += V;
        y--;
        printf("Case #%d: %d\n", x, y);
        y = 0; next_d = 1; sum = 0;
    }
    
    return 0;
}