#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isVow(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
char s[1000000 + 20];
int main()
{
    int i, j, k, n, pn = 1;
	scanf("%*d");
    while (scanf("%s%d", s, &n) == 2) {
        int cnt = 0;
        int l = strlen(s);
        long long sol = 0;

        int b = 0;
        bool f = false;
        for (i = 0; i <= l - n; i++) {
            if (f) {
                f = !isVow(s[i + n]);
            }
            else {
                for (j = i; j < i + n; j++) if (isVow(s[j])) break;
                f = i + n == j;
            }            
            if (f) {
                f = true;
                long long v = (long long)(i - b + 1) * (long long)(l - (i + n) + 1);
                sol += v;
                b = i + 1;
            }
        }
        printf("Case #%d: %lld\n", pn++, sol);
    }
}