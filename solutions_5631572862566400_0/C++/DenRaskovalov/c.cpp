#include <cstdio>

#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int iTest = 0; iTest < t; ++iTest) {
        int n;
        scanf("%d", &n);
        using IntVector = vector<int>;
        IntVector f(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &(f[i]));
            --f[i];
        }

        int best = 0;
        IntVector indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        IntVector cycle;
        for (int mask = 0; mask < (1 << n); ++mask) {
                cycle.clear();
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        cycle.push_back(i);
                    }
                }

                if (cycle.size() > best) {
        do {
                int i = 0;
                    for (i = 0; i < cycle.size(); ++i) {
                        int next = i + 1;
                        if (next == cycle.size()) {
                            next = 0;
                        }
                        int prev = i + cycle.size() - 1;
                        if (prev >= cycle.size()) {
                            prev -= cycle.size();
                        }
                        if (f[cycle[i]] != cycle[prev] && f[cycle[i]] != cycle[next]) {
                            break;
                        }
                    }

                    if (i == cycle.size()) {
                        best = cycle.size();
                    }
        } while (next_permutation(cycle.begin(), cycle.end()));
    }
}

        printf("Case #%d: %d\n", iTest + 1, best);
    }

    return 0;

}
