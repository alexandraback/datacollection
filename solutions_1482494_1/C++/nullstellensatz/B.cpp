


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 1005;

int T, N, A, B;
pair<int, int> p[MaxN];
int q[MaxN];

int main() {
    scanf("%d", &T);
    for (int n = 1; n <= T; ++ n) {
        scanf("%d", &N);
        for (int k = 0; k < N; ++ k) {
            scanf("%d %d", &A, &B);
            p[k] = make_pair(B, A);
        }
        sort(p, p + N);
        memset(q, 0, sizeof q);
        int cnt = 0, s = 0;
        for (int k = 0; k < N; ++ k)
            if (cnt >= p[k].first) {
                cnt += 2;
                ++ s;
                q[k] = 2;
            }
        
        while (true) {
            int key = -1;
            for (int k = N - 1; k >= 0; -- k)
                if (q[k] == 0 && cnt >= p[k].second) {
                    key = k;
                    break;
                }
            if (key < 0) break;
            ++ cnt;
            ++ s;
            q[key] = 1;
            for (int k = 0; k < N; ++ k)
                if (q[k] < 2 && cnt >= p[k].first) {
                    cnt += 2 - q[k];
                    ++ s;
                    q[k] = 2;
                }
        }
        printf("Case #%d: ", n);
        if (cnt < (N << 1))
            puts("Too Bad");
        else
            printf("%d\n", s);
    }
    
    return 0;
}
