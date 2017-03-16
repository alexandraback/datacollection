#include<bits/stdc++.h>
using namespace std;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#define bitcount    __builtin_popcountll
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d %d",&x,&y);
#define slld(x) scanf("%lld",&x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define ss(x) scanf("%s",x)
#define ll long long
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)
#define MOD 1000000007


int a[3000],b[3000],vis[3000];


int calc(int x,int n,int vis2[])
{
   // cerr<<x<<endl;

    int w=0;
    vis2[x]=1;
    for(int i=1;i<=n;i++)
    {
        if(vis2[i]==0&&a[i]==x)
        {
            w=max(w,calc(i,n,vis2));
        }
    }

    return w+1;

}







int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i;
    sd(t);

    for(int q=1;q<=t;q++)
    {
        int n;
        sd(n);
        for(i=1;i<=n;i++)
        {
            sd(a[i]);
            b[a[i]]=i;
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                vis[j]=0;

            int j=a[i];
            vis[j]=1;vis[i]=1;

            int k=2,m=0;
            int temp=i;
            //cerr<<i<<endl;
            while(j!=i)
            {
                k++;
                j=a[j];
                vis[j]=1;


                if(j==temp)
                {
                    int vis2[3000];
                    for(int y=1;y<=n;y++)
                    {
                        vis2[y]=vis[y];
                    }
                    ans=max(ans,k-2+calc(a[j],n,vis2));
                    m=1;
                    break;
                }
                temp=b[j];


                if(k>n+2)
                {
                    m=1;
                    break;
                }
            }
            if(m==0)
                ans=max(ans,k-1);
            //cerr<<k<<endl;
        }
        printf("Case #%d: %d\n",q,ans);








    }
}


