#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 102;

int A, N, x[maxn];
int ans, cnt;
int T;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++ ) {
        scanf("%d%d",&A,&N);
        for (int i = 0; i < N; i++ )
            scanf("%d",x+i);
        sort(x, x+N);
        printf("Case #%d: ",cas);
        ans = N;
        cnt = 0;
        if (A > 1)
           for (int i = 0; i < N; i++ ) {
               while (A <= x[i]) {
                     A += A - 1;
                     ++cnt;
               }
               A += x[i];
               ans = min(ans, cnt + N - i - 1);
           }
        printf("%d\n",ans);
    }
    return 0;
}
