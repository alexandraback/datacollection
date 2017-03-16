#include <bits/stdc++.h>
using namespace std;
#define INF 20000000

int frec[10];
int ans;

void solve(int sum, int pos)
{
    if(sum > ans) return;
    int mayor = -1;
    for(int i = pos; i > 0 && mayor == -1; i--)
        if(frec[i] > 0)
            mayor = i;
    frec[mayor]--;
    ans = min(ans, sum + mayor);
    for(int i = 1; i < mayor; i++)
    {
        frec[i]++;
        frec[mayor-i]++;
        solve(sum + 1, mayor);
        if(sum > ans) return;
        frec[i]--;
        frec[mayor-i]--;
    }
    frec[mayor]++;
}

int main()
{
    int T,D,x,pos,ntest=1;
    scanf("%d\n",&T);
    while(T--)
    {
        scanf("%d\n",&D);
        memset(frec, 0, sizeof frec);
        pos = 0;
        for(int i = 0; i < D; i++)
        {
            scanf("%d",&x);
            frec[x]++;
            pos = max(pos, x);    
        }
        ans = INF;
        solve(0,pos);
        printf("Case #%d: %d\n",ntest++,ans);
    }
    return 0;
}