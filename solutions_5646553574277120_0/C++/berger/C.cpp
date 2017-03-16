#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int maxUse, coins, value;
int coin[500];

bool isMakeable(int what) {
    int i;
    for (i = coins-1; i >= 0; i--) {
        if (coin[i] <= what) {
            int remove = min(maxUse * coin[i], (what / coin[i]) * coin[i]);
            what -= remove;
        }
        
    }
    return what == 0;
}

int main() {
    int TT, T;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        scanf("%d%d%d", &maxUse, &coins, &value);
        int i;
        int ans = 0;
        for (i = 0; i < coins; i++)
            scanf("%d", &coin[i]);
        sort(coin, coin+coins);
        int c = 0;
        int use[500] = {0};
        int upto = 0;
        while (c < value) {
            if (!isMakeable(c+1)) {
                ans++;
                coin[coins] = c+1;
                coins++;
                sort(coin, coin+coins);
            }
            
            //can we skip
            for (i = 0; i < coins; i++) {
                if (coin[i] == c+1) {
                    c = (maxUse+1)*coin[i] - 2;
                }
            }
            c++;
        }
        printf("%d\n", ans);
    }
}
        