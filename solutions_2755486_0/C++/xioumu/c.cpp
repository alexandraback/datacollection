/*
 * Author:  xioumu
 * Created Time:  2013/5/12 18:34:05
 * File Name: c.cpp
 * solve: c.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clr(x) memset(x,0,sizeof(x))
#define clrs( x , y ) memset(x,y,sizeof(x))
#define out(x) printf(#x" %d\n", x)
#define sqr(x) ((x) * (x))
typedef long long lint;

const int maxint = -1u>>1;
const double eps = 1e-8;
const int maxh = 2000 + 10;
const int midh = 1000;

int sgn(const double &x) {  return (x > eps) - (x < -eps); }

struct node {
    int d, w, e, s;
    node (int _d = 0, int _w = 0, int _e = 0, int _s = 0):
          d(_d), w(_w), e(_e), s(_s){}
    bool operator < (const node &b) const {
        return d < b.d;
    }
};

int n;
vector<node> att;

void init() {
    scanf("%d", &n);
    att.clear();
    while (n--) {
        int di, ni, wi, ei, si, de_di, de_pi, de_si;
        scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &de_di, &de_pi, &de_si);
        wi += midh, ei += midh;
        ei--;
        rep (j, ni) {
            node tmp = node(di, wi, ei, si);
            att.push_back(tmp);
            di += de_di;
            wi += de_pi;
            ei += de_pi;
            si += de_si;
        }
    }
}

int hig[maxh], newhis[maxh];

bool attack(int *hig, int *newhis, node att) {
    bool success = false;
    repf (i, att.w, att.e) {
        if (hig[i] < att.s)
            success = true;
        newhis[i] = max(newhis[i], att.s);
    } 
    return success;
}
int gao() {
    int ans = 0;
    sort(att.begin(), att.end());
    clr(hig);
    rep (i, sz(att)) {
        memcpy(newhis, hig, sizeof(hig));
        int today = att[i].d;
        while (i < sz(att) && att[i].d == today) {
            if ( attack(hig, newhis, att[i]) )
                ans++;
            i++;
        }
        //printf("%d : %d\n", today, ans);
        if (i >= sz(att)) break;
        else i--;
        memcpy(hig, newhis, sizeof(hig));
    }
    return ans;
}
int main() {
    freopen("c.out", "w", stdout);
    int T, ca = 1;
    scanf("%d", &T);
    while (T--) {
        init();
        int ans = gao();
        printf("Case #%d: ", ca++);
        printf("%d\n", ans);
    }
    return 0;
}
