#include <cstdio>

int main(int argc, char const *argv[])
{
    int tests;
    scanf("%d", &tests);
    for(int t = 1; t <= tests; t++) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        int min = N*M;
        if(K > min-4) {
            min = 2*(N+M-2)-(min-K);  
        } else { 
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= M; j++) {
                    if(i*j >= K) {
                        if(i == 1 || j == 1) {
                            if(i + j -1 < min) {
                                min = i + j - 1;
                            }
                        } else if (i == 2 || j == 2) {
                            if(i + j < min) {
                                min = i + j;
                            }
                        } else {
                            if(i*j >= K+4) {
                                if(2*(i+j-2)-4 < min) {
                                    min = 2*(i+j-2)-4;
                                }    
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", t, min);
    }
    return 0;
}