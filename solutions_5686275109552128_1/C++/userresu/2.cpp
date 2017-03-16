#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int T;
int D;
int A[1001];
int main () {
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        scanf("%d",&D);
        int Dmax=0;
        for (int i=1;i<=D;++i) scanf("%d",&A[i]),Dmax=max(A[i],Dmax);
        int best = 2000000000;
        for (int i=1;i<=Dmax;++i) {
            int tot = i;
            for (int j=1;j<=D;++j) tot += (int)ceil(1.0 * A[j] / i) - 1;
            best = min(best,tot);
        }
        printf("Case #%d: %d\n",z,best);
    }
}
