#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
#define fix(x) x = x >= MOD ? x % MOD : x

int n,cnt[40];
int f0[40][40];
string g[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ff[10] = {0,4,6,8,3,2,5,7,1,9};
int ans[11];
char ch[N];
int l;

int gcd(int x,int y) {return x % y == 0 ? y : gcd(y , x % y);}

void init()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%s",ch);
    l = strlen(ch);
    for(int i = 0;i < l;i++) cnt[ ch[i] - 'A' + 1 ]++;
}

void work()
{
    for(int ti = 0;ti < 10;ti++)
    {
        int i = ff[ti],now = 10000;
        for(int j = 1;j <= 26;j++)
        if(f0[i][j] > 0)
        {
            now = min(now , cnt[j] / f0[i][j]);
        }

        for(int j = 1;j <= 26;j++)
        if(f0[i][j] > 0)
        {
            cnt[j] -= f0[i][j] * now;
        }

        ans[i] = now;
    }

    for(int i = 0;i < 10;i++)
    {
        for(int j = 1;j <= ans[i];j++) printf("%d",i);
    }
    printf("\n");
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    for(int i = 0;i <= 9;i++)
    {
        for(int j = 0;j < g[i].size();j++)
          f0[i][ g[i][j] - 'A' + 1 ]++;
    }

    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
