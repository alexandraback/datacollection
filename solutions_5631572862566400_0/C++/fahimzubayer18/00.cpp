#include <bits/stdc++.h>
#define ll long long
using namespace std;

int g[1002];
int col[1002];
int N;
int cnt;
int in[1002];
int out[1002];
int rel[12][12];

void dfs(int i)
{
    col[i]=1;
    cnt++;
    cout<<i<<" ";
    if(col[ g[i] ]) return;
    dfs(g[i]);
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);


    int a,b,c,d,e,x,y,z,n,m;

    int t;
    scanf("%d",&t);

    for(int te=1;te<=t;te++)
    {
        printf("Case #%d: ",te);


        scanf("%d",&N);

        for(a=1;a<=N;a++)
        {
            g[a]=0;
            col[a]=0;
            in[a]=0;
            out[a]=0;
            for(b=1;b<=N;b++)
            {
                rel[a][b]=0;
            }
        }

        for(a=1;a<=N;a++)
        {
            scanf("%d",&g[a]);
            rel[a][g[a]]=true;
        }
        int ans=0;
        vector<int>v;
        v.clear();
        for(a=1;a<=N;a++) v.push_back(a);
        do
        {
            g[0]=v[0];
            for(a=1;a<N;a++)
            {
                g[a]=v[a];
                x=a+1;
                y=0;
                if(ans>=x) continue;
                for(b=0;b<x;b++)
                {
                    if(rel[ g[b] ][ g[(b+1)%x] ]) y++;
                    if(rel[ g[b] ][ g[(b-1+x)%x]]) y++;
                }
                if(y==x) ans=max(ans,x);
                //else break;
            }

        }while(next_permutation(v.begin(),v.end()));

        printf("%d\n",ans);
    }

    return 0;
}
