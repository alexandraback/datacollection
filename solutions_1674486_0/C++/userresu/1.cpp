#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int N;
vector<vector<int> > con(1001),con2(1001);
bool fin,vis[1001];

void start (int i) {
     if (fin) return;
     for (int j=0;j<con[i].size();++j) {
         int x=con[i][j];
         if (x==i) {
            fin=1;
            return;
         }
         if (vis[x]) continue;
         vis[x]=1;
         start(x);
     }
}

int s;
int solve (int i) {
     if (fin) return 1;
     if (i==s) return 1;
     int on=0;
     for (int j=0;j<con2[i].size();++j) {
         int x=con2[i][j];
         if (solve(x)) ++on;
         if (on>1) {
            fin=1;
            return 1;
         }
     }
     if (on==1) return 1;
     else return 0;
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    scanf("%d",&N);
    fin=0;
    for (int i=1;i<=N;++i) con[i].clear(),con2[i].clear();
    int x,y;
    for (int i=1;i<=N;++i) {
        scanf("%d",&x);
        while (x--) {
              scanf("%d",&y);
              con[i].push_back(y);
              con2[y].push_back(i);
        }
    }
    for (int i=1;i<=N;++i) {
        for (int j=1;j<=N;++j) vis[j]=0;
        vis[i]=1;
        start(i);
        if (fin) break;
    }
    printf("Case #%d: ",z);
    if (fin) {
       printf("Yes\n");
    }
    else {
         for (int i=1;i<=N;++i) {
             s=i;
             for (int j=1;j<=N;++j) vis[j]=0;
             for (int j=1;j<=N;++j) solve(j);
             if (fin) break;
         }
         if (fin) printf("Yes\n");
         else printf("No\n");
    }
    }
    return 0;
}
