#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isVow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main()
{
    int i, j, k, n, pn = 1;
    char s[1000];
	scanf("%*d");
    while (scanf("%s%d", s, &n) == 2) {
        int cnt = 0;
        int l = strlen(s);
        int sol = 0;
        for (i = 0; i < l; i++) {
            for (j = i; j < l; j++) {
                cnt = 0;
                for (k = i; k <= j; k++) {
                    if (!isVow(s[k])) {
                        cnt++;
                        if (cnt >= n) break;
                    }
                    else cnt = 0;
                }
                if (cnt >= n) {
                    //for (k = i; k <= j; k++) printf("%c", s[k]);
                    //puts("");
                    sol++;
                }                
            }
        }
        printf("Case #%d: %d\n", pn++, sol);
    }
}