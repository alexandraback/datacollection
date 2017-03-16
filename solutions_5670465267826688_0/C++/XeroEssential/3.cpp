#include <cstdlib>
#include <cstring>
#include <cstdio>
#define rep(i,n) for (int i=0;i<n;i+=1)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define sign(a) (a>0?1:-1)
#define abs(a) (a<0?-a:a)

using namespace std;
typedef long long ll;

const int mtable [][4] = {{1,2,3,4}, {2,-1,4,-3}, {3,-4,-1,2}, {4,3,-2,-1}};
inline int mul(int a, int b)
{
    return mtable[abs(a)-1][abs(b)-1] * sign(a) * sign(b);
}

int ppow(int a, ll b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    int t = ppow(a, b>>1); t = mul(t, t);
    if (b & 1) t = mul(t, a);
    return t;
}

const int Nmax = 11234;
char cmap[256]; char cstr[Nmax];
int ns[Nmax], nre, fre;
ll n, m;

bool smap_m[32];
bool *smap = smap_m + 16;
int seek(int inc, int tar)
{
    int beg, end;
    if (inc > 0) beg = 0, end = n;
    if (inc < 0) beg = n-1, end = -1;
    int mi = 0, cnt = 0, cur = 1;
    memset(smap_m, 0, sizeof(smap_m));
    while (mi < 16)
    {
        if (smap[cur]) return -1;
        smap[cur] = true, mi++;
        if (cur == tar) 
            return cnt;
        for (int i=beg;i!=end;i+=inc)
        {
            cur = (inc > 0 ? mul(cur, ns[i]) : mul(ns[i], cur));
            cnt ++;
            if (cur == tar) 
                return cnt;
        }
    }
    return -1;
}

inline void output(int _ti, bool re) { printf("Case #%d: %s\n", _ti+1, (re?"YES":"NO")); }
int main(int argc, const char *argv[])
{
    cmap['1'] = 1, cmap['i'] = 2, cmap['j'] = 3, cmap['k'] = 4;
    int _tn; scanf("%d", &_tn);
    rep(_ti, _tn)
    {
        scanf("%d%d%s", &n, &m, cstr);
        rep(i,n) ns[i] = cmap[(int)cstr[i]];
        nre = 1;
        rep(i,n) nre = mul(nre, ns[i]);
        fre = ppow(nre, m);
        if (fre != -1) { output(_ti, false); continue; }
        ll in = seek(1,2), kn=seek(-1,4);
        if (in == -1 || kn == -1 || m*n - in - kn <= 0)  { output(_ti, false); continue; }
        output(_ti, true);
    }
    return 0;
}

