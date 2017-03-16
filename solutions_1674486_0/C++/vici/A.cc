#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define maxn 1010
#define maxm 1001000

using namespace std;
struct edges{
   int u,next;
}e[maxm];
int p[maxn], idx;
//addedge
void addedge(int u,int v){
    e[idx].u=v;
    e[idx].next=p[u];
    p[u]=idx++;
}
void init(){
    idx = 0;
    memset(p, 0xff, sizeof(p));
}
int n;

bool used[maxn];
bool dfs(int u){
    used[u] = true;
    for(int i=p[u];i!=-1;i=e[i].next){
        if(used[e[i].u]) return true;
        else{
            if(dfs(e[i].u)) return true;
        }
    }
    return false;
}

int main(){
    freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-ans.txt", "w", stdout);
  //  freopen("A-large.in", "r", stdin);  freopen("A-large-ans.txt", "w", stdout);
    int test_case;
    scanf("%d", &test_case);


    int m, a;

    for(int _t = 1; _t <= test_case; _t++){
        scanf("%d", &n);
        init();
        for(int i=1;i<=n;i++){
            scanf("%d", &m);
            for(int j=0;j<m;j++){
                scanf("%d", &a);
                addedge(i, a);
            }
        }
        bool flag = false;
        for(int i=1;i<=n;i++){
            memset(used, false, sizeof(used));
            if(dfs(i)) {flag = true; break;}
        }
        printf("Case #%d:", _t);
        if(flag) puts(" Yes");
        else puts(" No");
    }
    return 0;
}
