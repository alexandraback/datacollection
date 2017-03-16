#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define N 2000
using namespace std;


int mark[N];
int need[N][2];

int main()
{
    int t,n,i,j,flag,ans,cur,ys,tmp,m;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("data.out","w",stdout);

    scanf("%d",&t);
    ys=0;
    while (t--)
    {
        scanf("%d",&n);

        for (i=0;i<n;i++)
            scanf("%d%d",&need[i][0],&need[i][1]);

        memset(mark,0,sizeof(mark));
        ans=cur=0;

        while (cur<2*n)
        {
            flag=0;

            for (i=0;i<n;i++)
                if (cur>=need[i][1]&&mark[i]==0)
                {
                    flag=1;
                    mark[i]=2;
                    ans++;
                    cur+=2;
                    break;
                }

            if (flag)
                continue;


            for (i=0;i<n;i++)
                if (cur>=need[i][1]&&mark[i]==1)
                {
                    flag=1;
                    mark[i]=2;
                    ans++;
                    cur++;
                    break;
                }

            if (flag)
                continue;

            tmp=-1;
            m=0;
            for (i=0;i<n;i++)
                if (cur>=need[i][0]&&mark[i]==0)
                {
                    flag=1;

                    if (m<need[i][1])
                    {
                        m=need[i][1];
                        tmp=i;
                    }
                }

            if (flag)
            {
                cur++;
                ans++;
                mark[tmp]=1;
                continue;
            }

            ans=-1;
            break;
        }

        if (ans==-1)
            printf("Case #%d: Too Bad\n",++ys);
        else
            printf("Case #%d: %d\n",++ys,ans);
    }

    return 0;
}

