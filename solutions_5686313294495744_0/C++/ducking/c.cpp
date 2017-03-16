#include <stdio.h>

#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

const int N = 2020;
const int G = 1010;

int lt[N], hd[N], nxt[N], cor[N], use[N], lst;
int mat[N];

int n;
map<string, int> maps[2]; 
int mapcnts[2];
string link[N][2];
int vis[N];

int dfs(int u, int fl) {
    vis[u] = 1;
    if (!mat[u]) {
        //ok!
        mat[u] = 1;
        use[fl] = 1;
        use[cor[fl]] = 1;
        return 1;
    }
    for (int l=hd[u]; l; l=nxt[l]) {
        if (!vis[lt[l]]) {
            if (use[fl]^use[l]) {
                if (dfs(lt[l], l)) {
                    // found by fl -> l
                    swap(use[fl], use[l]);
                    swap(use[cor[fl]], use[cor[l]]);
                }
            }
        }
    }
    return 0;
}
int find(int u) {
    for (int i=0; i<N; i++)
        vis[i] = 0;
    vis[u] = 1;
    int cnt = 0;
    for (int l=hd[u]; l; l=nxt[l])
        if (!mat[u]) {
            if (dfs(lt[l], l)) {
                mat[u] = 1;
                use[l] = 1;
                use[cor[l]] = 1;
                cnt++;
            }
        }
    return cnt;
}

void init() {
    for (int i=0; i<N; i++)
        hd[i] = mat[i] = use[i] = 0;
}
int if_use(int u, int v) {
    if (!mat[u] || !mat[v]) return 0;
    for (int l=hd[u]; l; l=nxt[l])
       if (lt[l]==v)
           return !use[l];
    return 0;
}
int main () {
    int t, u, v;
    string s1, s2;
    scanf("%d", &t);
    for (int c=1; c<=t; c++) {
        scanf("%d", &n);
        lst = 1;
        init();
        maps[0]=map<string, int>();
        maps[1]=map<string, int>();
        mapcnts[0] = mapcnts[1] = 0;
        for (int i=0; i<n; i++) {
            cin>>s1>>s2;
            link[i][0]=s1; link[i][1]=s2;
            if (maps[0].find(s1)==maps[0].end())
                maps[0][s1] = mapcnts[0]++;
            if (maps[1].find(s2)==maps[1].end())
                maps[1][s2] = (mapcnts[1]++) + G;
            u = maps[0][s1];
            v = maps[1][s2];
            lt[lst]=v; nxt[lst]=hd[u]; cor[lst]=lst+1; hd[u]=lst++;
            lt[lst]=u; nxt[lst]=hd[v]; cor[lst]=lst-1; hd[v]=lst++;
        }
        int sum=0;
        for (int i=0; i<maps[0].size(); i++)
            sum += find(i);
        sum = 0;
        for (int i=0; i<n; i++) {
            sum += if_use( maps[0][link[i][0]], maps[1][link[i][1]] );
        }
        printf("Case #%d: %d\n", c, sum);
    }
    
}
