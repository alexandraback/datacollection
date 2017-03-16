#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1000 + 10;

using namespace std;

int ans[60][60];
int num[60];
void init(int n)
{
    memset(ans, 0 ,sizeof ans);
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<n;j++)  ans[i][j] = 1;
    }
    num[1]=1;
    for (int i=2;i<n;i++)
    {
        num[i] = 0;
        for (int j=1;j<i;j++)
        if (ans[j][i]) num[i]+=num[j];
    }
}
void work()
{
    int B , M;
    bool flag=0;
    scanf("%d%d",&B,&M);
    init(B);
    int n = B - 1;
    for (int s = 0 ;s <(1<<n) ; s++)
    {
        int cut = 0;
        for (int i = 1 ; i <= n ; i ++)
        {
            if (s & (1<<(i-1))) cut += num[i];
        }
        if (cut == M)
        {
            printf(" POSSIBLE\n");
            //printf("%d\n",s);
            flag = 1;
            for (int i = 1; i <= n ; i ++)
            if (s & (1<<(i-1))) ans[i][B] = 1;
            for (int i=1;i<=B;i++)
            {
                for (int j=1;j<=B;j++) printf("%d",ans[i][j]); printf("\n");
            }
            return;
        }
    }
    if (!flag) printf(" IMPOSSIBLE\n");
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, cas = 0 ;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d:",++cas);
        work();
    }
    return 0;
}
