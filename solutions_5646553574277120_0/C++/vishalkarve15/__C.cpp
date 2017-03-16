#include<bits/stdc++.h>

using namespace std;

int deno[33];
int ds[33];

int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        memset(deno,0,sizeof deno);
        int c,d,v;
        scanf("%d%d%d",&c,&d,&v);

        for(int i=0;i<d;i++)
        {
            scanf("%d",&ds[i]);
        }

        bool done=0;
        int ans=0;
        while(done==0)
        {
            int com=(1<<d);
            memset(deno,0,sizeof deno);
            for(int i=0;i<com;i++)
            {
                int ss=0;
                for(int j=0;j<d;j++)
                {
                    if((i>>j)&1)
                        ss+=ds[j];
                }
                if(ss<=v)
                    deno[ss]=1;
            }
            done=1;
            for(int i=1;i<=v;i++)
            {
                if(deno[i]==0)
                {
                    done=0;
                    ds[d++]=i;
                    ans++;
                    sort(ds,ds+d);
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",tt,ans);
    }
    return 0;
}
