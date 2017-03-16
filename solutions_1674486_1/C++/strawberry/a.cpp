#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> > route;
vector<bool> in;
vector<bool> vis;
int n;

void initialization(){
    scanf("%d",&n);
    route.assign(n+1,vector<int>());
    in.assign(n+1,1);
    int x,y,i,j;
    for(i = 1; i <= n; i++){
        scanf("%d",&x);
        for(j = 0; j < x; j++){
            scanf("%d",&y);
            route[i].push_back(y);
            in[y] = 0;
        }
    }
}

bool work(int x){
    int i,y;
    if(vis[x]) 
        return 1;
    vis[x] = 1;
    for(i = 0; i < route[x].size(); i++){
        y = route[x][i];
        if(work(y))
            return 1;
    }
    return 0;
}

bool solve(){
    int i;
    for(i = 1; i <= n; i++){
        if(in[i]){
            vis.assign(n+1,0);
            if(work(i))
                return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int c,cas;
    scanf("%d",&cas);;
    for(c=1;c<=cas;c++){
        initialization();
        printf("Case #%d: ",c);
        if(solve())
            printf("Yes\n");
        else printf("No\n");
    }

}
