#include<cstdio>

using namespace std;

int main(){
    int T;
    int K, C, S;

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &K, &C, &S);
        if (S == K) {
            printf("Case #%d:", t);
            for (int k = 1; k <= K; k++)
                printf(" %d", k);
            printf("\n");
        }
    }
    return 0;
}
