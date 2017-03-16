#include <cstdio>
#include <map>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    int R, N, M, K;
    scanf("%d %d %d %d", &R, &N, &M, &K);
    printf("Case #1:\n");

    for (int z = 1; z <= R; z++) {
        int prod[K];
        for(int i = 0; i < K; i++)
            scanf("%d", &prod[i]);

        int bd1, bd2, bd3, best_prob = 0;
        for(int d1 = 2; d1 <= M; d1++)
            for(int d2 = 2; d2 <= M; d2++)
                for(int d3 = 2; d3 <= M; d3++) {
                    map<int, int> ans;

                    ans[1]++;
                    ans[d1]++; ans[d2]++; ans[d3]++;
                    ans[d1*d2]++; ans[d1*d3]++; ans[d2*d3]++;
                    ans[d1*d2*d3]++;

                    int prob = 1;
                    for(int i = 0; i < K; i++)
                        prob *= ans[prod[i]];

                    if(prob >= best_prob) {
                        bd1 = d1, bd2 = d2, bd3 = d3;
                        best_prob = prob;
                    }
                }

        printf("%d%d%d\n", bd1, bd2, bd3);
    }
}
