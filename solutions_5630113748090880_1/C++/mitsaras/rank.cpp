#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    int T;
    int h[2501];

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= 2500; i++) h[i] = 0;
        for (int i = 1; i <= N*(2*N-1); i++) {
            int he;
            scanf("%d", &he);
            h[he]++;
        }
        printf("Case #%d:", t);
        for (int i = 1; i <= 2500; i++)
            if (h[i] & 1 == 1)
                printf(" %d", i);
        printf("\n");
    }
    return 0;
}
