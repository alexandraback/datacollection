/*
	Time : 0552Z 20160409
	Task : Codejam 16 QR A
	Tags : idiot
	Stat : AC
*/
#include <bits/stdc++.h>

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

const int MAXN = 55;

//int N, sum, cnt[26];
int N, has[55];
LL M;

int main()
{
    freopen("B.in", "r", stdin), freopen("B.out", "w", stdout);
    int T = Read();
    for (int ca = 1; ca <= T; ca ++)
    {
        cin >> N >> M; printf("Case #%d: ", ca);
        if (M > (1LL << (LL) (N-2))) { puts("IMPOSSIBLE"); continue; }
        puts("POSSIBLE");
        fo (j, 1, N - 1) putchar(j > 1 ? '1' : '0');
        if (M == (1LL<<(LL)(N-2))) -- M, puts("1"); else puts("0");
        fo (i, 2, N - 1)
        {
            fo (j, 1, N - 1) putchar(j > i ? '1' : '0');
            puts(M % 2 ? "1" : "0");
            M /= 2;
        }
        fo (i, 1, N) putchar('0');
        puts("");
        /*sum=0; fo (i, 0, N-1) scanf("%d", cnt+i), sum+=cnt[i];
        for (; sum ;sum-=2)
        {
            int m1(0), m2(0), f1(0), f2(0);
            fo (i, 0, N-1) if (cnt[i]>m1) m2=m1,f2=f1,m1=cnt[i],f1=i;
                else if (cnt[i]>m2) m2=cnt[i], f2=i;
            if (sum != 3)
            {
                if (m1 > m2) printf(" %c%c", (char) ('A'+f1), (char) ('A'+f1)), cnt[f1]-=2;
                    else printf(" %c%c", (char) ('A'+f1), (char) ('A'+f2)), cnt[f1]--, cnt[f2]--;
            } else
            {
                sum ++;
                printf(" %c", (char) ('A'+f1)), -- cnt[f1];
            }
        }
        puts("");*/
    }
    
    return 0;
}