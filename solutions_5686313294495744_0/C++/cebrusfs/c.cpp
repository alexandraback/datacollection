// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define MSA(x, v) std::fill(ALL(x), (v))
#define MS(st, ed, v) std::fill((st), (ed), (v))

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

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

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;

// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;

// dump() {{{
template<typename T>
void _dump(const char* s, T&& head) {
    cerr<< s << "=" << head << endl;
}

template<typename T, typename... Args>
void _dump(const char* s, T&& head, Args&&... tail) {
    int c = 0;
    while (*s!=',' || c!=0) {
        if (*s=='(' || *s=='[' || *s=='{') c++;
        if (*s==')' || *s==']' || *s=='}') c--;
        cerr << *s++;
    }
    cerr << "=" << head << ", ";
    _dump(s+1, tail...);
}

#ifdef FISH
#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);
#else
#define dump(...) ;
#endif

template<typename Iter>
ostream& _out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "":" ") << *it;
    s << "]";
    return s;
}

template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<(ostream &s, const set<T> &c) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<(ostream &s, const unordered_set<T> &c) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<(ostream &s, const map<A,B> &c) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<(ostream &s, const unordered_map<A,B> &c) { return _out(s,ALL(c)); }
// }}}

#endif
// }}}


#define MAX 2005
#define SMAX 22

char s1[SMAX];
char s2[SMAX];
map<string, int> lmp, rmp;

vector<int> e[MAX];
bool vis[MAX];
int matching[MAX];
int m;

int dfs(int now)
{
    for (int b : e[now])
    {
        if (vis[b]) continue;

        vis[b] = true;
        if (matching[b] == -1 || dfs(matching[b]))
        {
            matching[now] = b;
            matching[b] = now;
            return true;
        }
    }
    return false;
}

int solve()
{
    int ans = 0;

    memset(matching, -1, sizeof(matching));
    for (int i = 0; i < m; ++i)
    //for (const auto &p : lmp)
    {
        //int i = p.second;
        if (matching[i] == -1)
        {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))
                ans++;
        }
    }
    return ans;
}


int main()
{
    int z;
    scanf("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < MAX; ++i)
            e[i].clear();

        m = 0;
        lmp.clear(), rmp.clear();
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            scanf("%s %s", s1, s2);
            if (not lmp.count(s1))
                lmp[s1] = m++;
            if (not rmp.count(s2))
                rmp[s2] = m++;

            a = lmp[s1];
            b = rmp[s2];

            e[a].push_back(b);
            e[b].push_back(a);
        }

        int match = solve();
        //dump(n, m, match);
        printf("Case #%d: %d\n", zi, n - (m - match));
    }
}

