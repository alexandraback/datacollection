/*
	Time : 0552Z 20160409
	Task : Codejam 16 QR A
	Tags : idiot
	Stat : AC
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define fe(i,x,y) for (int i = x, y = lnk[i]; i; i = nxt[i], y = lnk[i])
#define mkp make_pair
#define pb push_back
#define Fill(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Bit(x,y) ((((x) >> (y)) & 1))
#define mit map<int,SI>::iterator
#define sit SI::iterator

using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair <double, double> PD;
typedef pair <LL, LL> PLI;
typedef pair <PD, int> PDI;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
typedef pair <PI, PI> PIII;
typedef set <PI> SI;
typedef vector <int> VI;
typedef vector <PI> VII;
 
int Read()
{
    char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
    bool neg = (c == '-'); LL ret = (neg ? 0 : c - 48);
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
    return neg ? -ret : ret;
}

struct cmp_str
{
    bool operator()(char *first, char  *second)
    {
        return strcmp(first, second) < 0;
    }
};

map <string, int> ID1, ID2;

const int MAXN = 1005;

int st[MAXN], nxt[MAXN], lnk[MAXN], v[MAXN], match[MAXN];
string s1, s2;
int n, m, N, id, ans;

int Aug(int x)
{
    if (v[x] >= id) return 0;
    v[x] = id;
    fe (i, st[x], y) if (!match[y] || Aug(match[y]))
        return match[y] = x, 1;
    return 0;
}

int main()
{
    freopen("C.in", "r", stdin), freopen("C.out", "w", stdout);
    int T = Read();
    for (int ca = 1; ca <= T; ca ++)
    {
        scanf("%d", &N);
        ID1.clear(), ID2.clear(), n = m = 0;
        Fill(st, 0), Fill(nxt, 0);
        fo (i, 1, N)
        {
            //Fill(s1,0), Fill(s2,0);
            //scanf("%s %s", s1, s2);
            cin >> s1 >> s2;
            if (ID1.find(s1) == ID1.end())
                ID1[s1] = ++ n;
            if (ID2.find(s2) == ID2.end()) ID2[s2] = ++ m;
            int u = ID1[s1], v = ID2[s2];
            lnk[i] = v, nxt[i] = st[u], st[u] = i;
        }
        
        Fill(v, 0), Fill(match, 0), ans = 0;
        fo (i, 1, n)
            ++ id, ans += Aug(i);
        printf("Case #%d: %d\n", ca, N-n-m+ans);
    }
    
    return 0;
}