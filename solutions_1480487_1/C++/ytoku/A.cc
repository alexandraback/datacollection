#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/// from lib ///
/* i=0..n-1 の反復 */
#define REP(i,n) for(int i=0;i<(int)(n);++i)

/* vector<T> v に対して FOREACH(it, v) { *it } のように使う。 */
#define FOREACH(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)

////////////////

int main()
{
    int nset;
    scanf("%d", &nset);
    for (int _c = 1; _c <= nset; _c++) {
        int N;
        scanf("%d", &N);
        int s[N];
        int X = 0;
        REP(i, N) {
            scanf("%d", &s[i]);
            X += s[i];
        }

        double border0 = (double)2*X/N;
        int n_under_border0 = 0;
        int tmp = 0;
        REP(i, N) {
            if (s[i] <= border0) {
                n_under_border0++;
                tmp += s[i];
            }
        }
        double border = (double)(tmp + X)/n_under_border0;

        printf("Case #%d:", _c);
        REP(i, N) {
            double result;
            if (s[i] > border0)
                result = 0;
            else
                result = (border - s[i])/X;
            printf(" %f", result * 100);
        }
        printf("\n");
    }
    return 0;
}
