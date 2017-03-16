#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

const int N = 10000;

int e, r, n, v[N], l[N], x[N], d[N];

int main() {
    int test_count;
    scanf("%d", &test_count);
    for (int t = 1; t <= test_count; ++ t) {
        scanf("%d%d%d", &e, &r, &n);
        for (int i = 0; i < n; ++ i) {
            scanf("%d", v + i);
        }
        l[0] = x[0] = e;
        for (int i = 1; i < n; ++ i) {
            l[i] = std::min(l[i - 1] - x[i - 1] + r, e);
            x[i] = l[i];
            int max_trans = INT_MAX;
            int j = i - 1;
            while (j >= 0 && v[j] < v[i]) {
                max_trans = std::min(max_trans, e - l[j + 1]);
                if (max_trans <= 0) {
                    break;
                }
                d[j] = std::min(max_trans, x[j]);
                max_trans -= d[j];
                j --;
            }
            while (j + 1 < i) {
                j ++;
                x[j] -= d[j];
                x[j + 1] += d[j];
                d[j + 1] += d[j];

                l[j + 1] += d[j];
            }
        }
        long long answer = 0;
        for (int i = 0; i < n; ++ i) {
            answer += (long long)v[i] * x[i];
        }
        printf("Case #%d: %lld\n", t, answer);
    }
    return 0;
}
