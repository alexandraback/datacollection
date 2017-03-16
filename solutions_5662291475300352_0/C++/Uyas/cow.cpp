#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long D[10], V[10], a[10], b[10];

int main() {
    long long L = 360;
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        int ans = 1;
        int grp; scanf("%d", &grp);
        int n = 0;
        for (int i = 0; i < grp; ++i) {
            int d, num, sp;
            scanf("%d%d%d", &d, &num, &sp);
            for (int j = 0; j < num; ++j) {
                ++n; 
                D[n] = d;
                V[n] = sp + j;
            }
        }
        if (n <= 1) ans = 0; else {
            if (V[1] < V[2]) {
                swap(V[1], V[2]);
                swap(D[1], D[2]);
            }
            // V[1] < V[2] now
            if ( (L - D[1]) * V[1] < (2*L-D[2])*V[2] )
                ans = 0; else ans = 1;
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

        
        
