#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define min(a,b) ( a < b ? a : b )
#define max(a,b) ( a > b ? a : b )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
typedef long long ll;
using namespace std;


int use[1001][1001];
int can[1001];
int in[1001];
vector<int> edge[1001];
vector<int> sp[1001];
int result;
map<int, int> umap;

void go(int now, int root, int deep) {
    int i, j, k;
    rep(i, edge[now].size()) {
        j = edge[now][i];
        if (j == root) { result = max(result, deep); }
        if (can[j]) {
            can[j] = false;
            go(j, root, deep+1);
            can[j] = true;
        }
    }
}

int gox(int now, int root) {
    int i, x, ans(0);
    rep(i, sp[now].size()) {
        x = sp[now][i];
        if (x == root) { continue; }
        ans = max(ans, gox(x, root));
    }
    return ans + 1;
}

pair<int, pair<int, int> > gosp(int root) {
    int i, j, k, x, y;
    int ans1(0), ans2(0);
    x = in[root-1];
    if (in[x-1] != root) { return {0, {0, 0}}; }
    ans1 = gox(x, root);
    rep(i, sp[root].size()) {
        y = sp[root][i];
        if (y != x) {
            ans2 = max(ans2, gox(y, root));
        }
    }
    return {ans1 + ans2 + 1, {root, x}};
}

int main() {
    int tt, t, n, i, j, k;
    cin >> tt;
    xrep(t, 1, tt+1) {
        scanf("%d", &n);
        memset(in, 0, sizeof(in));
        rep(i, n) { scanf("%d", &in[i]); }
        rep(i, n+1) {
            edge[i].clear();
            sp[i].clear();
        }
        memset(use, 0, sizeof(use));
        rep(i, n) {
            int x = i+1;
            int y = in[i];
            sp[y].push_back(x);
            if (!use[x][y]) {
                use[x][y] = use[y][x] = 1;
                edge[x].push_back(y);
                edge[y].push_back(x);
            }
        }
        result = min(n, 2);
        memset(can, 1, sizeof(can));
        xrep(i ,1 , n+1) {
            can[i] = 0;
            go(i, i, 1);
            can[i] = 1;
        }
        vector<int> gosps;
        umap.clear();
        xrep(i, 1, n+1) {
            if (!umap[i]) {
                pair<int, pair<int, int> > tmp = gosp(i);
                umap[tmp.second.first] = 1;
                umap[tmp.second.second] = 1;
                gosps.push_back(tmp.first);
            }
        }
        int w(0);
        rep(i, gosps.size()) { w += gosps[i]; }
        result = max(result, w);
        cout << "Case #" << t << ": " << result << endl;
    }
}
