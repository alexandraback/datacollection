// complete-search - O(2^n)
#include <bits/stdc++.h>

using namespace std;

int test, n, res;
char s1[1010][50], s2[1010][50];
bool isReal[1010];

void Try(int p)
{
	if (p == n)
	{
		int total = 0;
		for (int i = 0; i < n; ++i)
			total += (isReal[i] == false);
		if (total <= res)
			return;
		map<string, int> mp1, mp2;
		for (int i = 0; i < n; ++i)
		if (isReal[i])
			mp1[s1[i]] = 1, mp2[s2[i]] = 1;
		for (int i = 0; i < n; ++i)
		if (!isReal[i])
		{
			if (mp1[s1[i]] == 0)
				return;
			if (mp2[s2[i]] == 0)
				return;
		}
		res = total;
		return;
	}

	isReal[p] = true;
	Try(p+1);
	isReal[p] = false;
	Try(p+1);
}

int main()
{
	scanf("%d", &test);

	for (int tt = 1; tt <= test; ++tt)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
			scanf("%s %s", s1[i], s2[i]);

		res = 0;
		Try(0);
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}