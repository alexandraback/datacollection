#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int N;
long long a[25];

map <long long, vector <int> > sumToMasks;

long long sum(int mask) {
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (mask & (1 << i)) ret += a[i];
    }
    return ret;
}

pair <int, int> solve() {
    sumToMasks.clear();
    for (int mask = 1; mask < (1 << N); ++mask) {
        long long s = sum(mask);
        if (sumToMasks.find(s) != sumToMasks.end()) {
            vector <int> &sume = sumToMasks[s];
            for (int i = 0; i < sume.size(); ++i) {
                if ((sume[i] & mask) == 0) {
                    return make_pair(sume[i], mask);
                }
            }
            sumToMasks[s].push_back(mask);
        } else {
            sumToMasks[s] = vector <int> (1, mask);
        }
    }

    return make_pair(-1, -1);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%lld", &a[i]);

        printf("Case #%d:\n", tt);
        pair <int, int> sol = solve();
        if (sol.first == -1) printf("Impossible\n");
        else {
            for (int i = 0; i < N; ++i) {
                if (sol.first & (1 << i)) printf("%lld ", a[i]);
            }
            printf("\n");
            for (int i = 0; i < N; ++i) {
                if (sol.second & (1 << i)) printf("%lld ", a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
