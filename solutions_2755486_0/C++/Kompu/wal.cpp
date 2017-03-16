#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef long long LL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;
const int MAX_N = 100000;
const int LOG_MAX_N = 25;
const int DELTA = 50000;

#define f1(x, y) max(x, y)
#define f2(x, y) min(x, y)
#define wiele(x, n) (x)
#define PUSTY 0

struct Tree
{
    VI w, W;
    int n;
    int ile;
    Tree() : w(4 * MAX_N), W(4 * MAX_N)
    {
        ile = DELTA;
        for (int i = 1; i < 2*ile; i++) w[i] = W[i] = PUSTY;
    }
    inline void insert(int a, int b, int c)
    {
        a += DELTA;
        b += DELTA;
        int va = ile + a, vb = ile + b;
        w[va] = f1(w[va], c);
        if (a != b) w[vb] = f1(w[vb], c);
        int d = 0;
        while (va != 1)
        {
            if (va / 2 != vb / 2)
            {
                if (va %2 == 0) w[va + 1] = f1(w[va + 1], c);
                if (vb %2 == 1) w[vb - 1] = f1(w[vb - 1], c);
            }
            va /= 2;
            vb /= 2;
            W[va] = f2(f1(W[2 * va],wiele(w[2 * va], (1 << d))), f1(W[2 * va + 1],wiele(w[2 * va + 1], (1 << d))));
            W[vb] = f2(f1(W[2 * vb],wiele(w[2 * vb], (1 << d))), f1(W[2 * vb + 1],wiele(w[2 * vb + 1], (1 << d))));
            d++;
        }
    }
#define droga(l) do { \
  int w##l = 0, v##l = ile + l; \
  while (v##l != 0) { \
    pom##l[w##l++] = w[v##l]; \
    v##l /= 2; \
  } \
  for (int j = w##l - 2; j >= 0; j--) \
    pom##l[j] = f1(pom##l[j], pom##l[j + 1]); \
} while (0)
    inline int query(int a, int b)
    {
        a += DELTA;
        b += DELTA;
        int poma[LOG_MAX_N], pomb[LOG_MAX_N];
        droga(a);
        droga(b);
        int va = ile + a, vb = ile + b;
        int wynik = ((va != vb) ? f2(poma[0], pomb[0]) : poma[0]);
        int d = 0;
        while (va / 2 != vb / 2)
        {
            if (va % 2 == 0) wynik = f2(wynik, f1(wiele(f1(poma[d + 1], w[va + 1]), (1 << d)), W[va + 1]));
            if (vb % 2 == 1) wynik = f2(wynik, f1(wiele(f1(pomb[d + 1], w[vb - 1]), (1 << d)), W[vb - 1]));
            va /= 2;
            vb /= 2;
            d++;
        }
        return wynik;
    }
    void Write(int p, int k)
    {
        FOR(x, p, k) cout << query(x, x) << " ";
        cout << endl;
    }
};
struct Event
{
    int p, k, t, s;
    Event(int p, int k, int t, int s) : p(p), k(k), t(t), s(s) { }
};
struct djcmp
{
    bool operator() (Event a, Event b)
    {
        return (a.t == b.t) ? a.p < b.p : a.t < b.t;
    }
};
int main()
{
    int t, n, d, m, w, e, s, dd, dp, ds, l;
    scanf("%d", &t);
    FOR(cs, 1, t)
    {
        scanf("%d", &n);
        int wynik = 0;
        vector<Event> events;
        REP(x, n)
        {
            scanf("%d%d%d%d%d%d%d%d", &d, &m, &w, &e, &s, &dd, &dp, &ds);
            REP(i, m) events.PB(Event(w + dp * i, e + dp * i, d + dd * i, s + ds * i));
        }
        sort(ALL(events), djcmp());
//        FOREACH(it, events) cout << it->p << " " << it->k << " " << it->t << " " << it->s << endl;
//        cout << endl;

        Tree k;
        int j, i = 0;
        while(i < SIZE(events))
        {
            j = i;
            l = k.query(events[i].p, events[i].k - 1);
            if(l < events[i].s) wynik++;
//            else cout << events[i].p << " " << events[i].k << " " << events[i].t << " " << events[i].s << endl;
            i++;
            while(i < SIZE(events) && events[i].t == events[i - 1].t)
            {
                l = k.query(events[i].p, events[i].k - 1);
                if(l < events[i].s) wynik++;
//                else cout << events[i].p << " " << events[i].k << " " << events[i].t << " " << events[i].s << endl;
                i++;
            }
            i = j;
            k.insert(events[i].p, events[i].k - 1, events[i].s);
            i++;
            while(i < SIZE(events) && events[i].t == events[i - 1].t)
            {
                k.insert(events[i].p, events[i].k - 1, events[i].s);
                i++;
            }
        }
        printf("Case #%d: %d\n", cs, wynik);
    }
    return 0;
}
