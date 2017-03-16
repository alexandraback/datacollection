#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    
    int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        
        unsigned int a, b, k;
        scanf("%u %u %u", &a, &b, &k);
        unsigned int i, j;
        int ans = 0;
        for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
        if (int(i&j) < k) {
            ans++;
        }}}
        
        printf("%d\n", ans);
    }
    
}