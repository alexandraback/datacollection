#include <bits/stdc++.h>
#define ll long long
using namespace std;

int g[1002];
int col[1002];
int cy[1002];
int dis[1002][1002];
int mx[1002];
int N;
int r;
int cnt;
int in[1002];
vector<int>v[1002];

void dfs(int i)
{
    col[i]=1;
    dis[r][i]=cnt;
    mx[i]=max(mx[i],cnt);
    cnt++;
    if(!col[ g[i] ]) dfs(g[i]);
    else
    {
        if(g[i]==r) cy[r]=max(cy[r],dis[r][i]+1);
    }
}

void ddfs(int i,int d)
{
    col[i]=d;
    cnt=max(cnt,d);
    for(int a=0;a<v[i].size();a++)
    {
        if(col[ v[i][a] ]) continue;
        ddfs(v[i][a],d+1);
    }
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("00.out","w",stdout);


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
            cy[a]=0;
            mx[a]=0;
            in[a]=0;
            v[a].clear();
            for(b=1;b<=N;b++)
            {
                dis[a][b]=0;
            }
        }
        for(a=1;a<=N;a++)
        {
            scanf("%d",&g[a]);
            v[ g[a] ].push_back(a);
            in[ g[a] ]++;
        }

        for(a=1;a<=N;a++)
        {
            for(b=1;b<=N;b++) col[b]=0;
            r=a;
            cnt=0;
            dfs(a);
        }

        for(a=1;a<=N;a++)
        {
            for(b=1;b<=N;b++) col[b]=0;
            r=a;
            cnt=0;
            ddfs(a,1);
        }

        int ans=0;
        for(a=1;a<=N;a++)
        {
            //cout<<"From "<<a<<endl;
            //cout<<"Cycle length "<<cy[a]<<endl;
            //cout<<"max in "<<mx[a]<<endl;
            if(cy[a]>2) ans=max(ans,cy[a]);
        }

        y=0;
        for(a=1;a<=N;a++)
        {
            if(cy[a]==2)
            {
                for(b=1;b<=N;b++) col[b]=0;
                col[ a ]=1;
                col[ g[a] ]=1;
                cnt=0;
                ddfs(a,1);
                y=y+cnt;
                //cout<<"Cycle "<<a<<" "<<g[a]<<endl;
            }
        }
        ans=max(ans,y);
        printf("%d\n",ans);
    }

    return 0;
}
