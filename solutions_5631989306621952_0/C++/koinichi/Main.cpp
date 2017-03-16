#include <stdio.h>


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	int _n;
	scanf("%d", &_n);

	for (int _t=1; _t<=_n; _t++) {
		char s[1010] = {0}, ret[2010] = {0};
		int x = 1005, y = 1005;
		scanf("%s", s+1);
		for (int i=1; s[i]; i++) {
			if (s[i] >= ret[x]) {
				ret[--x] = s[i];
			}
			else {
				ret[y++] = s[i];
			}
		}
		printf("Case #%d: %s\n", _t, ret + x);
	}
}
