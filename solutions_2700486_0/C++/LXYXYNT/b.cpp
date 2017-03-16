#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <sstream>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;

const int dx[8]={1,0,-1,0,-1,-1,1,1};
const int dy[8]={0,1,0,-1,1,-1,1,-1};
const int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool bi[111][111];
double ans;
int n,x,y;

pair<int,int> sim(int x,int y){
    while (y && (bi[x-1][y-1] || bi[x+1][y-1])){
        if (bi[x-1][y-1]) x--;
        else x++;
        y--;
    }
    return make_pair(x,y);
}   

void dfs(int deep,double k){
    if (deep==n){
        if (!bi[x+100][y]) ans+=k;
        return;
    }
    int nowx=100,nowy=20;
    while (bi[100][nowy-2]) nowy--;

    if (!bi[nowx-1][nowy-1] && !bi[nowx+1][nowy-1]){ 
        bi[nowx][nowy]=false;
        dfs(deep+1,k);
        bi[nowx][nowy]=true;
        return;
    }

    while (true){
        if (nowy==0 || (!bi[nowx-1][nowy-1] && !bi[nowx+1][nowy-1])){ 
            bi[nowx][nowy]=false;
            dfs(deep+1,k);
            bi[nowx][nowy]=true;            
            return;
        }
    
        if (bi[nowx-1][nowy-1] && bi[nowx+1][nowy-1]){
            pair<int,int> t;
            t=sim(nowx-1,nowy-1);
            bi[t.first][t.second]=false;
            dfs(deep+1,k*0.5);
            bi[t.first][t.second]=true;
            
            t=sim(nowx+1,nowy-1);
            bi[t.first][t.second]=false;
            dfs(deep+1,k*0.5);
            bi[t.first][t.second]=true;
            return;
        }
        
        if (bi[nowx-1][nowy-1]) nowx--;
        else nowx++;
        nowy--;
    }
}

int main(){
    freopen("b.in","r",stdin);
    
    int _,cas=0;
    scanf("%d",&_);
    while (_--){
        scanf("%d%d%d",&n,&x,&y);
//        printf("--%d %d %d\n",n,x,y);
        if (x>50 || y>50 || x<-50){
            printf("Case #%d: %.10f\n",++cas,0);            
            continue;
        }
        ans=0;
        memset(bi,true,sizeof(bi));
        bi[100][0]=false;
        dfs(1,1);
        printf("Case #%d: %.10f\n",++cas,ans);
    }
    return 0;
}
