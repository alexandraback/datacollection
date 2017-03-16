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
const int N = 100;

vector<vector<int> > adj;
vector<bool> in;
vector<bool> vis;
int n;
void init(){
    scanf("%d",&n);
    adj.assign(n+1,vector<int>());
    in.assign(n+1,true);
    int x,y;
    for(int i = 1; i <= n; i++){
        scanf("%d",&x);
        for(int j = 0; j < x; j++){
            scanf("%d",&y);
            adj[i].push_back(y);
            in[y] = false;
        }
    }
}
bool gao2(int x){
    if(vis[x]) return true;
    vis[x] = true;
    for(int i = 0,y; i < adj[x].size(); i++){
        y = adj[x][i];
        if(gao2(y)) return true;
    }
    return false;
}
bool gao(){
    for(int i = 1; i <= n; i++){
        if(in[i]){
//            cout<<i<<endl;
            vis.assign(n+1,false);
            if(gao2(i))
                    return true;
        }
    }
    return false;
}

int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,cas;
    
    scanf("%d",&t);cas = 0;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        init();
        if(gao()) puts("Yes");
        else puts("No");
    }

}
