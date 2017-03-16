#include <cstdio>
#include <cassert>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;
struct State {
    vector<int> ps;
    int spent;
};

int main() {
    int t;
    scanf("%d", &t);
    for (int zz = 1; zz <= t; ++zz) {
        int d;
        scanf("%d", &d);
        vector<int> ps(MAX, 0);
        for (int i = 0; i < d; ++i) {
            int t;
            scanf("%d", &t);
            assert(t < MAX);
            ps[t]++;
        }

        int best = 0;
        for (int i = MAX; i; ) {
            --i;
            if (ps[i]) { best = i; break; }
        }
        ps.resize(best+1);

        queue<State> q;
        q.push(State{ps, 0});

        while (!q.empty()) {
            const State s = q.front();
            q.pop();

            const int mi = s.ps.size()-1;

#if 0
            for (int i = 1; i < s.ps.size(); ++i)
                printf("%d:%d ", i, s.ps[i]);
            printf("-> %d(spent %d)\n", mi + s.spent, s.spent);
#endif

            for (int i = 2; s.spent + i - 1 < best; ++i) {
                State ss = s;
                ss.spent += ss.ps[mi]*(i-1);

                int p = mi%i;
                ss.ps[mi/i] += ss.ps[mi] * (i-p);
                ss.ps[mi/i + 1] += ss.ps[mi] * p;
                ss.ps[mi] = 0;

                int new_mi = mi;
                while (!ss.ps[new_mi]) --new_mi;
                ss.ps.resize(new_mi+1);

                // if (ss.spent + new_mi >= best) break;
                best = min(best, new_mi + ss.spent);
#if 0
                printf("split by %d\n", i);
#endif
                q.push(ss);
            }
            assert(q.size() < 10000000);
        }

        printf("Case #%d: %d\n", zz, best);
    }

    return 0;
}
