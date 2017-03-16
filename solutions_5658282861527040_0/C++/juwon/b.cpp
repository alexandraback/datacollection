#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int A, B, K;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%d %d %d", &A, &B, &K);
        int count = 0;
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                if ((i & j) < K) {
                    count++;
                }
            }
        }
        printf("Case #%d: %d\n", cs, count);
    }
    return 0;
}


