#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define rep(i,n) for (int i=0;i<n;++i)

using namespace std;

const int Dmax = 1123, Pmax = 1123;

int n, ps[Dmax], pn[Dmax];

int com(const void*a , const void *b)  { return - *((const int *)a) + *((const int *)b); }

int check(int et)
{
    memcpy(pn, ps, sizeof(int[n]));
    int re = 0;
    rep(i,n) re += ps[i] / et + (ps[i] % et ? 1 : 0) - 1;
    return re + et;
}

int main()
{
    int _tn; scanf("%d", &_tn);
    rep(_ti, _tn)
    {
        scanf("%d", &n);
        rep(i, n) scanf("%d", ps+i);
        int mt = INT_MAX, mst = 0;
        rep(i, n) mst = max(ps[i], mst);
        for (int i=1;i<=mst;++i) 
            mt = min(mt, check(i));
        printf("Case #%d: %d\n", _ti+1, mt);
    }
    return 0;
}
