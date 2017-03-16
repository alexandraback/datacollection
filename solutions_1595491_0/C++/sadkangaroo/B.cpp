#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<climits>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

const int MaxN = 100 + 5;

int T, N, S, P;
int a[MaxN];

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    scanf("%d", &T);
    for (int te = 1; te <= T; ++te) {
        scanf("%d%d%d", &N, &S, &P);
        for (int i = 0; i < N; ++i) scanf("%d", a + i);
        sort(a, a + N);
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (S && a[i] >= 2 && a[i] <= 28) {
                int tmp = a[i] - P - (P - 2);
                if (tmp >= P - 2) {
                    ans++;
                    S--;
                    continue;
                }
            }
            int tmp = a[i] / 3;
            if (a[i] % 3) tmp++;
            if (tmp >= P) ans++;
        }
        printf("Case #%d: %d\n", te, ans);
    }

    return 0;

}

