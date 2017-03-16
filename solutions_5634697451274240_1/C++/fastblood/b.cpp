#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long lint;
typedef unsigned long long ull;

#define pb push_back
#define mp make_pair

char s[105];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%s", s);
		int n = strlen(s);
		int ans = 0;
		while (true)
		{
			int ind = -1;
			for (int j = n - 1; j >= 0 && ind == -1; j--)
				if (s[j] == '-')
					ind = j;

			if (ind == -1)
				break;

			ans++;
			for (int j = 0; j <= ind; j++)
				s[j] = (s[j] == '-') ? '+' : '-';
		}

		printf("Case #%d: %d\n", i + 1, ans);
	}
}
