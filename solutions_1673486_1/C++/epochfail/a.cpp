#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100005;

void solve() {
    int typed, total;
    double prob[MAX_N];

    scanf("%d %d", &typed, &total);
    for (int i = 0; i < typed; i++) {
        scanf("%lf", &prob[i]);
    }

    double best = 2 + total; // hit enter; re-type
    // special case, all p_i = 1.0?

    double P = 1.0;

    for (int correct = 0; correct <= typed; correct++) {
        const int rest = total - typed;
        double expect = 2*(typed-correct) + P * (rest + 1) + (1-P)*(rest+1+total+1);
        // printf("%lf\n", expect);
        best = min(best, expect);

        P *= prob[correct];
    }

    printf("%lf\n", best);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i+1);
        solve();
    }

    return 0;
}
