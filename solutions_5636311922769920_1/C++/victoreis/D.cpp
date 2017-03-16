#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int T, K, C, S; cin >> T;
    for(int tt = 1; tt <= T; tt++){
        cin >> K >> C >> S;
        printf("Case #%d: ", tt);
        int bound = K/C;
        if(K % C) bound++;
        if(S < bound) printf("IMPOSSIBLE");
        else{
            for(int i = 1; i <= K; i += C){
                ll loc = i - 1;
                for(int j = 0; j < min(K - i, C - 1); j++){
                    loc *= K;
                    loc += i + j;
                }
                printf("%I64d ", loc + 1);
            }
        }
        printf("\n");
    }
    return 0;
}

