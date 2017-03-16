#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();

int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    cerr.precision(10);
    cerr.setf(ios::fixed);
    #ifdef LOCAL
    freopen("c.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

struct Hiker
{
    ld start;
    ld time;

    Hiker(ld start, ld time): start(start), time(time) {}

    bool operator<(const Hiker &h) const
    {
        return start < h.start || (start == h.start && time > h.time);
    }
};

#define EPS 1e-5

vector <Hiker> a;

ld getpos(Hiker h, ld t)
{
    ld res = h.start + t * 360 / h.time;
    ld q = floorl(res / 360);
    res -= q * 360;
    if (res + EPS >= 360)
        res -= 360;
    assert(res >= 0 && res < 360);
    return res;
}

ld next_intersect(Hiker a, Hiker b, ld t)
{
    if (a.time >= b.time)
        return INFL;
    t += EPS;
    ld apos = getpos(a, t);
    ld bpos = getpos(b, t);
    ld diff = (bpos - apos);
    if (diff <= 0)
        diff += 360;
    ld bspeed = (b.time >= INFL ? 0 : 360 / b.time);
    return t + diff / (360 / a.time - bspeed);
}

int calc(int id, ld t)
{
    int n = sz(a);
    Hiker fict(0, INFL);
    ld win_time = next_intersect(a[id], fict, t);
    pair <ld, int> nx = {INFL, -1};
//    cerr << win_time << '\n';
    forn (i, n)
    {
        ld next = next_intersect(a[i], a[id], t);
        nx = min(nx, {next, i});
//        cerr << i << ' ' << next << '\n';
    }
    if (nx.first > win_time)
        return 0;
    return 1;
}

int test = 1;

int solve()
{
    a.clear();
    int n;
    cin >> n;
    forn (i, n)
    {
        int start, cnt, mv;
        cin >> start >> cnt >> mv;
        forn (j, cnt)
            a.emplace_back(start, mv++);
    }
    sort(a.begin(), a.end());
    int ans = calc(0, 0);
    cout << "Case #" << test++ << ": " << ans << '\n';
    return 0;
}
