#include <cstdio>
#include <cstring>

#include <map>
#include <utility>

#include <algorithm>

using namespace std;

const int MAX_N = 20;

int main() {
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int K, N; scanf("%d %d", &K, &N);

        static map<int, int> start;
        start.clear();
        for (int i = 0; i < K; ++i) {
            int k; scanf("%d", &k);
            ++start[k];
        }

        static pair<int, map<int, int> > chest[MAX_N];
        for (int i = 0; i < N; ++i) {
            int k; scanf("%d", &k);
            chest[i].first = k;

            chest[i].second.clear();
            int num; scanf("%d", &num);
            for (int j = 0; j < num; ++j) {
                scanf("%d", &k);
                ++chest[i].second[k];
            }
        }

        static int fp[1 << MAX_N];
        fill(fp, fp + (1 << N), -1);
        fp[(1 << N) - 1] = -2;

        for (int sst = (1 << N) - 1; sst >= 0; --sst) {
            map<int, int> cur = start;
            for (int i = 0; i < N; ++i) {
                if (!(sst & 1 << i)) continue;
                --cur[chest[i].first];
                for (typeof(chest[i].second.begin()) it = chest[i].second.begin();
                        it != chest[i].second.end(); ++it)
                    cur[it->first] += it->second;
            }

            for (int i = 0; i < N; ++i) {
                if (sst & 1 << i || fp[sst ^ 1 << i] == -1 || !cur[chest[i].first]) continue;
                fp[sst] = i;
                break;
            }
        }

        printf("Case #%d:", t + 1);
        if (fp[0] == -1)
            puts(" IMPOSSIBLE");
        else {
            int sst = 0;
            while (fp[sst] != -2) {
                printf(" %d", fp[sst] + 1);
                sst ^= 1 << fp[sst];
            }
            puts("");
        }
    }
}
