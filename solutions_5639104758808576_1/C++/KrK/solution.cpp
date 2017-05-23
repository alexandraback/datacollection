#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxn = 1005;

int t;
int len;
int cur;
char s[Maxn];
int res;

int main()
{
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %s", &len, s);
		cur = 0; res = 0;
		for (int i = 0; i <= len; i++) {
			while (cur < i) cur++, res++;
			cur += s[i] - '0';
		}
		printf("Case #%d: %d\n", tc, res);
	}
	return 0;
}