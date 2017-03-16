#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#ifdef CUTEBMAING
#include "cutedebug.h"
#else
#define debug(x) ({})
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

const int inf = ((1 << 30) - 1);
const int64 linf = ((1ll << 62) - 1);
const int cmax = 100500;

const char* fin = "input.txt";
const char* fout = "output.txt";

struct item{
    int x, cnt;
    item *l, *r;
    item(){}
};

typedef item* pnode;

item _[2000000];
int ln = 0;

inline pnode node(int x = 0){
    pnode res = &_[ln++];
    res->x = x, res->cnt = 1;
    res->l = res->r = 0;
    return res;
}

inline pnode clone(pnode t){
    pnode res = node();
    res->x = t->x, res->cnt = t->cnt;
    res->l = t->l, res->r = t->r;
    return res;
}

#define cnt(a) ((a) ? (a)->cnt : 0)

inline void merge(pnode &t, pnode l, pnode r){
    if (!l || !r)
        return void (t = l ? l : r);
    if (rand() % (l->cnt + r->cnt) < l->cnt)
        l = clone(l), merge(l->r, l->r, r), t = l;
    else
        r = clone(r), merge(r->l, l, r->l), t = r;
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

inline void split(pnode t, pnode &l, pnode &r, int x, int add = 0){
    if (!t)
        return void (l = r = 0);
    t = clone(t);
    int curX = cnt(t->l) + add;
    if (x <= curX)
        split(t->l, l, t->l, x, add), r = t;
    else
        split(t->r, t->r, r, x, curX + 1), l = t;
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

inline int kth_element(pnode rt, int k){
    pnode l, m, r; split(rt, l, r, k + 1);
    split(l, l, m, k);
    assert(m);
    return m->x;
}

inline void copy(pnode &a, pnode b, int l1, int r1, int l2, int r2){
    pnode ll1, mm1, rr1; split(a, ll1, rr1, r1 + 1);
    split(a, ll1, mm1, l1);
    pnode ll2, mm2, rr2; split(b, ll2, rr2, r2 + 1);
    split(b, ll2, mm2, l2);
    merge(a, ll1, mm2); merge(a, a, rr1);
}

int n, m;
int a[cmax], b[cmax];
pnode rt1 = 0, rt2 = 0;

inline void print(pnode t, bool flag = true){
    if (t){
        print(t->l, false);
        cout << t->x << ' ';
        print(t->r, false);
    }
    if (flag)
        cout << endl;
}

int main(){
    #if !defined STRESS && defined CUTEBMAING
    assert(freopen(fin, "r", stdin));
    assert(freopen(fout, "w", stdout));
    #endif
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; i++)
        cin >> x, merge(rt2, rt2, node(x));
    for (int i = 0; i < n; i++)
        cin >> x, merge(rt1, rt1, node(x));
    print(rt2);
    print(rt1);
    for (int i = 0; i < m; i++){
        int t; cin >> t;
        if (t == 1){
            int x, y, k; cin >> x >> y >> k, --x, --y;
            copy(rt1, rt2, y, y + k - 1, x, x + k - 1);
        }
        else if (t == 2){
            int x; cin >> x, --x;
            cout << kth_element(rt1, x) << endl;
        }
        print(rt2);
        print(rt1);
    }
    return 0;
}
