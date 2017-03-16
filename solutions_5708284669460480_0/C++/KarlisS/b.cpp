#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int K, L, S;
const int MXL = 128;
char WK[MXL];
char WL[MXL];

double pc[MXL][MXL];
double expc[MXL][MXL];
int dp[MXL][MXL];

double solve()
{
    for (int i=0; i<=L; i++)
    {
        for (int j=0; j<=L; j++)
        {
            pc[i][j] = 0;
        }
    }
    
    double padd=1.0/double(K);
    for (int have=0; have<=L; have++)
    {
        for (int nc=0; nc<K; nc++)
        {
            for (int nl=min(L, have+1) ; nl>=0; nl--)
            {
                bool bad = false;
                if (nl == 0 || WL[nl-1] == WK[nc])
                {
                    for (int p=0; p<nl-1; p++) {
                        if (WL[p] != WL[have-nl+p+1]){
                            bad = true;
                            break;
                        }
                    }
                }
                else
                {
                    bad = true;
                }
                if (!bad) {
                    pc[have][nl] += padd;
                    break;
                }
            }
        }
    }
    for (int i=0; i<=L; i++) {
        for (int j=0; j<=L; j++) {
           // printf("x:%d %d %.9f\n", i, j, pc[i][j]);
        }
    }
    for (int pos=0; pos<=S; pos++)
        for (int maxpr=0; maxpr<=L; maxpr++) expc[pos][maxpr]=0.0;

    expc[0][0] = 1;
    double ans=0;
    for (int pos=0; pos<=S; pos++)
    {
        ans -= expc[pos][L];
        for (int cl=0; cl<= L; cl++)
        {
            for (int nl=0; nl<=L; nl++){
                expc[pos+1][nl] += expc[pos][cl]*pc[cl][nl];
            }
        }
    }
    memset(dp, 0x81, sizeof(dp));
    dp[0][0] = 0;
    for (int pos=0; pos<=S; pos++)
    {
        for (int cl=0; cl<=L; cl++) {
            for (int nl=0; nl<=L; nl++) {
                int nv = dp[pos][cl] + (nl == L ? 1 : 0);
                if (pc[cl][nl] != 0) {
                    dp[pos+1][nl] = max(dp[pos+1][nl], nv);
                }
            }
        } 
    }
    int bestdp=0;
    for (int i=0; i<=L; i++) bestdp = max(bestdp, dp[S][i]);
    //printf("exp:%.9f %d\n", ans, bestdp);
    return bestdp+ans;
}



int main()
{
    int t;
    scanf("%d", &t);
    for (int nt=1; nt<=t; nt++)
    {
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s %s", WK, WL);
        printf("Case #%d: ", nt);
        printf("%.8f\n", solve());
    }
    return 0;
}
