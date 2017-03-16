#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int bits[100];

int main() {
    int T;
    scanf("%d", &T);
    for(int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);

        int B;
        long long M;
        scanf("%d %lld", &B, &M);

        if((1LL << (B-2)) < M) {
            printf("IMPOSSIBLE\n");
            continue;
        }
        else {
            --M;
            printf("POSSIBLE\n");
            for(int i = 0; i < 100; ++i) bits[i] = 0;
            long long x = M;
            int pos = 0;
            while(x != 0) {
                if(x % 2 != 0) {
                    bits[pos] = 1;
                }
                x /= 2;
                ++pos;
                // printf("pos = %d\n", pos);
            }
            string res = "1";
            for(int i = B - 2; i > 0; --i) {
                if(bits[B - 2 - i] == 1)
                    res = "1" + res;
                else
                    res = "0" + res;
            }
            res = "0" + res;
            printf("%s\n", res.c_str());
            for(int i = 1; i < B; ++i) {
                for(int j = 0; j <= i; ++j)
                    printf("0");
                for(int j = i + 1; j < B; ++j)
                    printf("1");
                printf("\n");
            }
        }
    }

    return 0;
}
