#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int A, N;
int S[1000000];

int main() {
    int T; scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        
        scanf("%d%d", &A, &N);
        for (int i=0; i<N; i++)
            scanf("%d", &S[i]);
        
        
        int result = 0x7fffffff;
        
        if (A==1) {
            result = N;
        }
        else {
        
            sort(S, S+N);
            
            long long a = A;
            int added = 0;
            for (int i=0; i<N; i++) {
                result = min(result, N-i+added);
                while (a<=S[i])
                    a=a+a-1, added++;
                a+=S[i];
            }
            result = min(result, added);
        }
        
        printf("Case #%d: %d\n", t, result);
    }
    
    return 0;
}
