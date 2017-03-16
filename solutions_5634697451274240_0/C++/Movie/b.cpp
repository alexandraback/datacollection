#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char s[101];

int main (void)
{
	int T;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		scanf ("%s", s);

		int sum = 0;

		for (int i = strlen (s) - 1; i >= 0; i--)
		{
			if (s[i] == s[i + 1]) continue;

			if (s[i] == '+')
			{
				if (sum%2 == 1) sum++;
			}
			else
			{
				if (sum%2 == 0) sum++;
			}
		}

		printf ("Case #%d: %d\n", t, sum);
	}
}