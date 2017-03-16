#include <cstdio>
#include <algorithm>

#define fr(a,b,c) for(int a = b; a < c; a++)
#define vi vector<int>
#define vvi vector< vi >
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define rfin freopen("in.txt", "r", stdin)
#define wtout freopen("out.txt", "w", stdout)
#define tri(x) (x*x + x)/2

using namespace std;

long long comb(int n, int k) {
    if (k > n) return 0;
    if (k > n/2) k = n-k;
    long long num = 1, denom = 1;
    while (k) {
        denom *= k--;
        num *= n--;
    }
    return num/denom;
}

double prob1(int n, int k) {
    long long sum = 0;
    if (k > n/2) k = n-k;
    double fator = (double) (1<<n);
    for(int x = 0; x <= k; x++) {
        sum += comb(n, x);
    }
    return ((double)sum)/fator;
}

int main() {
    rfin;
    wtout;
    int t, casen = 0, n, x, y, lado, montanha;
    double p;
    sc(t);
    while (++casen <= t) {
        printf("Case #%d: ", casen);
        sc3(n, x, y);
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        lado = x+y;
        //printf("%d\n", lado);
        montanha = tri((lado+1));
        //printf("%d\n", montanha);
        if ((x == 0 && y == 0) || n >= montanha) {
            printf("1.0\n");
            continue;
        } else if (n <= tri(lado-1)) {
            printf("0.0\n");
            continue;
        }
        n -= tri((lado-1));
        lado++;
        //printf("%d %d\n", n, y+1);
        if (y+2 + lado/2 <= n) {
            printf("1.0\n");
        } else if (x) {
            p = prob1(n, y+1);
            printf("%lf\n", p);
        }else printf("0.0\n");
    }
    return 0;
}
