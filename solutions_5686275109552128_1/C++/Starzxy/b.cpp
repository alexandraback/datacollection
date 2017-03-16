#include<cstdio>

using namespace std;

const int INF=1000000000;

int T,n;
int p[1010];

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++)
            scanf("%d",p+i);
        int ans=INF;
        for(int j=1;j<=1000;j++)
        {
            int temp=0;
            for(int k=1;k<=n;k++)
                if(p[k]>j)
                    temp+=(p[k]-1)/j;
            temp+=j;
            if(temp<ans)ans=temp;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
/*
3
1
3
4
1 2 1 2
1
4
*/
