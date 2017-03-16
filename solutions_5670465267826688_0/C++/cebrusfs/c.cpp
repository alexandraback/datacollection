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


int tab[4][4] =
{
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1},
};

int mul(int a, int b)
{
    int sign = a * b / abs(a * b);
    return sign * tab[abs(a) - 1][abs(b) - 1];
}

#define MAX 500005

char str[MAX];
int ary[MAX];
int pre[MAX], suf[MAX];

void solve(int caseid)
{
    fprintf(stderr, "solve at Case %d ... \n", caseid);

    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    scanf("%s", str);

    if (m >= 16)
        m = m % 16 + 16;

    for (int i = 0; i < n; ++i)
    {
        int val;
        if (str[i] == '1')
            val = 1;
        else if (str[i] == 'i')
            val = 2;
        else if (str[i] == 'j')
            val = 3;
        else// if (str[i] == 'k')
            val = 4;
        ary[i] = val;
    }
    for (int j = 1; j < m; ++j)
        for (int i = 0; i < n; ++i)
            ary[j * n + i] = ary[i];
    n *= m;

    pre[0] = ary[0];
    for (int i = 1; i < n; ++i)
    {
        pre[i] = mul(pre[i - 1], ary[i]);
    }


    suf[n - 1] = ary[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        suf[i] = mul(ary[i], suf[i + 1]);
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i)
        if (l == -1 and pre[i] == 2) // i
            l = i;

    for (int i = n - 1; i >= 0; --i)
        if (r == -1 and suf[i] == 4) // k
            r = i;

    bool ans = l >= 0 and r >= 0 and l < r and pre[n - 1] == -1;
    printf("Case #%d: %s\n", caseid, ans ? "YES" : "NO");

}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
        solve(i);
}

