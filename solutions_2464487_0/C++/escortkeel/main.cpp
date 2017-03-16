#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    freopen("bull.txt", "r", stdin);
    freopen("bull.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++) {
        long long R, M, ans = 0;
        scanf("%lld %lld", &R, &M);
        
        while(M >= 0) {
            M -= (R + 1)*(R + 1) - (R)*(R);
            R += 2;
            ans++;
        }
        
        printf("Case #%d: %lld\n", i + 1, ans - 1);
    }

    return 0;
}

