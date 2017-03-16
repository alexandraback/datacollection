#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 111;
int n;
char s[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int it = 1; it <= t; it++)
	{
		scanf("%s", s);
		n = strlen(s);
		int ans = (s[n - 1] == '-');
		for (int i = 0; i < n - 1; i++)
			ans += (s[i] != s[i + 1]);
		printf("Case #%d: %d\n", it, ans);
	}

	return 0;
}