#include <cstdio>
#include <algorithm>

using namespace std;


int A;
int N;
int sizes[100];

int main() {
    int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        int i, j;
        
        scanf("%d%d", &A, &N);
        for (i = 0; i < N; i++)
            scanf("%d", &sizes[i]);
        
        sort(sizes, sizes+N);
        
        int ans = N;
        int eaten = 0;
        for (j = 0; j < N; j++) {
            for (;sizes[eaten] < A && eaten < N; eaten++)
                A+=sizes[eaten];
            if (j + (N-eaten) < ans)
                ans = j + (N-eaten);
            if (eaten == N)
                break;
            A = A + A - 1;
        }
        
        printf("Case #%d: %d\n", T, ans);
    }
}