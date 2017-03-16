#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int nArray[MAXN][MAXN];

int main(void) {
    FILE *fp = NULL;
    FILE *fp2 = NULL;
    freopen_s(&fp, "B-small-attempt0.in", "r", stdin);
    freopen_s(&fp2, "B.out", "w", stdout);
    int T;
    while (cin >> T) {
        for (int cas = 1; cas <= T; ++cas) {
            int A;
            int B;
            int K;
            int nSum = 0;
            cin >> A >> B >> K;
            
            for (int i = 0; i < A; ++i) {
                for (int j = 0; j < B; ++j) {
                    if ((i & j) < K) {
                        ++nSum;
                    }
                }
            }
            printf("Case #%d: ", cas);
            printf("%d\n", nSum);
        }
    }
    return 0;
}