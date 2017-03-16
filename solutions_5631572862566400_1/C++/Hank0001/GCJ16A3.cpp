#include<bits/stdc++.h>
using namespace std;
int graph[1005];
int vis[1005];
int dep[1005];
vector<int> rev[1005];
typedef pair<int,int> pii;
#define f first
#define s second
int dfs(int me,int d,int&crc)
{
    if(vis[me]==2) return 0;
    if(vis[me]==1){
        vis[me]=2;
        crc=me;
        return d-dep[me];
    }
    vis[me]=1;
    dep[me]=d;
    int r=dfs(graph[me],d+1,crc);
    vis[me]=2;
    return r;
}
int far(int me,int p=-1)
{
    int a=0,b=0,t=0;
    for(int to:rev[me]){
        if(to==p) continue;
        t=far(to)+1;
        a=max(t,a);
    }
    if(p>-1){
        for(int to:rev[p]){
            if(to==me) continue;
            t=far(to)+1;
            b=max(t,b);
        }
        a=a+b;
    }
    return a;
}
main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);


    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        printf("Case #%d: ",kase);
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) rev[i].clear();
        for(int i=0;i<n;i++){
            scanf("%d",&graph[i]);
            graph[i]--;
            rev[graph[i]].push_back(i);
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        int spans=0;
        vector<int> two;
        for(int i=0;i<n;i++){
            int crc;
            int tmp=dfs(i,0,crc);
            if(tmp==2){
                two.push_back(crc);
            }
            else{
                ans=max(ans,tmp);
            }
        }
        for(int x:two){
            spans+=far(x,graph[x])+2;
        }
        printf("%d\n",max(ans,spans));
    }
}
