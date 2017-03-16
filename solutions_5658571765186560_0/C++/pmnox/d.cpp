#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,b) for(auto i=(0);i<(b);++i)
#define fo(i,a,b) for(auto i=(a);i<=(b);++i)
#define ford(i,a,b) for(auto i=(a);i>=(b);--i)
#define fore(a,b) for(auto a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

#define vpp vector<pair<int, int>>

set<vpp> checked;
int X, R, C;

int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int used[30][30];
int check2[30][30];
int ile_prew = 0;

int dfs_count(int yy, int xx) {
    if (used[yy][xx] == 1) return 0;
    if (check2[yy][xx] == 1) return 0;
    check2[yy][xx] = 1;
    int cnt = 1;

    rep (d, 4) {
        int ny = dy[d] + yy;
        int nx = dx[d] + xx;
        if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
            cnt += dfs_count(ny, nx);
        }
    }
    return cnt;
}

bool richard = 0;
map<vpp, bool> can;

void go(vpp w) {
    sort(all(w));
    if (checked.count(w)) return;
    checked.insert(w);
    if (int(w.size()) == X) {
        int minx = 1000, maxx = 0;
        int miny = 1000, maxy = 0;

        rep (p, int(w.size())) {
            minx = min(minx, w[p].first);
            maxx = max(maxx, w[p].first);
            miny = min(miny, w[p].second);
            maxy = max(maxy, w[p].second);
        }
        rep (p, int(w.size())) {
            w[p].first -= minx;
            w[p].second -= miny;
        }
        sort(all(w));
        vpp w2 = w;
        rep (p, int(w.size())) {
            swap(w2[p].first, w2[p].second);
        }
        sort(all(w2));

        can[w] = can[w];
        can[w2] = can[w2];

        ile_prew++;
        rep (yy, R)
            rep (xx, C)
                check2[yy][xx] = 0;
        bool ok = 1;
        rep (yy, R)
            rep (xx, C)
                if (dfs_count(yy, xx) % X) {
                    ok = false;
                }
        if (ok) {
            can[w] = true;
            can[w2] = true;
        }
        return;
    }

    rep (p, int(w.size())) {
        for (int d = 0; d < 4; d++) {
            int nx = w[p].first + dx[d];
            int ny = w[p].second + dy[d];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
                if (used[ny][nx]) continue;
                used[ny][nx] = 1;
                w.push_back(make_pair(nx, ny));
                go(w);
                w.pop_back();
                used[ny][nx] = 0;
            }
        }
    }
}

void solve() {
    scanf("%d%d%d", &X, &R, &C);
    if ((R * C) % X || X >= 7) {
        printf("RICHARD");
        return;
    }
    for (int a = 1; a <= X; a++) {
        int b = X - a + 1;
        if ((R >= a && C >= b) || (R >= b && C >= a)) {

        }
        else {
            printf("RICHARD");
            return;
        }
    }

    richard = false;
    checked.clear();
    can.clear();
    ile_prew = 0;
    memset(used, 0, sizeof(used));
    rep (yy, R)
        rep (xx, C) {
            vpp w;
            used[yy][xx] = 1;
            w.push_back(make_pair(xx, yy));
            go(w);
            used[yy][xx] = 0;
        }
    bool hmm = 0;
    fore (it, can) {
        if (!it->second) {
            hmm = true;
            break;
        }
    }

    if (hmm)
        printf("RICHARD");
    else
        printf("GABRIEL");
}

int main(int argc, char ** argv) {
    ios::sync_with_stdio(false);

    //  freopen("../1.in","r",stdin);
    //  freopen("../2.in","r",stdin);
    //  freopen("../3.in","r",stdin);
    //  freopen("../A-small.in","r",stdin); freopen("../A-small.out","w",stdout);
    //  freopen("../A-small-attempt0.in","r",stdin);freopen("../A-small-attempt0.out","w",stdout);
    //  freopen("../A-small-attempt1.in","r",stdin);freopen("../A-small-attempt1.out","w",stdout);
    //  freopen("../A-small-attempt2.in","r",stdin);freopen("../A-small-attempt2.out","w",stdout);
    //  freopen("../A-large.in","r",stdin); freopen("../A-large.out","w",stdout);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}
