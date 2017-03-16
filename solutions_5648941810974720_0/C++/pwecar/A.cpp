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

const int MAXN = 2005;

int N, cnt[26], ans[10];
char s[MAXN];

int main()
{
    freopen("A.in", "r", stdin), freopen("A.out", "w", stdout);
    int T = Read();
    for (int ca = 1; ca <= T; ca ++)
    {
        scanf("%s", s); printf("Case #%d: ", ca);
        Fill(cnt, 0), Fill(ans,0), N = strlen(s);
        fo (i, 0, N - 1) ++ cnt[s[i] - 'A'];
        ans[0] = cnt[25];
        ans[2] = cnt[22];
        ans[6] = cnt[23];
        ans[4] = cnt[20];
        ans[5] = cnt[5] - ans[4];
        ans[7] = cnt[21] - ans[5];
        ans[8] = cnt[6];
        ans[3] = cnt[19] - ans[2] - ans[8];
        ans[1] = cnt['O'-'A'] - ans[0] - ans[2] - ans[4];
        ans[9] = cnt[8] - ans[5] - ans[6] - ans[8];
        fo (i, 0, 9)
            fo (j, 1, ans[i]) printf("%d", i);
        puts("");
        /*if (N > 0)
        {
            LL ans = N;
            for (int tot = 0; tot < 10; ans += N)
                for (LL n = ans; n; n /= 10)
                    if (lab[n % 10] < ca) lab[n % 10] = ca, tot ++;
            cout << ans - N << endl;
        } else puts("INSOMNIA");*/
    }
    
    return 0;
}