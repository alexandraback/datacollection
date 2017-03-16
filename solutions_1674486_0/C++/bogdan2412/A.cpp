#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int> > con;

bool findDiamond(int root) {
    vector<bool> used(N, false);
    queue<int> Q;

    Q.push(root);
    used[root] = true;
    for (; !Q.empty(); Q.pop()) {
        vector<int> :: iterator it;
        for (it = con[Q.front()].begin(); it != con[Q.front()].end(); it++) {
            if (used[*it]) {
                return true;
            }
            Q.push(*it);
            used[*it] = true;
        }
    }
    return false;
}

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    for (int t = 1; t <= T; t++) {
        assert(scanf("%d", &N) == 1);
        con.clear(); con.resize(N);
        for (int i = 0; i < N; i++) {
            int cnt, parent;
            assert(scanf("%d", &cnt) == 1);
            for (; cnt; cnt--) {
                assert(scanf("%d", &parent) == 1);
                assert(1 <= parent && parent <= N);
                con[parent - 1].push_back(i);
            }
        }

        bool haveDiamond = false;
        for (int i = 0; i < N && !haveDiamond; i++) {
            haveDiamond = findDiamond(i);
        }

        printf("Case #%d: %s\n", t, haveDiamond ? "Yes" : "No");
    }
    return 0;
}
