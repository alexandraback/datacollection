#include <cstdio>
#include <vector>
#include <string>
using namespace std;


int B, M;
unsigned G[6];
unsigned C[6];

int main() {
    int Z; scanf("%d", &Z);
    for (int z=1; z<=Z; z++) {
        scanf("%d%d", &B, &M);
        
        for (unsigned p=0; p<(1<<15); p++) {
            G[1] = p&1;
            G[2] = (p>>1)&3;
            G[3] = (p>>3)&7;
            G[4] = (p>>6)&15;
            G[5] = (p>>10)&31;

            C[0] = 1;
            for (int i=1; i<=B; i++) {
                C[i] = 0;
                for (int j=0; j<i; j++)
                    if (G[i] & (1<<j))
                        C[i] += C[j];
            }

            if (C[B-1] == M) {
                printf("Case #%d: POSSIBLE\n", z);
                for (int i=0; i<B; i++) {
                    for (int j=0; j<B; j++)
                        printf("%d", !!(G[j]&(1<<i)));
                    printf("\n");
                }

                goto next;
            }
        
        }
        
        printf("Case #%d: IMPOSSIBLE\n", z);

        next: {}
        
    }
    return 0;
}
