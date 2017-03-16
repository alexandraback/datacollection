#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 1000000

typedef long long ll;


int dis[10000006],v[10000006];

int rev(int x)
{
    int ret=0;
    while(x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}

void bfs()
{
    memset(v,0,sizeof(v));
    dis[1]=1;v[1]=1;
    queue<int> q;
    q.push(1);
    //int it=0;
    while(!q.empty())
    {
        //it++;
        int u=q.front();
        q.pop();
        //if(it>2000000) cout<<it<<endl;
        if(u+1<=MAX && !v[u+1] )
        {
            v[u+1]=1;
            dis[u+1]=dis[u]+1;
            q.push(u+1);
        }
        int x=rev(u);
        if(x<=MAX && !v[x] )
        {
            v[x]=1;
            dis[x]=dis[u]+1;
            q.push(x);
        }

    }
}
int main()
{
    //cout<<"ok";
    bfs();
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,cs=1;
    cin>>t;
    while(t--)
    {
        int a;cin>>a;
        printf("Case #%d: %d\n",cs++,dis[a]);
    }
    return 0;
}
