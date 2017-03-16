#include <iostream>
#include <cstring>

#define MAXH 2501

using namespace std;

bool fallAsleep(int D[]);

void doCase(int iCase) {
    printf("Case #%d:", iCase);
    
    int N; scanf("%d", &N);
    int H[MAXH]; memset(H, 0, sizeof(H));
    
    for (int i=0; i<2*N-1; i++) {
        for (int j=0; j<N; j++) {
            int V; scanf("%d", &V);
            H[V]++;
        }
    }
    
    int S[51]; int nS=0;
    for (int i=0; i<MAXH; i++) {
        if (H[i] % 2 == 1) {
            S[nS] = i;
            nS++;
        }
    }
    
    sort(S, S+nS);
    
    for (int i=0; i<nS; i++) {
        printf(" %d", S[i]);
    }
    
    puts("");
}

int main(void) {
    int T; scanf("%d", &T);
    for (int i=1; i<=T; i++) doCase(i);
    return 0;
}