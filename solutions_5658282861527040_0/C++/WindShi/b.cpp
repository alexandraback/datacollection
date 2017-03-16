#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test;
long long w[31], v[1001], a1[1001], a2[1001], a3[1001], v1[131], v2[131], v3[131];
int A, B, K;

inline void change(long long  *a, long long *q, int now){
    memset(v, 0, sizeof(v));
    v[0] = 0;
    for (; now; now >>= 1) v[++v[0]] = now & 1;
    a[0] = v[0];
    for (int i = 1, j = 30; i <= 30; i++, j--)
        a[i] = v[j];
    q[31] = 0;
    for (int i = 30, j = 0; i; --i, ++j) 
        if (a[i]) q[i] = q[i + 1] + (1 << j);
        else q[i] = q[i + 1];
}

int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    w[0] = 1;
    for (int i = 1; i <= 30; i++) w[i] = w[i - 1] * 2;
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        printf("Case #%d: ", uu);
        scanf("%d%d%d", &A, &B, &K);
        long long ans = 0;
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K) ++ans;
        printf("%lld\n", ans);
    }
}
