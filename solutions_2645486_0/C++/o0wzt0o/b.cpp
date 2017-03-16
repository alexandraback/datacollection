#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int e,r,n;
int v[10010];
int ma[10010];
int main()
{
        int i,j,k,tot,ttl;
        scanf("%d",&tot);
        for(ttl=1;ttl<=tot;ttl++)
        {
            scanf("%d%d%d",&e,&r,&n);
            ma[n+1]=0;
            for(i=1;i<=n;i++)
                scanf("%d",&v[i]);
            for(i=n;i>=1;i--)
                ma[i]=max(ma[i+1],v[i]);
            long long ans=0,now=e;
            
            for(i=1;i<=n;i++)
            {
                if(ma[i]==v[i])
                    ans+=now*v[i],now=r;
                else
                {
                    now+=r;
                    if(now>e)
                        ans+=(now-e)*v[i],now=e;
                }
            }
            cout<<"Case #"<<ttl<<": "<<ans<<endl;
        }
        
        return 0;
}
