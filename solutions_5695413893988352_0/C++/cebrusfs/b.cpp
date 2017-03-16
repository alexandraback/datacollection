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

#define MAX 20

string replace(string s, char c)
{
    string ans = s;
    for (int i = 0; i < SZ(s); ++i)
        if (ans[i] == '?') ans[i] = c;
    return ans;
}

pair<long long, long long> update(pair<long long, long long> ans, pair<long long, long long> x)
{
    if (ans.first == -1) return x;

    long long d = abs(ans.first - ans.second);
    long long d2 = abs(x.first - x.second);

    if (d2 < d) return x;

    if (d2 == d)
    {
        if (ans.first > x.first) return x;
        if (ans.first == x.first and ans.second > x.second) return x;
    }
    return ans;
}

pair<long long, long long> update(pair<long long, long long> ans, string a, string b)
{
    string ta, tb;

    ta = replace(a, '0'), tb = replace(b, '9');
    ans = update(ans, MP(stoll(ta), stoll(tb)));

    ta = replace(a, '9'), tb = replace(b, '0');
    ans = update(ans, MP(stoll(ta), stoll(tb)));
    return ans;
}

pair<long long, long long> solve(string a, string b)
{
    pair<long long, long long> ans = {-1, -1};
    for (int i = 0; i < SZ(a); ++i)
    {
        string a2, b2;

        a2 = a, b2 = b;
        for (int j = 0; j <= i; ++j)
        {
            if (a2[j] == '?' and b2[j] == '?') a2[j] = b2[j] = '0';
            else if (a2[j] == '?') a2[j] = b2[j];
            else if (b2[j] == '?') b2[j] = a2[j];
        }
        string ta = a2, tb = b2;

        // no change
        a2 = ta, b2 = tb;
        ans = update(ans, a2, b2);

        // add 1 in a
        a2 = ta, b2 = tb;
        if (a[i] == '?' and b[i] == '?')
        {
            a2[i] = '1';
            b2[i] = '0';
        }
        else if (a[i] == '?')
        {
            a2[i] = (b2[i] - '0' + 1) % 10 + '0';
        }
        ans = update(ans, a2, b2);

        // add 1 in b
        a2 = ta, b2 = tb;
        if (a[i] == '?' and b[i] == '?')
        {
            b2[i] = '1';
            a2[i] = '0';
        }
        else if (b[i] == '?')
        {
            b2[i] = (a2[i] - '0' + 1) % 10 + '0';
        }
        ans = update(ans, a2, b2);

        // sub1 in a
        a2 = ta, b2 = tb;
        if (a[i] == '?' and b[i] == '?')
        {
            a2[i] = '0';
            b2[i] = '1';
        }
        else if (a[i] == '?')
        {
            a2[i] = (b2[i] - '0' - 1 + 10) % 10 + '0';
        }
        ans = update(ans, a2, b2);

        // sub1 in b
        a2 = ta, b2 = tb;
        if (a[i] == '?' and b[i] == '?')
        {
            b2[i] = '0';
            a2[i] = '1';
        }
        else if (b[i] == '?')
        {
            b2[i] = (a2[i] - '0' - 1 + 10) % 10 + '0';
        }
        ans = update(ans, a2, b2);

    }
    return ans;
}


bool check(string a, string pat)
{
    for (int i = 0; i < SZ(a); ++i)
        if (pat[i] != '?' and a[i] != pat[i]) return false;
    return true;
}
pair<long long, long long> solve2(string a, string b)
{
    int n = SZ(a);

    int m = 1;
    for(int i = 0; i < n; ++i, m *= 10);

    pair<long long, long long> ans = {-1, -1};
    for (int i = 0; i < m; ++i)
    {
        char s1[MAX], s2[MAX];
        sprintf(s1, "%0*d", n, i);
        if (not check(s1, a)) continue;
        for (int j = 0; j < m; ++j)
        {
            sprintf(s2, "%0*d", n, j);
            if (not check(s2, b)) continue;

            ans = update(ans, MP(1LL * i, 1LL * j));
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
        char s1[MAX], s2[MAX];
        scanf("%s %s", s1, s2);

        string a = s1;
        string b = s2;

        int n = strlen(s1);
        auto p = solve(a, b);
        /*auto p2 = solve2(a, b);
        if (p != p2)
            dump(zi, s1, s2, p, p2);
        */
        printf("Case #%d: %0*lld %0*lld\n", zi, n, p.first, n, p.second);
    }
}

