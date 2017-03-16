#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cases, kejs;
int i, j, n;
int p[10];
char a[10][200];
char s[100000];
char cl[10], cp[10];

int main() {
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        fprintf(stderr, "Case #%d: ", kejs);
				scanf("%d", &n);
				for (i = 0; i < n; i++) {
					scanf("%s", a[i]);
					p[i] = i;
				}
				j = 0;
				do {
					s[0] = '\0';
					for (i = 0; i < n; i++) {
						strcat(s, a[p[i]]);
					}
					int k;
					int cnta[400];
					for (k = 'a'; k <= 'z'; k++) {
						cnta[k] = 0;
					}
						for (i = 0; s[i]; i++) {
							if (cnta[s[i]] > 0 && s[i-1] != s[i]) break;
							cnta[s[i]]++;
						}
					if (!s[i]) j++;
				} while (next_permutation(p, p+n));
				printf("%d\n", j);
    }
    return 0;
}

