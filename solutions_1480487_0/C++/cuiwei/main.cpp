#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 222;

int prev[MAXN];
bool s[MAXN];
double quick[MAXN], times[MAXN], load;

int main() {
    freopen("D:\\A-small-attempt0.in", "r", stdin);
    freopen("D:\\A-small-attempt0.out", "w", stdout);
    int input, all, total, totalX, cnt;
    scanf("%d", &input);
    for (int i = 1; i <= input; ++i) {
        total = 0;
        scanf("%d", &all);
        for (int j = 1; j <= all; ++j) {
            s[j] = 1;
            scanf("%d", &prev[j]);
            total += prev[j];
        }
        totalX = total;
        cnt = all;
        printf("Case #%d:", i);
        for (int j = 1; j <= all; ++j)
            times[j] = prev[j] / double(total);
        load = 2.0 / all;
        for (int j = 1; j <= all; ++j)
            if (load <= times[j]) {
                s[j] = quick[j] = 0;
                --cnt;
                totalX -= prev[j];
            }
        load = (total + totalX) / double(cnt);
        for (int j = 1; j <= all; ++j)
            if (s[j]) {
                quick[j] = (load - prev[j]) / total;
            }
        for (int j = 1; j <= all; ++j)
            printf(" %.6lf", quick[j]*100);
        printf("\n");
    }
    return 0;
}
