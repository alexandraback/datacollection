#include <cstdio>
#include <cstdlib>
#include <cstring>


int calculate_indices(int K, int C, int S, unsigned long long *indices) {
    int k_index = 0;
    int i = 0;
    bool done = false;

    for (i = 0; i < K && !done; ++i) {

        if (i == S) {
            return -1;
        }

        unsigned long long index = 0;
        //fprintf(stderr, "i: %d\n", i);
        for (int j = 0; j < C; ++j) {
            //fprintf(stderr, "k index: %d\n", k_index);
            index *= K;
            index += k_index;
            if (k_index + 1 < K) {
                k_index++;
            } else {
                done = true;
            }
        }
        //fprintf(stderr, "\n");
        indices[i] = index;

    }

    return i;
}


int main() {
    int T, K, C, S;
    unsigned long long indices[101];

    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        scanf("%d", &K);
        scanf("%d", &C);
        scanf("%d", &S);
        int num_of_indices = calculate_indices(K, C, S, indices);
        if (num_of_indices >= 0) {
            printf("Case #%d:", i + 1);
            for (int j = 0; j < num_of_indices; ++j) {
                printf(" %llu", indices[j] + 1L);
            }
            printf("\n");
        } else {
            printf("Case #%d: IMPOSSIBLE\n", i + 1);
        }
    }
}
