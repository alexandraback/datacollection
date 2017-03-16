#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 1<<30
#define MAXN 10

using namespace std;

int fst[MAXN], snd[MAXN], n;
int DP[1<<MAXN][1<<MAXN];

int solve(int mfst, int mask, int amount)
{
    if((1<<n)-1 == mask)
        return 0;
    int &ret = DP[mfst][mask];
    if(ret != INF)
        return ret;
    bool check = false;
    for(int i = 0; i < n; i++)
    {
        if( !(mask & (1<<i)))
        {
            if(amount >= snd[i])
            {
                ret = min(ret, solve(mfst,mask|(1<<i),amount + ((!(mfst&(1<<i))) ? 2 : 1))+1);
                check = true;
            }else if(amount >= fst[i] && !(mfst&(1<<i)))
            {
                ret = min(ret, solve(mfst|(1<<i),mask,amount+1)+1);
                check = true;
            }
        }
    }
    return ret;
}

int main()
{
    /*freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-soutput.out", "w", stdout);*/
    int t, tz = 1;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &fst[i], &snd[i]);
        for(int i = 0; i < (1<<n); i++)
            for(int j = 0; j < (1<<n); j++)
                DP[i][j] = INF;
        int resp = solve(0,0,0);
        if( resp == INF)
            printf("Case #%d: Too Bad\n",tz++);
        else
            printf("Case #%d: %d\n", tz++,resp);
    }
    return 0;
}
