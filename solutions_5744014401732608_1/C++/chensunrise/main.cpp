#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1000 + 10;

using namespace std;

int ans[60][60];
LL num[60];
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

void output(int B){
    printf(" POSSIBLE\n");
    for (int i=1;i<=B;i++)
    {
        for (int j=1;j<=B;j++) printf("%d",ans[i][j]); printf("\n");
    }
    return;
}

void work()
{
    int B ;
    LL M;
    scanf("%d%I64d",&B,&M);
    init(B);
    int n = B - 1;
    while(M>0){
        for (int i = n ; i >= 1; i--)
        {
            if (M>=num[i]){
                M-=num[i];
                n=i-1;
                ans[i][B] = 1;
            }
        }
        if (n==0) break;
    }
    if (M!=0) printf(" IMPOSSIBLE\n");
    else output(B);
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
