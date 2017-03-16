#include <stdio.h>
char buf[200];
int main() {
	int __;
	scanf("%d",&__);
	int c = 1;
	for (; __ > 0; __--) {
		scanf("%s",buf);
		int s = 0;
		int i;
		for (i = 1; buf[i]; i++) {
			if (buf[i] != buf[i-1]) s++;
		}
		if (buf[i-1] != '+') s++;
		printf("Case #%d: %d\n",c++,s);
	}
	return 0;
}

