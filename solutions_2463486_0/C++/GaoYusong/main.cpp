#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 10000000;

int sum[N + 1000];

bool check(ll x)
{
    int aa[110], cc = 0;
    while (x) {
        aa[cc++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < cc / 2; i++) {
        if (aa[i] != aa[cc - i - 1]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int T;
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    for (ll i = 1; i <= N; i++) {
        sum[i] = sum[i - 1];
        if (check(i) && check(i * i)) {
            sum[i]++;
        }
    }

    scanf("%d", &T);
    int cn = 0;
    while (T--) {
        ll A, B;
        scanf("%I64d%I64d", &A, &B);
        int l = (int)ceil(sqrt(A) - 1e-10),
            r = (int)floor(sqrt(B) + 1e-10);
        printf("Case #%d: %d\n", ++cn, sum[r] - sum[l - 1]);
    }
    return 0;
}
