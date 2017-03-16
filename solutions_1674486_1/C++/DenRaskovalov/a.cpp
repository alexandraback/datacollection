#include <cstdio>
#include <cassert>

#include <vector>

using namespace std;

typedef vector<int> TIntVector;
typedef vector<TIntVector> TGraph;

void DFS(const TGraph& g, size_t index, TIntVector& counts) {
    ++counts[index];
    if (counts[index] < 2) {
        for (size_t i = 0; i < g[index].size(); ++i)
            DFS(g, g[index][i], counts);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt","w", stdout);

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out","w", stdout);

    int nTests;
    scanf("%d", &nTests);
    for (int iTest = 0; iTest < nTests; ++iTest) {
        int n;
        scanf("%d", &n);
        TGraph g(n);
        for (size_t i = 0; i < n; ++i) {
            int m;
            scanf("%d", &m);
            for (size_t j = 0; j < m; ++j) {
                int k;
                scanf("%d", &k);
                --k;
                g[k].push_back(i);
            }
        }

        bool hasDiamond = false;
        for (size_t i = 0; (i < n) && !hasDiamond; ++i) {
            TIntVector counts(n);
            DFS(g, i, counts);
            for (size_t j = 0; j < n; ++j)
                if (counts[j] > 1)
                    hasDiamond = true;
        }
        
        printf("Case #%d: ", iTest + 1);
        fprintf(stderr, "Case #%d: ", iTest + 1);
        if (hasDiamond)
            printf("Yes");
        else
            printf("No");
        printf("\n");
    }

    return 0;
}