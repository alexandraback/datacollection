/* ***********************************************
Author        :oilover
Created Time  :2016/4/9 8:29:42
File Name     :
************************************************ */

#include <bits/stdc++.h>
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;
int K, C, S;
int main()
{
    int re, ca=1; cin>>re;
    while (re--) {
        cin >> K >> C >> S;
        printf("Case #%d: ", ca++);
        if (C * S < K) {
            puts("IMPOSSIBLE");
            continue;
        }
        int b = 0;
        LL ans[123];
        int n = (K+C-1)/C;
        for (int i=0;i<(K+C-1)/C;i++)
        {
            LL t = 0;
            for (int j=0;j<C;j++,b=(b+1)%K)
                t = t*K + b;
            ans[i] = t;
        }
        for (int i=0;i<n;i++)
            printf("%lld%c", ans[i]+1, i==n-1 ? 10 : ' ');
    }
}
