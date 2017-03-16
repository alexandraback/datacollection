#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 110
#define MAX 1000100

int n, a, s[MAXN];
int v[MAX], nv;

int main () {
	int teste;
	scanf ("%d", &teste);
	for (int t = 0; t < teste; t++) {
		scanf ("%d %d", &a, &n);
		for (int i = 0; i < n; i++)
			scanf ("%d", &s[i]);
		sort (s, s + n);
		nv = 0;
		int ret = n;
		int c = a;
		for (int i = 0; i < n && c > 1; i++) {
			if (c > s[i]) {
				c += s[i];
				ret = min (ret, nv + n - i - 1);
			}
			else {
                while (c <= s[i]) {
                    ret = min (ret, nv + n - i);
                    c += c - 1;
                    nv++;
                    ret = min (ret, nv + n - i - 1);
                }
                c += s[i];
				ret = min (ret, nv + n - i - 1);
			}
		}
		printf ("Case #%d: %d\n", t + 1, ret);
	}
	return 0;
}
