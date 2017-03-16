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
#define inf 0x7fffffff
using namespace std;
#define N 200

vector<vector<int> > adj;
vector<bool> in;
vector<bool> visit;
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
bool method2(int x){
    if(visit[x]) return true;
    visit[x] = true;
    for(int i = 0,y; i < adj[x].size(); i++){
        y = adj[x][i];
        if(method2(y)) return true;
    }
    return false;
}
bool method(){
    for(int i = 1; i <= n; i++){
        if(in[i]){
//            cout<<i<<endl;
            visit.assign(n+1,false);
            if(method2(i))
                    return true;
        }
    }
    return false;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    int nCase,ca;
    
    scanf("%d",&nCase);ca= 0;
    while(nCase--)
    {
      
        init();
	    printf("Case #%d: ",++ca);
       
        if(method())printf("Yes\n");
        else printf("No\n");
    }

}

