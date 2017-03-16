#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <climits>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef long long LL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

size_t popcount(size_t n)
{
    bitset<sizeof(size_t) * CHAR_BIT> b(n);
    return b.count();
}
int Piramida(int n)
{
    return ((n * n) + n) / 2;
}
double Symuluj(int k, int n, int a) // k rzutow, n pojemnosci
{
    int w = 0, q = 0, g = (1 << k);
    REP(i, g)
    {
        int l = popcount(i);
        if(l > n || l < k - n) continue;
        q++;
        if(l >= a) w++;
    }
    return double(w) / double(q);
}
int main()
{
    int t, n, corx, cory, r;
    scanf("%d", &t);
    FOR(cs, 1, t)
    {
        scanf("%d%d%d", &n, &corx, &cory);
        printf("Case #%d: ", cs);
        if(((abs(corx) + abs(cory)) & 1) == 1)
        {
            printf("0\n");
            continue;
        }
        r = abs(corx) + abs(cory) - 1;
        if(Piramida(r + 2) <= n || (corx == 0 && cory == 0))
        {
            printf("1\n");
            continue;
        }
        if(Piramida(r) >= n)
        {
            printf("0\n");
            continue;
        }
        n -= Piramida(r++);
        printf("%lf\n", Symuluj(n, r, cory + 1));
    }
    return 0;
}
