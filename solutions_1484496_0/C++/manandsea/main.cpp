#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;


int first[10000000 + 2];
int a[1024], sum[1 << 20];
int T, N;

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    cin >> T;
    for (int ca = 1; ca <= T; ++ ca) {
        memset(first, -1, sizeof(first));
        cin >> N;
        for (int i = 0; i < N; ++ i) {
            cin >> a[i];
        }
        printf("Case #%d:\n", ca);
        sum[0] = 0;
        first[0] = 0;
        for (int i = 0; i < 1 << N; ++ i) {
            int j = 0;
            for (int k = N - 1; k >= 0; -- k) if ((i >> k) & 1) { j = k; break; }

            sum[i] = a[j] + sum[i - (1 << j)];

            if (first[sum[i]] != -1) {
                int sx = i, sy = first[sum[i]];
                int tmp = sx & sy;
                sx ^= tmp, sy ^= tmp;
                bool begin = false;
                for (int k = N - 1; k >= 0; -- k) {
                    if ((sx >> k) & 1){
                        if (begin) putchar(' ');
                        printf("%d", a[k]);
                        begin = true;
                    }
                }
                puts("");
                begin = false;
                for (int k = N - 1; k >= 0; -- k) {
                    if ((sy >> k) & 1){
                        if (begin) putchar(' ');
                        printf("%d", a[k]);
                        begin = true;
                    }
                }
                puts("");
                break;
            } else first[sum[i]] = i;
        }
    }
}
