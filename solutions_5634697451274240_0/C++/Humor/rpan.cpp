#include <cstdio>
#include <cstring>

const int N = 100010;
int n;
char s[N];

void solve(int test)
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	s[n + 1] = '+';
	int z = 0;
	for (int i = 1; i <= n; i++) if (s[i] != s[i + 1]) z++;
	printf("Case #%d: %d\n", test, z);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}