#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

struct query {
    int t, type, l, r, s;
    query(int t, int type, int l, int r, int s) : t(t), type(type), l(l), r(r), s(s)  {}
};

OUT(query, w) {
    o << "{ time: " << w.t << " " <<
         "  type: " << w.type << " " <<
         "  [l, r]: " << w.l << " " << w.r << " " <<
         "  strength: " << w.s << "}\n" ;
}

inline bool operator < (const query &a, const query &b) {
    if (a.t != b.t) return a.t < b.t;
    if (a.type != b.type) return a.type < b.type;
    return false;
}

struct node {
    node *L, *R;
    int ll, rr, mh;
    node(int ll, int rr) : ll(ll), rr(rr), mh(0) { L = R = NULL; }
    void erase() {
        if (L) L->erase(), delete(L);
        if (R) R->erase(), delete(R);
    }
    void uL() {
        if (!L) L = new node(ll, (ll + rr) / 2);
    }
    void uR() {
        if (!R) R = new node((ll + rr) / 2, rr);
    }
    void update(int l, int r, int h) {
        int tt = (ll + rr) / 2;
        if (l == ll && r == rr) {
            mh = max(mh, h);
            return;
        }
        if (r <= tt) {
            uL();
            L->update(l, r, h);
        } else if (tt <= l) {
            uR();
            R->update(l, r, h);
        } else {
            uL();
            uR();
            L->update(l, tt, h);
            R->update(tt, r, h);
        }
        if (L && R) {
            mh = max(mh, min(L->mh, R->mh));
        }
    }
    int get(int l, int r) {
        int tt = (ll + rr) / 2;
        if (l == ll && r == rr) {
            return mh;
        }
        if (r <= tt) {
            if (L) return max(L->get(l, r), mh);
            else return mh;
        } else if (tt <= l) {
            if (R) return max(R->get(l, r), mh);
            else return mh;
        } else {
            int t = INF;
            if (L) t = min(t, L->get(l, tt));
            else   t = 0;
            if (R) t = min(t, R->get(tt, r));
            else   t = 0;
            return max(mh, t);
        }
    }
} *root = NULL;

// const int MX = 10000000;
// int _h[2 * MX + 1];
// #define h(x) _h[x + MX]

int execute(const query &q) {
    //cerr << "TYPE: " << q.type << endl;
    if (q.type == 0) {
        // check
        // bool ok = true;
        // for (int i = q.l; i < q.r; i++) 
        //     if (h(i) < q.s) {
        //         ok = false;
        //         break;
        //     }

        // if (!ok) return 1;
        if (root->get(q.l, q.r) < q.s) return 1;
    } else {
        // update
        // for (int i = q.l; i < q.r; i++)
        //     h(i) = max(h(i), q.s);
        root->update(q.l, q.r, q.s);
    }
    return 0;
}

void init() {
    if (root != NULL) {
        root->erase();
        delete(root); 
        root = NULL;
    }
    root = new node(-(1 << 30), +(1 << 30));
}

void solve(int case_id) {
    cerr << case_id << endl;
    init();
    int n;
    scanf("%d", &n);
    vector<query> q;
    rept(i, n) {
        int d0, nx, l0, r0, s0, dd, dp, ds;
        scanf("%d%d%d%d%d%d%d%d", &d0, &nx, &l0, &r0, &s0, &dd, &dp, &ds);
        rept(j, nx) 
            rept(type, 2)
                q.pb(query(d0 + j * dd, type, l0 + j * dp, r0 + j * dp, s0 + j * ds));
    }
    SORT(q);

    int ans = 0;
    rept(i, L(q)) {
        //cerr << i << endl;
        int wc = execute(q[i]);
        // cerr << YELLOW;
        // cerr << "time: " << q[i].t << " type: " << q[i].type << endl;
        // cerr << "[l, r, s]: " << q[i].l << " " << q[i].r << " " << q[i].s << endl;
        // cerr << "res: " << wc << endl;
        // cerr << RESET;
        ans += wc;
        
    }
    printf("Case #%d: %d\n", case_id, ans);
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
        solve(tc);
    }
    return 0;
}
