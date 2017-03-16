#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cases, kejs;
int i, j, n, len, k, cnt;
long long res;
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
        cnt = 0;
        j = -1;
        for (i = 0; i < len; i++) {
            if (!wovel[(int)w[i]]) {
                cnt++;
				if (cnt >= n) j = i - n + 1;
            } else {
                cnt = 0;
            }
			if (j > -1) {
				res += j + 1;
			}
        }
        printf("%lld\n", res);
    }
    return 0;
}

