#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>

#define N 50
using namespace std;

int DEBUG = 0;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }


int a[N][N];
int vis[N];
int path[N], zip[N], ans[N];

int n,m; 
bool hasAns;

int compare() {
    bool smaller = !hasAns;
    
    if (DEBUG) {
    for (int i=0;i<n;i++) {
        printf("%d", zip[path[i]]);
    }
    puts("");
    }

    for (int i=0;i<n && !smaller;i++) {
        if (zip[path[i]] < zip[ans[i]]) {
            smaller = true;
        } else if (zip[path[i]] > zip[ans[i]]) {
            break;
        }
    }
    if (smaller) {
        for (int i=0;i<n;i++) ans[i] = path[i];
        hasAns = true;
    }
    return 0;
}

int walk(int u, int par, int x) {
    if (DEBUG) {
        printf("walk %d %d\n", u, x);
    }
    if (x == n) {
        compare();
        return 0;
    }

    for (int i=0;i<n;i++) {
        if (a[u][i]) {
            a[u][i] = 0;
            if (!vis[i]) {
                path[x] = i;
                walk(i, u, x+1);
            }else {
                walk(i, u, x);
            }
            a[u][i] = 1;
        }
    }
    return 0;
}


int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        hasAns = false;
        scanf("%d%d", &n, &m);

        int t, x, y;
        
        int start = 0;

        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (int i=0;i<n;i++) {
            scanf("%d", &zip[i]);
            if (zip[i] < zip[start]) start = i;
        }
        for (int i=0;i<m;i++) {
            scanf("%d%d", &x, &y);
            x--; y--;
            a[x][y] = a[y][x] = 1;
        }

        if (DEBUG){
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++) printf("%d", a[i][j]); puts("");
            }
        }

        vis[start] = true;
        path[0] = start;
        walk(start, -1, 1);


        printf("Case #%d: ",ti);
        for (int i=0;i<n;i++)printf("%d", zip[ans[i]]);
        puts("");
    }
    return 0;
}
