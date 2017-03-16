#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 10010
#define LL long long
int val[maxn], f[maxn];
int N, R, E;

int main() {
    int i, j;
    int t, cas;
    LL tmp, k;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    scanf("%d", &t);
    for (cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &E, &R, &N);
        for (i = 1; i <= N; i++) {
            scanf("%d", &val[i]);
        }
        f[N + 1] = N + 1;
        for (i = N; i >= 1; i--) {
            j = i + 1;
            while (j <= N && val[j] < val[i]) {
                j = f[j];
            }
            f[i] = j;
        }
        LL ans = 0;
        tmp = E;
        for (i = 1; i <= N; i++) {
            k = 0;
            if (f[i] <= N) {
                k = max((f[i] - i)*1LL * R + tmp - E, 0LL);
            } else {
                k = tmp;
            }
            k = min(tmp, k);
            ans += k * val[i];
            tmp -= k - R;
        }
        printf("Case #%d: ", cas);
        cout << ans << endl;
    }
    return 0;
}

