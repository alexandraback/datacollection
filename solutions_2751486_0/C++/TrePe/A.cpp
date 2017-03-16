#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cases, kejs;
int i, j, n, len, k, cnt, res;
char w[1000002];
bool wovel[127];

int main() {
    wovel['a'] = wovel['e'] = wovel['i'] = wovel['o'] = wovel['u'] = true;
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%s%d", w, &n);
        len = strlen(w);
        res = 0;
        for (i = 0; i < len; i++) {
            for (j = i; j < len; j++) {
                cnt = 0;
                bool has = false;
                for (k = i; k <= j; k++) {
                    if (!wovel[(int)w[k]]) cnt++;
                    else {
                        if (cnt >= n) has = true;
                        cnt = 0;
                    }
                }
                if (cnt >= n) has = true;
                if (has) res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
