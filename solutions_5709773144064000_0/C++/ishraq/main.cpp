#include <cstdio>
#include <algorithm>

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    FO(Z,0,T) {
        printf("Case #%d: ", Z+1);

        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);

        double best = 1e100;

        double ct = 0;
        FO(n,0,10000000) {
            if (n) ct += c / (2 + (n-1)*f);
            best = min(best, ct + x / (2 + n*f));
        }

        printf("%.10lf\n", best);
    }

    return 0;
}

