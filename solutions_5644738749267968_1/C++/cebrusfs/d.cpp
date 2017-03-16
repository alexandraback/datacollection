// macros {{{
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define BIT(n) ((1LL) << (long long)(n))
#define FOR(i,c) for (auto i=(c).begin(); i != (c).end(); ++i)
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define REP1(i,a,b) for (int i=(int)(a); i <= (int)(b); ++i)
#define MP make_pair
#define PB push_back

#define Fst first
#define Snd second

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

int solve1(vector<double> A, vector<double> B)
{
    int n = SZ(A);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        auto p = lower_bound(ALL(B), A[i]);
        if (p == B.end())
            p = B.begin();

        if (A[i] > *p)
            ans ++;

        B.erase(p);
    }
    return ans;
}

int solve2(vector<double> A, vector<double> B)
{
    int n = SZ(A);

    int ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        auto p = lower_bound(ALL(B), A[i]);

        if (p == B.begin()) break;

        ans ++;
        B.erase(p - 1);
    }
    return ans;
}

int main()
{
    int z;
    scanf ("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        int n;
        scanf("%d", &n);
        vector<double> A, B;

        for (int i = 0; i < n; ++i)
        {
            double val;
            scanf("%lf", &val);
            A.PB(val);
        }
        for (int i = 0; i < n; ++i)
        {
            double val;
            scanf("%lf", &val);
            B.PB(val);
        }
        sort(ALL(A));
        sort(ALL(B));

        int ans1 = solve1(A, B);
        int ans2 = solve2(A, B);

        printf("Case #%d: %d %d\n", zi, ans2, ans1);
    }
}

