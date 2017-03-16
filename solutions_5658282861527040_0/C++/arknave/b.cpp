#include <iostream>
#include <cstdio>

using namespace std;
int main() {
    int T, A, B, K;
    scanf("%d", &T);
    for(int casenum=1;casenum<=T;casenum++) {
        scanf("%d %d %d", &A, &B, &K);
        int count = 0;
        for(int a=0;a<A;a++) {
            for(int b=0;b<B;b++) {
                if((a&b) < K) count++;
            }
        }
        printf("Case #%d: %d\n", casenum, count);
    }

    return 0;
}
