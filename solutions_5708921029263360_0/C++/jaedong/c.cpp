#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> outfit;
const int MAX = 11;
int used[MAX][MAX][MAX];

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int j, p, s, k;
        scanf("%d%d%d%d", &j, &p, &s, &k);

        memset(used, 0, sizeof(used));
        vector<outfit> sol;
        for (int d1 = 1; d1 <= j; d1++)
            for (int d2 = 1; d2 <= p; d2++)
                for (int d3 = 1; d3 <= s; d3++)
                    if (used[d1][0][d3] < k and used[d1][d2][0] < k and used[0][d2][d3] < k) {
                        used[0][d2][d3]++;
                        used[d1][0][d3]++;
                        used[d1][d2][0]++;
                        sol.emplace_back(d1, d2, d3);
                    }

        printf("Case #%d: %d\n", cs, int(sol.size()));
        for (auto o: sol)
            printf("%d %d %d\n", get<0>(o), get<1>(o), get<2>(o));
    }
}
