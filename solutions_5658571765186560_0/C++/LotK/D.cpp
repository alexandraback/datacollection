#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int tt;
    scanf("%d", &tt);
    for(int t=0; t<tt ; t++) {
        int x, r, c;
        scanf("%d%d%d", &x, &r, &c);
        int ans = 0;
        if(x==3) {
            if(r == 1 || c == 1) ans = 1;
            else {
            }
        }
        else if(x==4) {
            if(r <= 2 || c <= 2) ans = 1;
        }

        // Necessary Condition
        if(r*c % x > 0) ans = 1;
        if(r < x && c < x) ans = 1;

        if(ans == 0) {
            printf("Case #%d: GABRIEL\n", t+1);     // If Gabriel can completely fill in the grid, he wins
        }
        else {
            printf("Case #%d: RICHARD\n", t+1);
        }
    }
}
