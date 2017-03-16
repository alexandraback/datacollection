#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<ctime>
#include<iomanip>
#include<fstream>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define sz(a) int((a).size())
#define pb push_back
const int INF = 2147483647;
const double PI = 3.141592653589793;
const int N = 1005;

int z,q,n,i,k,j,L[N][N],vis[N],ok,a,w;
VI graf[N],wek;

void dfs (int w) {
     vis[w]=1;
     for (int i=0;i<graf[w].size();i++) if (!vis[graf[w][i]]) dfs(graf[w][i]);
     wek.pb(w);
}

int main () {
scanf ("%d",&z);
for (q=1;q<=z;q++) {
    scanf ("%d",&n);
    //printf("%d\n",n);
    for (i=0;i<n;i++) {
        graf[i].resize(0);
        scanf ("%d",&k);
        //printf("%d ",k);
        while (k--) {
              scanf ("%d",&a);
              //printf("%d ",a);
              graf[i].pb(a-1);
        }
        vis[i]=0;
        //printf("\n");
    }
    wek.resize(0);
    for (i=0;i<n;i++) if (vis[i]==0) dfs(i);
    ok=0;
    //for (i=0;i<n;i++) printf("%d ",wek[i]+1); printf("%\n");
    
    /*for (i=0;i<n;i++) vis[i]=0;
    for (i=0;i<n;i++) {
        w=wek[i];
        vis[w]=1;
        for (j=0;j<graf[w].size();j++) if (vis[graf[w][j]]==0) printf("UWAGA %d %d\n",w+1,graf[w][j]+1);
    }*/
    
    for (i=0;i<n;i++) for (j=0;j<n;j++) L[i][j]=0;
    for (i=0;i<n && ok==0;i++) {
        w=wek[i];
        //printf(" %d\n",w+1);
        L[w][w]=1;
        for (j=0;j<i;j++) {
            L[w][wek[j]]=0;
            for (k=0;k<graf[w].size();k++) L[w][wek[j]]+=L[graf[w][k]][wek[j]];
            if (L[w][wek[j]]>1) ok=1;
            //printf("%d %d %d\n",w+1,wek[j]+1,L[w][wek[j]]);
        }
    }
    if (ok==1) printf("Case #%d: Yes\n",q); else printf("Case #%d: No\n",q);
}
return 0;
}
