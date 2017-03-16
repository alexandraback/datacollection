#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> in;
vector<bool> vis;
int n;
void init(){
    scanf("%d",&n);
    adj.assign(n+1,vector<int>());
    in.assign(n+1,true);
    int x,y;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        for(int j = 0; j < x; j++)
        {
            scanf("%d",&y);
            adj[i].push_back(y);
            in[y] = false;
        }
    }
}
bool f(int x){
    if(vis[x]) return true;
    vis[x] = true;
    for(int i = 0,y; i < adj[x].size(); i++)
    {
        y = adj[x][i];
        if(f(y)) return true;
    }
    return false;
}
bool dfs(){
    for(int i = 1; i <= n; i++)
    {
        if(in[i]){
            vis.assign(n+1,false);
            if(f(i))
                    return true;
        }
    }
    return false;
}

int main()
{

    freopen("re.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    int t,cas=1;  
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",cas++);
        init();
        if(dfs())
        printf("Yes\n");
        else 
        printf("No\n");
    }

}

