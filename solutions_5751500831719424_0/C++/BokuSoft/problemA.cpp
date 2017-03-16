#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int t, T, n, cuenta[100][101], i, d, suma, j, sumatotal, m, arr[100], k;
    char s[101], cadenas[100][101], *p;
    scanf("%d", &T);
    bool L;
    for(t = 1;t <= T;t++) {
        scanf("%d", &n);
        printf("Case #%d: ", t);
        L = false;
        for(i = 0;i < n;i++) {
            scanf("%s", s);
            if(L) continue;
            d = 0;
            cadenas[i][0] = s[0];
            cuenta[i][0] = 1;
            for(p = s+1;*p != 0;p++) {
                if(*p == cadenas[i][d]) {
                    cuenta[i][d]++;
                } else {
                    cadenas[i][++d] = *p;
                    cuenta[i][d] = 1;
                }
            }
            cadenas[i][++d] = 0;
            if(i > 0 && strcmp(cadenas[i], cadenas[i-1]) != 0) {
                printf("Fegla Won\n");
                L = true;
                continue;
            }
        }
        if(L) continue;
        sumatotal = 0;
        strcpy(s, cadenas[0]);
        for(i = 0;s[i] != 0;i++) {
            suma = 0;
            for(j = 0;j < n;j++) {
                arr[j] = cuenta[j][i];
                suma += arr[j];
            }
            m = suma;
            sort(arr, arr + n);
            j = 0;
            ///
            ///printf("|||%d|||\n", suma);
            ///
            for(k = 1;k <= 100 && j < n;k++) {
                suma += 2 * j - n;
                if(suma < m) m = suma;
                while(arr[j] == k) j++;
                ///printf("suma=%d|||k=%d|||j=%d|||m=%d\n", suma, k, j, m);
            }
            sumatotal += m;
        }
        printf("%d\n", sumatotal);
    }
    return 0;
}
