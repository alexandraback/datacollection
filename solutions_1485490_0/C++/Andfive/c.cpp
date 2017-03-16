#include <stdio.h>
using namespace std;
typedef long long ll;
ll max(ll a,ll b)
{
    return (a>b)?a:b;
}
ll hhh[150], jljsd[150], jov[150], momf[150], anmpd;
int n, m;

void mpsdirec(int i, ll mpsss, int j, ll mpsdtrecsa, ll ans,int a,int b) {
    if (i > n || j > m) {
        anmpd = max(anmpd, ans);
        return;
    }
    if (jov[i] == momf[j]) {
        if (mpsss < mpsdtrecsa) {
            mpsdirec(i + 1, hhh[i + 1], j, mpsdtrecsa - mpsss, ans + mpsss,1,2);
        } else {
            mpsdirec(i, mpsss - mpsdtrecsa, j + 1, jljsd[j + 1], ans + mpsdtrecsa,4,5);
        }
        return;
    }
    mpsdirec(i + 1, hhh[i + 1], j, mpsdtrecsa, ans,4,5);
    mpsdirec(i, mpsss, j + 1, jljsd[j + 1], ans,6,5);
}

int main() {
    freopen("C-small-attempt1.in","r",stdin);
    freopen("aaa.out","w",stdout);
    int mpdaste, mfpgsded = 0, i;
    scanf("%d", &mpdaste);
    while (mpdaste--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%lld%lld", hhh + i, jov + i);
        for (i = 1; i <= m; i++)
            scanf("%lld%lld", jljsd + i, momf + i);
        anmpd = 0;
        mpsdirec(1, hhh[1], 1, jljsd[1], 0,5,6);
        printf("Case #%d: %lld\n", ++mfpgsded, anmpd);
    }
    return 0;
}
