#include <cstdio>
#include <cassert>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;

int main() {
    int t;
    scanf("%d", &t);
    for (int zz = 1; zz <= t; ++zz) {
        int d;
        scanf("%d", &d);
        vector<int> ps;
        for (int i = 0; i < d; ++i) {
            int t;
            scanf("%d", &t);
            ps.push_back(t);
        }

        int best = MAX;
        for (int i = 1; i < MAX; ++i) {
            int c = i;
            for (auto t: ps) c += (t+i-1)/i-1;
            if (best > c) best = c;
        }

        printf("Case #%d: %d\n", zz, best);
    }

    return 0;
}
