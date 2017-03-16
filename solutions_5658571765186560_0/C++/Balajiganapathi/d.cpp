//Coder: Balajiganapathi
#ifndef ONLINE_JUDGE
#   define DEBUG
#   define TRACE
#else
//#   define NDEBUG
#endif

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;
typedef vector<pi> vpi;

// Basic macros
#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fo(i,n)     re(i,0,n)
#define rev(i,n,s)  for(int i=(n)-1;i>=s;--i)
#define repv(i,n,s) for(int i=(n);i>=s;--i)
#define fov(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define si(x)       (int)(x.size())

#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
    #define trace4(a,b,c,d)
    #define trace5(a,b,c,d,e)
    #define trace6(a,b,c,d,e,f)
#endif

const int oo = 1000000009;
const double eps = 1e-6;
const int mod = 1000000007;
const int mx = 20;

int r, c, x;
class XMino {
public:
    pi d[mx]; 
    int cnt;
    bool dirty;
    
    XMino() {
        cnt = 0;
        dirty = false;
    }
    XMino(const XMino &o) {
        cnt = o.cnt;
        fo(i, cnt) d[i] = o.d[i];
        dirty = o.dirty;
    }
    void add(int di, int dj) {
        d[cnt].fi = di;
        d[cnt].se = dj;
        ++cnt;
        dirty = true;
    }

    void soft_normalize() {
        if(!dirty) return;
        pi origin(oo, oo);
        fo(i, cnt) {
            origin.fi = min(origin.fi, d[i].fi);
            origin.se = min(origin.se, d[i].se);
        }
        fo(i, cnt) {
            d[i].fi -= origin.fi;
            d[i].se -= origin.se;
        }
        sort(d, d + cnt);
        fo(i, cnt) assert(d[i].fi >= 0 && d[i].se >= 0);
        dirty = false;
    }

    void rotate() {
        soft_normalize();
        pi bound(-oo, -oo);
        fo(i, cnt) {
            bound.fi = max(bound.fi, d[i].fi);
            bound.se = max(bound.se, d[i].se);
        }
        fo(i, cnt) {
            swap(d[i].fi, d[i].se);
            d[i].se = bound.fi - d[i].se;
        }
        dirty = true;
        soft_normalize();
    }

    void reflect_ver() {
        soft_normalize();
        pi bound(-oo, -oo);
        fo(i, cnt) {
            bound.fi = max(bound.fi, d[i].fi);
            bound.se = max(bound.se, d[i].se);
        }
        fo(i, cnt) {
            d[i].fi = bound.fi + -1 * d[i].fi;
        }
        dirty = true;
        soft_normalize();
    }

    void reflect_hor() {
        soft_normalize();   
        pi bound(-oo, -oo);
        fo(i, cnt) {
            bound.fi = max(bound.fi, d[i].fi);
            bound.se = max(bound.se, d[i].se);
        }
        fo(i, cnt) {
            d[i].se = bound.se + -1 * d[i].se;
        }
        dirty = true;
        soft_normalize();   
    }

    bool operator <(const XMino &xmino) const {
        if(cnt != xmino.cnt) return cnt < xmino.cnt;
        fo(i, cnt) if(d[i] != xmino.d[i]) return d[i] < xmino.d[i];
        return false;
    }

    void print() {
        soft_normalize();   
        fo(i, cnt) trace3(i, d[i].fi, d[i].se);
        char b[mx][mx];
        fo(i, x) {
            fo(j, x) b[i][j] = '.';
            b[i][x] = 0;
        }
        fo(i, cnt) b[d[i].fi][d[i].se] = '*';
        fo(i, cnt) printf("%s\n", b[i]);
        printf("\n");
    }

};

set<XMino> xminos, all_xminos;

int di[] = {0, 0, -1, 1}, dj[] = {-1, 1, 0, 0};
set<pi> cb;


bool exist(set<XMino> &xms, XMino cur) {
    fo(i, 4) {
        cur.rotate();
        fo(j, 2) {
            cur.reflect_ver();
            fo(k, 2) {
                cur.reflect_hor();
                if(xms.count(cur)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void add_inv(set<XMino> &xminos, XMino cur) {
    if(!exist(xminos, cur)) {
        cur.soft_normalize();
        xminos.insert(cur);
        //cur.print();
    }
}

void gen_xmino(XMino cur) {
    if(cur.cnt == x) {
        add_inv(xminos, cur);
        cur.soft_normalize();
        all_xminos.insert(cur);
        return;
    }

    fo(i, cur.cnt) {
        fo(d, 4) {
            XMino nw = cur;
            int ni = nw.d[i].fi + di[d];
            int nj = nw.d[i].se + dj[d];

            if(cb.count(mp(ni, nj)) == 0) {
                cb.insert(mp(ni, nj));
                nw.add(ni, nj);
                gen_xmino(nw);
                cb.erase(cb.find(mp(ni, nj)));
            }
        }
    }
}


set<XMino> pos;
map<XMino, int> cnt;

int b[mx][mx], vis[mx][mx], comp_cnt;

void dfs(int i, int j) {
    if(i < 0 || i >= r || j < 0 || j >= c || vis[i][j] || b[i][j] == 0) return;
    ++comp_cnt;
    vis[i][j] = 1;
    fo(d, 4) dfs(i + di[d], j + dj[d]);
}

bool still_possible() {
    ini(vis, 0);
    fo(i, r) fo(j, c) if(!vis[i][j] && b[i][j]) {
        comp_cnt = 0;
        dfs(i, j);
        if(comp_cnt % x != 0) return false;
    }
    return true;
}

bool can_place(int i, int j, XMino &nxt) {
    fo(k, x) {
        int ni = i + nxt.d[k].fi, nj = j + nxt.d[k].se;
        if(ni >= 0 && ni < r && nj >= 0 && nj < c && b[ni][nj] == 0) {
        } else {
            return false;
        }
    }

    return true;
}

void place(int i, int j, XMino &nxt, int pl) {
    fo(k, x) b[i + nxt.d[k].fi][j + nxt.d[k].se] = pl;
    if(pl) ++cnt[nxt];
    else --cnt[nxt];
}

bool brute(int i, int j) {
    if(i == r && j == 0) {
        return true;
    }
    if(j == c) {
        return brute(i + 1, 0);
    }
    if(b[i][j]) {
        return brute(i, j + 1);
    }

    //if(!still_possible()) return;

    for(auto nxt: all_xminos) {
        if(can_place(i, j, nxt)) {
            place(i, j, nxt, 1);
            if(brute(i, j + 1)) return true;
            place(i, j, nxt, 0);
        }
    }

    return false;
}

int possible() {
    XMino s;
    cb.clear();
    cb.insert(mp(0, 0));
    s.add(0, 0);
    xminos.clear();
    all_xminos.clear();

    gen_xmino(s);

    if(r * c % x != 0) return false;

    pos.clear();
    for(auto xm: all_xminos) if(!exist(pos, xm)) {
        ini(b, 0);
        bool ok = false;
        fo(i, r) {
            if(ok) break;
            fo(j, c) if(can_place(i, j, xm)) {
                if(ok) break;
                place(i, j, xm, 1);
                if(brute(0, 0)) {
                    add_inv(pos, xm);
                    ok = true;
                }
                place(i, j, xm, 0);
            }
        }
    }

    return si(pos) == si(xminos);
}


int main() {
    //freopen("sample.txt", "r", stdin);
    freopen("D-small-attempt0.in", "r", stdin);
    //freopen("D-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small0.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases;
    scanf("%d", &kases);
    for(int kase = 1; kase <= kases; ++kase) {
        scanf("%d %d %d", &x, &r, &c);
        trace4(kase, x, r, c);
        printf("Case #%d: %s\n", kase, (possible()? "GABRIEL": "RICHARD"));
    }
    
	return 0;
}
