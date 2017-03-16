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

const int MAXN = 11;

int A, B, C, K;

int main()
{
    freopen("C.in", "r", stdin), freopen("C.out", "w", stdout);
    int T = Read();
    for (int ca = 1; ca <= T; ca ++)
    {
        cin >> A >> B >> C >> K; printf("Case #%d: ", ca);
        printf("%d\n", A * B * min(C, K));
        fo (i, 1, A)
            fo (j, 1, B)
                fo (k, 1, min(C, K))
                    printf("%d %d %d\n", i, j, 1 + (i + j + k) % C);
    }
    return 0;
}