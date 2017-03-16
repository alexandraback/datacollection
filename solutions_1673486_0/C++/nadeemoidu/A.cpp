
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cstdio>

using namespace std;
int m, n;
long double p[1123456];
long double sp[1123456];
int main()
{
    int T,iT;
    scanf("%d",&T);
    for(iT = 1; iT <= T; iT++) {
        int A, B;
        scanf("%d%d",&A, &B);
        int i;
        sp[0] = p[0] = 1;
        for(i = 1; i <= A; i++) {
            scanf("%Lf", p+i);
            sp[i] = sp[i-1] * p[i];
        }

        long double ans = B + 2, tmp;
        for(i = 0; i <= A; i++) {
            tmp = A - i + B - i + 1 + (1 - sp[i]) * (B + 1);
//            printf("%d %Lf\n", i, tmp);
            if(tmp < ans) ans = tmp;
        }
        printf("Case #%d: %Lf\n", iT, ans);
    }
   return 0;
}
