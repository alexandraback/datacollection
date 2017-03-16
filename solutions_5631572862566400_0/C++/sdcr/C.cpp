#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define ri(X) scanf("%d", &(X))
#define rii(X, Y) scanf("%d%d", &(X), &(Y))
#define riii(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define all(a) (a).begin(),(a).end()
#define sz(s) ((int) ((s).size()))
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornr(i, n) for (int i = (int)(n)-1; i>=0; --i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define for1r(i, n) for (int i = (int)(n); i>0; --i)

#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

int mod1 = int(1e9) + 7;

#define MX 100100

int edg[1010];
vi redg[1010];
int vis[1010];

int curans;

void dfs(int r, int v, int d) {

    if(vis[v]==1) {
        if(r==v) {
            curans = d;
        } 
        return;
    }

    vis[v] = 1;
    dfs(r,edg[v],d+1);

}

int rlen(int v, int ex) {
    if(redg[v].size()==0)
        return 1;
    else {
        int mx = 0;
        forn(j,redg[v].size()) {
            if(redg[v][j]==ex) continue;
            mx = max(mx, rlen(redg[v][j], 0));
        }
        return mx + 1;
    }
}

void main2(){

    int n;
    ri(n);

    curans = -1;

    memset(edg,0,sizeof(edg));
    memset(redg,0,sizeof(redg));
    memset(vis,0,sizeof(vis));

    for1(i,n) {
        ri(edg[i]);
        redg[edg[i]].pb(i);
    }

    int ans = -1;


    for1(i,n) {
        memset(vis,0,sizeof(vis));
        curans = -1;
        dfs(i,i,0);
        ans = max(ans,curans);
    }


    memset(vis,0,sizeof(vis));
    curans = 0;
    for1(i,n) {
        if(vis[i]) continue;
        if(edg[edg[i]] == i) {
            vis[i] = vis[edg[i]] = 1;

            curans += rlen(i,edg[i]);
            curans += rlen(edg[i],i);
        }
    }
    ans = max(ans, curans);


    printf("%d\n", ans);

}


int main(){

    int t;
    ri(t);

    for1(cas,t) {
        printf("Case #%d: ", cas);
        main2();
    }

    return 0;
}
