#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void
solve()
{
	const int MAXLEN = 200;
	char buf[MAXLEN + 1];
	fgets(buf, MAXLEN, stdin);
	int n = strlen(buf);
	while (n > 0 && isspace(buf[n - 1])) n--;
	buf[n] = '+';
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += (buf[i] != buf[i + 1]);
	}
	printf("%d\n", res);
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
