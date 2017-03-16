#include <cstdio>
#include <fstream>
#include <iostream>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <cstring>
#include <algorithm>

#include <ctime>
#include <cstdlib>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(A) (int) (A).size()

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(A) fputs((A), stderr)

#define sqr(A) ((A) * (A))
#define x first
#define y second
  
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;

const int N = (int) 676060 + 11;
const int SZ = 4 * N;
const int INF = 1e9 + 7;

struct event
{
    int day, l, r;
    LL power;

    event () { }
    event (int day, int l, int r, LL power)
    {
        event :: day = day;
        event :: l = l;
        event :: r = r;
        event :: power = power;
    }
};

bool operator < (const event & a, const event & b)
{
    return a.day < b.day;
}

int tc, n;
LL t[SZ], push_val[SZ];
bool need_to_push[SZ];
vector <event> e;
vector <int> have;

void assign (int v, LL val)
{
    need_to_push[v] = true;
    push_val[v] = max(push_val[v], val);
    t[v] = max(t[v], val);
}

void push (int v)
{
    if (need_to_push[v]) {
        need_to_push[v] = false;
        assign(v * 2 + 1, push_val[v]);
        assign(v * 2 + 2, push_val[v]);
    }
}

void buildTree (int v, int l, int r)
{
    t[v] = 0;
    if (l + 1 == r)
        return;

    int m = (l + r) / 2;
    
    buildTree(v * 2 + 1, l, m);
    buildTree(v * 2 + 2, m, r);
}

LL get (int v, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return t[v];

    if (r <= L || R <= l)
        return INF;

    push(v);

    int m = (l + r) / 2;

    return min(get(v * 2 + 1, l, m, L, R), get(v * 2 + 2, m, r, L, R));
}

void update (int v, int l, int r, int L, int R, LL val)
{
    if (L <= l && r <= R) {
        assign(v, val);
        return;
    }

    if (r <= L || R <= l)
        return;

    push(v);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, L, R, val);
    update(v * 2 + 2, m, r, L, R, val);

    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
} 

void print (int v, int l, int r)
{
    if (l + 1 == r) {
        cerr << t[v] << ' ';
        return;
    }

    push(v);

    int m = (l + r) / 2;

    print(v * 2 + 1, l, m);
    print(v * 2 + 2, m, r);
}

int get (int val)
{
    return lower_bound(have.begin(), have.end(), val) - have.begin();
}

int main () 
{
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif

    scanf("%d", &tc);

    for (int T = 0; T < tc; T++) {
        e.clear();
        have.clear();
        memset(need_to_push, 0, sizeof(need_to_push));
        memset(push_val, 0, sizeof(push_val));
        buildTree(0, 0, N);

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int d, cnt, w, e, dd, dp, ds; 
            LL s;
            scanf("%d%d%d%d%I64d%d%d%d", &d, &cnt, &w, &e, &s, &dd, &dp, &ds);

            for (int i = 0; i < cnt; i++) {
                ::e.push_back(event(d, w, e, s));
                d += dd;
                s += ds;
                e += dp;
                w += dp;
            }
        }
        sort(e.begin(), e.end());

        for (int i = 0; i < sz(e); i++)
            have.push_back(e[i].l), have.push_back(e[i].r);
        sort(have.begin(), have.end());
    
        int ans = 0;
        for (int i = 0, j = 0; i < sz(e); i = j) {
            while (j < sz(e) && e[i].day == e[j].day) {
                //cerr << e[j].l << ' ' << e[j].r << ' ' << e[j].power;
                e[j].l = get(e[j].l), e[j].r = get(e[j].r);
                if (get(0, 0, N, e[j].l, e[j].r) < e[j].power)
                    ans++;//, cerr << " true";
                //cerr << endl;
                j++;
            }

            for (int k = i; k < j; k++) {
                assert(e[k].power >= 0);
                assert(0 <= e[k].l);
                assert(e[k].l < e[k].r);
                assert(e[k].r <= N);
                update(0, 0, N, e[k].l, e[k].r, e[k].power);
            }        
            
            //print(0, 0, N);
            //cerr << endl;
        }

        printf("Case #%d: %d\n", T + 1, ans);
        //cerr << endl << endl;
    }
    
    return 0; 
}

