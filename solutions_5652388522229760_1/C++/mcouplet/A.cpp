#include<bits/stdc++.h>
using namespace std;

int main() {
    int TC; scanf("%d", &TC);
    for(int t = 0; t < TC; ++t) {
        printf("Case #%d: ", t+1);
        int N; scanf("%d", &N);
        if(N == 0)
            printf("INSOMNIA\n");
        else {
            set<int> dgt;
            for(int m = 1;; ++m) {
                int n = m*N;
                for(; n > 0; n /= 10) dgt.insert(n%10);
                if(dgt.size() == 10) {
                    printf("%d\n", m*N);
                    break;
                }
            }
        }
    }
}

