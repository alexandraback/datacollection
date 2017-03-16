#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>

using namespace std;

const int kMaxN = 12;

int R, N, M, K;
vector<long long> numProd[8001];

struct NumSet {
    int n[kMaxN];
    vector<long long> prod;
};
vector<NumSet> c;
int cnum[kMaxN];

void dfs(int pos) {
    if (pos == N) {
        c.push_back(NumSet());
        NumSet* cSet = &c[c.size() - 1];
        for (int i = 0; i < N; ++i)
            cSet->n[i] = cnum[i];
        for (int i = 0; i < (1 << N); ++i) {
            long long prod = 1;
            for (int j = 0; j < N; ++j)
                if ((1 << j) & i)
                    prod *= cnum[j];
            cSet->prod.push_back(prod);
        }
        sort(cSet->prod.begin(), cSet->prod.end());
        cSet->prod.erase(unique(cSet->prod.begin(), cSet->prod.end()), cSet->prod.end());
        return;
    }
    for (int i = 2; i <= M; ++i) {
        cnum[pos] = i;
        dfs(pos + 1);
    }
}

void solve() {
    dfs(0);
    for (int r = 0; r < R; ++r) {
        sort(numProd[r].begin(), numProd[r].end());
        bool found = false;
        for (int i = 0; i < c.size(); ++i) {
            const NumSet& s = c[i];
            bool matched = true;
            for (int j = 0; j < K; ++j) {
                vector<long long>::const_iterator pos = lower_bound(s.prod.begin(), s.prod.end(), numProd[r][j]);
                if (pos == s.prod.end() || *pos != numProd[r][j]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                found = true;
                for (int j = 0; j < N; ++j)
                    printf("%d", s.n[j]);
                printf("\n");
                break;
            }
        }
        assert(found);
    }
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 1; caseNo <= numCases; ++caseNo) {
        scanf("%d %d %d %d", &R, &N, &M, &K);
        for (int i = 0; i < R; ++i) {
            numProd[i].clear();
            for (int j = 0; j < K; ++j) {
                long long prod;
                scanf("%lld", &prod);
                numProd[i].push_back(prod);
            }
        }
        printf("Case #%d:\n", caseNo);
        solve();
    }
    return 0;
}
