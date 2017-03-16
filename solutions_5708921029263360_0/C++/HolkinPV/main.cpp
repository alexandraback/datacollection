#pragma comment(linker, "/stack:128000000")

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = INT_MAX / 2;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

const int N = 3 + 1;

int j, p, s, k;

inline bool read()
{
    if (scanf("%d%d%d%d", &j, &p, &s, &k) != 4)
        return false;

	return true;
}

int ps[N][N], js[N][N], jp[N][N];
//int used[N][N][N];
int used2[N * N * N];

int ANS;
int CUR;

vector<pair<int, pt> > ANSV;
vector<pair<int, pt> > CURV;

int J, P, S, K;

map< pair<pt, pt>, int > RES;
map< pair<pt, pt>, vector<pair<int, pt> > > RESV;

inline void brute()
{
    if (ANS < CUR)
    {
        ANS = CUR;
        ANSV = CURV;
    }

    if (sz(CURV) > 0)
    {
        if (!(CURV[0].ft == 0 && CURV[0].sc.ft == 0 && CURV[0].sc.sc == 0))
            return;

    }

    /*if (sz(CURV) > 1)
    {
        if (CURV[1].ft == 2 && CURV[1].sc.ft == 2 && CURV[1].sc.sc == 2)
            return;
    }*/


    /*if (sz(CURV) > 1)
    {
        //if (CURV[sz(CURV) - 2].sc.sc > CURV[sz(CURV) - 1].sc.sc)
        if (CURV[sz(CURV) - 2] > CURV[sz(CURV) - 1])
            return;
    }*/


    forn(ss, S)
        forn(jj, J)
            if (js[jj][ss] + 1 <= K)
            {
                forn(pp, P)
                {
                    int idx = jj * N * N + pp * N + ss;

                    //if (!used[jj][pp][ss] && ps[jj][pp] + 1 <= K && jp[jj][pp] + 1 <= K)
                    if (!used2[idx] && ps[pp][ss] + 1 <= K && jp[jj][pp] + 1 <= k)
                    {
                        js[jj][ss]++;
                        ps[pp][ss]++;
                        jp[jj][pp]++;
                        //used[jj][pp][ss] = true;
                        used2[idx] = true;
                        CUR++;
                        CURV.pb(mp(jj, mp(pp, ss)));

                    if (sz(CURV) > 1)
                    {
                    //if (CURV[sz(CURV) - 2].sc.sc > CURV[sz(CURV) - 1].sc.sc)
                        if (CURV[sz(CURV) - 2] <= CURV[sz(CURV) - 1])
                            brute();
                    }
                    else
                        brute();

                if (sz(CURV) > 0)
                {
                    if (!(CURV[0].ft == 0 && CURV[0].sc.ft == 0 && CURV[0].sc.sc == 0))
                        return;
                }
    /*if (sz(CURV) > 1)
    {
        if (CURV[1].ft == 2 && CURV[1].sc.ft == 2 && CURV[1].sc.sc == 2)
            return;
    }*/

                        js[jj][ss]--;
                        ps[pp][ss]--;
                        jp[jj][pp]--;
                        //used[jj][pp][ss] = false;
                        used2[idx] = false;
                        CUR--;
                        CURV.pop_back();
                    }
                }
            }
}

inline void naive(int j, int p, int s, int k)
{
    k = min(k, 3);
    if (RES.count(mp( mp(j, p), mp(s, k) ) ))
    {
        ANS = RES[mp( mp(j, p), mp(s, k) )];
        ANSV = RESV[mp( mp(j, p), mp(s, k) )];
        return;
    }


    memset(ps, 0, sizeof(ps));
    memset(js, 0, sizeof(js));
    memset(jp, 0, sizeof(jp));
    //memset(used, 0, sizeof(used));
    memset(used2, 0, sizeof(used2));

    ANS = CUR = 0;
    ANSV.clear();
    CURV.clear();
    J = j, P = p, S = s, K = k;

    brute();

    RES[mp( mp(j, p), mp(s, k) )] = ANS;
    RESV[mp( mp(j, p), mp(s, k) )] = ANSV;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);

    /*fore(s, 1, 3)
    fore(p, 1, s)
    fore(j, 1, p)
    fore(k, 1, 3)
    {
        naive(j, p, s, k);
        cerr << j << " " << p << " " << s << " " << k << endl << " clock = " << clock() << endl;
        assert(ANS == sz(ANSV));
        cerr << ANS << endl;
        forn(i, sz(ANSV))
            cerr << ANSV[i].ft + 1 << " " << ANSV[i].sc.ft + 1 << " " << ANSV[i].sc.sc + 1 << endl;

        cerr << endl;
    }*/
        
    naive(j, p, s, k);
        
    assert(ANS == sz(ANSV));
    cout << ANS << endl;
    forn(i, sz(ANSV))
        cout << ANSV[i].ft + 1 << " " << ANSV[i].sc.ft + 1 << " " << ANSV[i].sc.sc + 1 << endl;
}

int main()
{
#ifdef HP
    freopen("input.txt", "rt", stdin);
    freopen("output2.txt", "wt", stdout);
#endif

    int testCnt;
    assert(cin >> testCnt);

    forn(test, testCnt)
    {
        assert(read());
        solve(test);
    }

    return 0;
}

