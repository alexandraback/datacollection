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

const int MAXN = 20;

char s1[20], s2[20], a1[20], a2[20], a3[20], a4[20], pa[20][3], pb[20][3];
int N, t[20][3];
LL f[20][3];

bool small(char *x, char *y)
{
    fo (i, 1, N) if (x[i] < y[i]) return 1; else if (x[i] > y[i]) return 0;
    return 0;
}

void gen(int x, char *a, char *b)
{
    fd (i, N, 1) a[i] = pa[i][x], b[i] = pb[i][x], x = t[i][x];
}

int main()
{
    freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
    int T = Read();
    for (int ca = 1; ca <= T; ca ++)
    {
        scanf("%s %s", s1+1, s2+1); printf("Case #%d: ", ca); N = strlen(s1+1);
        fo (i,1,N+1) f[i][0]=f[i][1]=f[i][2]=-1;
        f[0][0] = 0, f[0][1] = f[0][2] = -1;
        fo (i, 1, N)
        {
            if (s1[i] == '?')
            {
                if (s2[i] == '?')
                {
                    if (f[i-1][1] >= 0) f[i][1] = f[i - 1][1] * 10 - 9, t[i][1] = 1, pa[i][1] = '0', pb[i][1] = '9';
                    if (f[i-1][2] >= 0) f[i][2] = f[i - 1][2] * 10 - 9, t[i][2] = 2, pa[i][2] = '9', pb[i][2] = '0';
                    if (f[i-1][0] >= 0) f[i][1] = 1, f[i][2] = 1, f[i][0] = t[i][0] = t[i][1] = t[i][2] = 0, pa[i][0] = pb[i][0] = pb[i][1] = pa[i][2] = '0', pa[i][1] = pb[i][2] = '1';
                } else
                {
                    if (f[i-1][1] >= 0) f[i][1] = f[i - 1][1] * 10 - (s2[i]-48), t[i][1] = 1, pa[i][1] = '0', pb[i][1] = s2[i];
                    if (f[i-1][2] >= 0) f[i][2] = f[i - 1][2] * 10 + (s2[i]-48) - 9, t[i][2] = 2, pa[i][2] = '9', pb[i][2] = s2[i];
                    if (f[i-1][0] >= 0)
                    {
                        f[i][0] = 0, pa[i][0] = pb[i][0] = s2[i];
                        if (s2[i] < '9') f[i][1] = 1, t[i][1] = 0, pa[i][1] = s2[i]+1, pb[i][1] = s2[i];
                        if (s2[i] > '0') f[i][2] = 1, t[i][2] = 0, pa[i][2] = s2[i]-1, pb[i][2] = s2[i];
                    }
                }
            } else
            {
                if (s2[i] == '?')
                {
                    if (f[i-1][1] >= 0) f[i][1] = f[i - 1][1] * 10 + (s1[i]-48) - 9, t[i][1] = 1, pa[i][1] = s1[i], pb[i][1] = '9';
                    if (f[i-1][2] >= 0) f[i][2] = f[i - 1][2] * 10 - (s1[i]-48), t[i][2] = 2, pa[i][2] = s1[i], pb[i][2] = '0';
                    if (f[i-1][0] >= 0)
                    {
                        f[i][0] = 0, t[i][0] = 0, pa[i][0] = pb[i][0] = s1[i];
                        if (s1[i] < '9') f[i][2] = 1, t[i][2] = 0, pa[i][2] = s1[i], pb[i][2] = s1[i] + 1;
                        if (s1[i] > '0') f[i][1] = 1, t[i][1] = 0, pa[i][1] = s1[i], pb[i][1] = s1[i] - 1;
                    }
                } else
                {
                    pa[i][0] = pa[i][1] = pa[i][2] = s1[i], pb[i][0] = pb[i][1] = pb[i][2] = s2[i];
                    if (f[i-1][1] >= 0) f[i][1] = f[i - 1][1] * 10 + (s1[i] - s2[i]), t[i][1] = 1;
                    if (f[i-1][2] >= 0) f[i][2] = f[i - 1][2] * 10 + (s2[i] - s1[i]), t[i][2] = 2;
                    if (f[i-1][0] >= 0)
                    {
                        if (s1[i] == s2[i]) f[i][0] = 0; else
                            if (s1[i] > s2[i]) f[i][1] = s1[i] - s2[i], t[i][1] = 0;
                                else f[i][2] = s2[i] - s1[i], t[i][2] = 0;
                    }
                }
            }
        }
        Fill(a1,0),Fill(a2,0), Fill(a3,0), Fill(a4,0);
        if (f[N][0] == 0)
        {
            fo (i, 1, N)
                if (s1[i] == '?') a1[i] = (s2[i] == '?' ? '0' : s2[i]);
                    else a1[i] = s1[i];
            printf("%s %s\n", a1+1,a1+1);
        } else
        {
            if (f[N][1] >= 0)
            {
                gen(1,a1,a2);
                /*fo (i, 1, N)
                    if (f[i+1][0] == 0) 
                        a1[i] = a2[i] = (s1[i] == '?' ? (s2[i] == '?' ? '0' : s2[i]) : s1[i]);
                    else
                    {
                        if (s1[i] == '?')
                        {
                            if (s2[i] == '?')
                            {
                                if (f[i-1][0] >= 0)
                                {
                                    if (s1[i+1] == '0') a1[i] = '1', a2[i] = '0'; else a1[i] = a2[i] = '0';
                                } else a1[i] = '0', a2[i] = '9';
                            } else
                            {
                                a2[i] = s2[i];
                                if (f[i-1][1] >= 0 && s2[i] < '9') a1[i] = s2[i] + 1; else a1[i] = '0';
                            }
                        } else
                            a1[i] = s1[i], a2[i] = (s2[i] == '?' ? (f[i][0]>=0&&s1[i]>'0'?s1[i]-1:'9') : s2[i]);
                    }*/
            } else f[N][1] = 4e18;
            if (f[N][2] >= 0)
            {
                /*fo (i, 1, N)
                    if (f[i+1][0] == 0) a3[i] = a4[i] = (s1[i] == '?' ? (s2[i] == '?' ? '0' : s2[i]) : s1[i]);
                    else
                    {
                        if (s1[i] == '?')
                        {
                            if (s2[i] == '?')
                            {
                                if (f[i-1][0] >= 0)
                                {
                                    a3[i] = '0';
                                    if (s2[i+1] == '0') a4[i] = '1'; else a4[i] = '0';
                                } else a3[i] = '9', a4[i] = '0';
                            } else
                            {
                                a4[i] = s2[i];
                                if (f[i-1][2] >= 0 && s2[i] > '0') a3[i] = s2[i] - 1; else a3[i] = '9';
                            }
                        } else 
                            a3[i] = s1[i], a4[i] = (s2[i] == '?' ? (f[i][0]>=0&&s1[i]<'9'?s1[i]+1:'0') : s2[i]);
                    }*/
                gen(2,a3,a4);
            } else f[N][2] = 4e18;
            
            if (f[N][1] < f[N][2]) printf("%s %s\n", a1+1, a2+1);
                else if (f[N][2] < f[N][1]) printf("%s %s\n", a3+1,a4+1);
                else
                {
                    if (small(a3,a1)) printf("%s %s\n", a3+1,a4+1);
                        else printf("%s %s\n", a1+1,a2+1);
                }
        }
    }
    return 0;
}