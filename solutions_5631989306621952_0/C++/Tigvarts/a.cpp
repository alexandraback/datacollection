#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1010];
char was[1010];
int first[26];

void
solve()
{
	fgets(buf, 1005, stdin);
	int n = strlen(buf);
	while (n && isspace(buf[n - 1])) n--;
	char cur = 'A';
	for (int i = 0; i < 26; ++i) {
		first[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		if (first[buf[i] - 'A'] == -1) {
			first[buf[i] - 'A'] = i;
		}
		if (buf[i] > cur) {
			cur = buf[i];
		}
		was[i] = 0;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (buf[i] == cur) {
			was[i] = 1;
			putc(buf[i], stdout);
			while (cur >= 'A' && (first[cur - 'A'] == -1 || first[cur - 'A'] >= i)) cur--;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (was[i] == 0) {
			putc(buf[i], stdout);
		}
	}
	printf("\n");
}

int
main()
{
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
