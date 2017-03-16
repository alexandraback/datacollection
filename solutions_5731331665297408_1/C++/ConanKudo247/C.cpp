#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define FOR(i,a,b) for(int i = (a); i <= (b);i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)

using namespace std;
#define maxn 100
int n,m;
string s[maxn];
int order[maxn],a[maxn];
pair<string,int> p[maxn];
bool c[maxn][maxn];

int top, st[maxn], ds[maxn], w[maxn], kq[maxn];
bool dd[maxn];

bool avail[maxn], save[maxn];
void dfs(int u) {
    avail[u] = false;
    FOR(v,1,n)
    if (avail[v] && c[u][v]) dfs(v);
}
bool possible(int x) {
    FOR(i,1,n) avail[i] = save[i];
    DOWN(i,top,1) {
        if (c[st[i]][x]) {
            FOR(j,1,i)
            if (avail[st[j]]) dfs(st[j]);
            dfs(x);
            FOR(j,1,n)
            if (avail[j]) {
                return false;
            }
            return true;
        }
        avail[st[i]] = false;
    }
}
void solve() {
    FOR(i,1,n) p[i] = make_pair(s[i],i);
    sort(p+1,p+n+1);
    FOR(i,1,n) ds[i] = p[i].second;
    FOR(i,1,n) w[ds[i]] = i;
    kq[1] = ds[1];
    top = 1;
    st[top] = ds[1];
    
    memset(dd,true,sizeof(dd));
    memset(save,true,sizeof(save));
    dd[ ds[1] ] = false;
    FOR(i,2,n) {
        vector<pair<int,int> > ls(0);
        FOR(j,1,top) {
            int u = st[j];
            FOR(v,1,n)
            if (dd[v] && c[u][v]) {
                ls.push_back( make_pair(w[v], v));
            }
        }
        sort(ls.begin(),ls.end());
        ls.resize( unique(ls.begin(),ls.end()) - ls.begin());
//        FR(j,ls.size()) cout << ls[j].second << " ";
  //      cout << endl;
        FR(j,ls.size()) {
            int cand = ls[j].second;
            if (possible(cand)) {
                kq[i] = cand;
                dd[cand] = false;
                while ((top > 0) && (!c[st[top]][cand])) {
                    save[st[top]] = false;
                    top--;
                }
                if (top == 0) {
                    cout << "FALSE" << endl;
                }
                st[++top] = cand;
                break;
            }
        }
    }
    FOR(i,1,n) cout << s[kq[i]];
    cout << endl;
}
int main() 
{
    freopen("C-large.in","r",stdin);
    freopen("C.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n >> m;
        FOR(i,1,n) cin >> s[i];
        memset(c,false,sizeof(c));
        int u,v;
        FOR(i,1,m) {
            cin >> u >> v;
            c[u][v] = true;
            c[v][u] = true;
        }
        solve();
    }
    return 0;
}
