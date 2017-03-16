// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define MS(x, v) std::fill(ALL(x), (v));


#define IOS ios_base::sync_with_stdio(false)

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front


// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;
#endif

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define OMAX 6
#define MAX 25

vector<vector<PII>> ominoes[OMAX];

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

vector<PII> shift_root(const vector<PII> &v)
{
    int mx = v[0].F;
    int my = v[0].S;

    vector<PII> res;
    for (const auto &p : v)
        mx = min(p.F, mx), my = min(p.S, my);

    for (const auto &p : v)
        res.push_back(MP(p.F - mx, p.S - my));

    sort(ALL(res));
    return res;
}

PII rot(const PII& p)
{
    return MP(p.S, -p.F);
}
PII reflect(const PII& p)
{
    return MP(-p.F, p.S);
}

vector<PII> mapv(const vector<PII> &v, function<PII(const PII&)> f)
{
    vector<PII> res;
    for (const auto &p : v)
        res.PB(f(p));
    return shift_root(res);
}

vector<vector<PII>> span(vector<PII> v)
{
    vector<vector<PII>> vs;

    for (int i = 0; i < 4; ++i)
    {
        v = mapv(v, rot);
        vs.push_back(v);
    }
    v = mapv(v, reflect);
    for (int i = 0; i < 4; ++i)
    {
        v = mapv(v, rot);
        vs.push_back(v);
    }
    sort(ALL(vs));
    return vs;
}


vector<vector<PII>> gen_next(const vector<vector<PII>> &vs, int l)
{
    vector<vector<PII>> res;
    for (const auto& v : vs)
    {
        for (const auto& p : v)
        {
            for (int i = 0; i < 4; ++i)
            {
                auto newp = p;
                newp.first += dir[i][0];
                newp.second += dir[i][1];

                auto newv = v;
                newv.PB(newp);

                UNIQUE(newv);

                if (SZ(newv) != l)
                    continue;

                newv = span(newv)[0];
                res.PB(newv);
            }
        }
    }
    UNIQUE(res);
    return res;
}


bool mp[MAX][MAX];
int R, C;

int dfs(int x, int y)
{
    mp[x][y] = true;
    int s = 1;
    for (int i = 0; i < 4; ++i)
    {
        int a = x + dir[i][0];
        int b = y + dir[i][1];
        if (0 <= a and a < R and 0 <= b and b < C and not mp[a][b])
            s += dfs(a, b);
    }
    return s;
}

bool check(const vector<PII> &v, int r, int c)
{
    for(const auto& p: v)
    {
        int x = p.F + r, y = p.S + c;
        if (x >= R or y >= C) return false;
    }
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            mp[i][j] = false;

    for(const auto& p: v)
    {
        int x = p.F + r, y = p.S + c;
        mp[x][y] = true;
    }

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (not mp[i][j])
            {
                int s = dfs(i, j);
                if (s % SZ(v) != 0) return false;
            }

    return true;
}

bool solve2(int x)
{
    if (x >= 7) return true;
    if (x > R and x > C) return true;
    if ((R * C) % x != 0) return true;

    for (const auto& v : ominoes[x])
    {
        bool success = false;
        for (const auto& realv : span(v))
            for (int i = 0; i < R and not success; ++i)
                for (int j = 0; j < C and not success; ++j)
                    if (check(realv, i, j))
                        success = true;

        if (not success)
            return true;
    }
    return false;
}


void solve(int caseid)
{
    fprintf(stderr, "solve at Case %d ... \n", caseid);
    int x;
    scanf("%d %d %d", &x, &R, &C);

    bool ans = solve2(x);
    printf("Case #%d: %s\n", caseid, ans ? "RICHARD" : "GABRIEL");
}


int main()
{
    ominoes[1] = {
        {{0, 0}}
    };
    for (int i = 2; i <= 6; ++i)
    {
        ominoes[i] = gen_next(ominoes[i - 1], i);
        //printf("%d %d\n", i, SZ(ominoes[i]));
    }
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve(i);
}

