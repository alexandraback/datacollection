#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,d,c;
    int v;
    int dd[100];
    int chose[100];
    int vis[110];
    int vis2[110];
    int cases;
    scanf("%d",&t);
    cases=0;
    while(t--)
    {
        cases++;
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&c,&d,&v);
        for(int i=1; i<=d; i++)
        {
            scanf("%d",&dd[i]);
        }
        int now=1<<d;
        now--;
        //printf("%d\n",now);
        while(now>=0)
        {
            memset(chose,0,sizeof(chose));
            int tmp=now;
            int i=1;
            while(tmp>0)
            {
                if(tmp%2==1)
                {
                    chose[i]=1;
                }
                tmp/=2;
                i++;
            }
            now--;
            int ans=0;
            for(int j=1; j<i; j++)
            {
                if(chose[j]==1)
                {
                    ans+=dd[j];
                }
            }
            //printf("%d\n",ans);
            vis[ans]=1;
            //printf("--%d\n",ans);
        }
        int anss=0;
        /*for(int i=1; i<=v; i++)
        {
            printf("%d ",vis[i]);
        }
        puts("");*/
        for(int i=1; i<=v; i++)
        {
            memset(vis2,0,sizeof(vis2));
            if(vis[i]==0)
            {
                anss++;
                memset(vis2,0,sizeof(vis2));
                for(int j=1; j<=v; j++)
                {
                    if(j!=i&&vis[j]==1)
                    {
                        vis2[j+i]=1;
                    }
                }
                vis[i]=1;
            }
            for(int k=1; k<=v; k++)
            {
                if(vis2[k]==1)
                {
                    vis[k]=1;
                }
            }
           /* for(int k=1; k<=v; k++)
            {
                printf("%d ",vis[k]);
            }
            puts("");*/
        }
        printf("Case #%d: %d\n",cases,anss);
    }
    return 0;
}
