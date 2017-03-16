#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, N, M, R, K, lixo;
int prob[32], L[32];

bool cmp(int a, int b) {
    return prob[a] > prob[b];
}

int main() {

    scanf("%d",&lixo);
    scanf("%d %d %d %d",&R,&N,&M,&K);
    printf("Case #1:\n");
    n=0;

    while (R--) {
        for (int i=2;i<=M;i++) prob[i]=0;
        for (int i=0;i<K;i++) {
            int prod;
            scanf("%d",&prod);
            for (int d=2;d<=M;d++) if ((prod%d)==0)
                prob[d]++;
        }
        for (int i=0;i<7;i++) L[i] = i+2;
        sort(L,L+7,cmp);
        for (int k=0;k<6;k++) printf("%d",L[0]);
        for (int k=6;k<12;k++) printf("%d",L[k-5]);
        printf("\n");
    }

    return 0;
}
