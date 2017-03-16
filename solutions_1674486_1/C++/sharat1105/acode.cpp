#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<list>
using namespace std;

#define PI pair<int,int>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>

#define LIM 1<<10

bool vis[LIM];
VVI v;
int N,M,inp;
bool found;

void dfs(int x)
{
    if(found) return ;
    for(int i=0;i<v[x].size();i++){
        if(!vis[v[x][i]]){
            vis[v[x][i]]=true;
            dfs(v[x][i]);
        }
        else{
            found=true;
            return ;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int tt=1;tt<=cases;tt++){
        scanf("%d",&N);
        v.clear();
        v.resize(N+1);
        for(int i=1;i<=N;i++){
            scanf("%d",&M);
            for(int j=0;j<M;j++){
                scanf("%d",&inp);
                v[i].PB(inp);
            }
        }
        found=false;
        for(int i=1;i<=N && !found;i++){
            memset(vis,false,N+1);
            vis[i]=true;
            dfs(i);
        }
        printf("Case #%d: ",tt);
        if(found){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
