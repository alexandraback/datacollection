
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 1e3+10;
int ia[MAXN];
int n, ans;
bool used[MAXN];

void dfs(int root, int pre, int cur, int cnt);

int main(){
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int icase;
    scanf("%d", &icase);

    for(int k=1; k<=icase; ++k){
        ans = 1;
        scanf("%d",&n);
        memset(ia, 0, sizeof(ia));

        for(int i=1; i<=n; ++i){
            scanf("%d", &ia[i]);
        }

        for(int i=1; i<=n; ++i){
            memset(used, false, sizeof(used));
            used[i] = true;
            dfs(i, -1, i, 1);
            used[i] = false;
        }
        printf("Case #%d: %d\n", k, ans);
    }

    return 0;
}

void dfs(int root, int pre, int cur, int cnt){
    if(ia[cur] == pre || ia[cur] == root){
        if(cnt > ans) {
            ans = cnt;
        }
    }

    if(pre == ia[cur]){
        for(int i=1; i<=n; ++i){
            if(!used[i])
            {
                used[i] = true;
                dfs(root, cur, i, cnt+1);
                used[i] = false;
            }
        }
    }
    int ib = ia[cur];
    if(!used[ib]){
        used[ib] = true;
        dfs(root, cur, ib, cnt+1);
        used[ib] = false;
    }
}
/*
 1->2->3->4->1

 1->3->4->1
 2->3->4->1->3

 1->3->4->3
 2->3->4->3

 2->8->6->2
 1->7->9->3<->10<-4
*/
