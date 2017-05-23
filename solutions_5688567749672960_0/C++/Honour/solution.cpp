//Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>
using namespace std;

vector<long long>adj[1000009],vec;
long long dis[1000009],color[1000009];
queue<long long>Q;

long long rev(long long curr)
{
    long long i,j,k,l;
    vec.clear();
    i=curr;
    while(i)
    {
        vec.push_back(i%10);
        i/=10;
    }
    j=vec.size();
    k=0;
    for(i=0;i<j;i++)
    {
        k=k*10;
        k+=vec[i];
    }
    return k;
}

long long bfs(long long s,long long dest)
{
    while(!Q.empty()) Q.pop();
    long long a,d,f,g,h,j,k,l;
    Q.push(s);
    dis[s]=0;
    color[s]=1;
    while(!Q.empty())
    {
        d=Q.front();
        //cout<<d<<" ";
        Q.pop();
        for(a=0;a<adj[d].size();a++)
        {
            //cout<<adj[]
            if(color[adj[d][a]]==0)
            {
                color[adj[d][a]]=1;
                dis[adj[d][a]]=dis[d]+1;
                if(color[dest]) return dis[dest];
                Q.push(adj[d][a]);
            }
        }
    }
}

int  main()
{
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    long long i,j,k,T,S,ans,temp,cas=0,ans1,now,N;

    for(i=0;i<=1000000;i++)
    {
        adj[i].push_back(i+1);
        adj[i].push_back(rev(i));
        //cout<<i<<' '<<rev(i)<<endl;
    }
    cin>>T;
    while(T--)
    {
        cas++;

        cin>>N;
        memset(color,0,sizeof(color));
        ans=bfs(0,N);

        printf("Case #%lld: %lld\n",cas,ans);

    }

}
