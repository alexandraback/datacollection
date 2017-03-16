#include <stdio.h>
#include <string.h>


void solve(int no)
{
	char s[255];
	scanf(" %s", s);
	int n = strlen(s);
	int r = 0;
	char c = '+';
	for (int i=n-1; i>=0; i--) {
		if (s[i] == c) {
		} else {
			if (c == '+') c = '-';
			else c = '+';
			r++;
		}
	}
	printf("Case #%d: %d\n", no, r);
}

int main()
{
	int T;
	scanf(" %d", &T);
	for (int i=0; i<T; ++i) {
		solve(i+1);
	}
	return 0;
}
