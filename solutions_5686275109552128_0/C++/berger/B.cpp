#include <cstdio>

using namespace std;

int d;
int p[2000];

int main() {
	int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        printf("Case #%d: ", T);
        
        scanf("%d", &d);
        int i, j;
        int maxp = 0;
        for (i = 0; i < d; i++) {
            scanf("%d", &p[i]);
            if (p[i] > maxp)
                    maxp = p[i];
        }
        
        int ans = maxp;
        for (i = 1; i <= maxp; i++) {
            int moves = 0;
            for (j = 0; j < d; j++)
                moves += (p[j] - 1) / i;
            if (i + moves < ans)
                ans = i + moves;
        }
        
        printf("%d\n", ans);
    }
}