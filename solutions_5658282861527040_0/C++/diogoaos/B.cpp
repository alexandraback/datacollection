#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

typedef long long lint;

using namespace std;


int main() {
    int ntests;
    scanf("%d", &ntests);
    
    for (int test = 1; test <= ntests; test++) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);
        int res = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    res++;
                }
            }
        }
        printf("Case #%d: %d\n", test, res);
    }
}

