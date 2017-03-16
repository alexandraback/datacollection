#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long int LL;
typedef pair<int,int> PII;

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t) {
        int A, B, K;
        scanf("%d%d%d", &A, &B, &K);
        int r = 0;
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < B; ++j) {
                int w = i&j;
                if (w < K)
                    r++;
            }
    
        printf("Case #%d: %d\n", t, r);
    }

    return EXIT_SUCCESS;
}
