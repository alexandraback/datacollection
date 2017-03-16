#include <bits/stdc++.h>

using namespace std;

typedef long long Int;

int solve()
{
	char s[128];

	scanf("%s", s);

	int cnt = 0;
	for (int i = 0; s[i + 1]; i++){
		cnt += s[i] != s[i + 1];
	}

	return (cnt + (s[strlen(s) - 1] == '-'));
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++){
		printf("Case #%d: %d\n", i + 1, solve());
	}

	return (0);
}