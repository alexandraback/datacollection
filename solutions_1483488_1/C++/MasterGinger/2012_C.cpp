#include <stdio.h>
#include <string.h>
#include <set>
#include <string>
using namespace std;
int p[8] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
char num[100];

int main()
{
	int n, nc;
	scanf("%d", &n);
	for (int nc = 1; nc <= n; nc++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int total = 0;
		set<int> s;
		for (int i = a; i <= b; i++)
		{
			s.clear();
			sprintf(num, "%d", i);
			int digits = strlen(num);
			for (int j = 0; j < 8; j++)
			{
				if (i >= p[j])
				{
					int next = i % p[j] * p[digits - j - 2] + i / p[j];
					if (i < next && next <= b)
					{
						//sprintf(num, "%d%d", i, next);
						if (s.find(next) == s.end())
						{
							s.insert(next);
							//printf("%d, %d\n", i, next);
							total++;
						}
					}
				}
				else
				{
					break;
				}
			}
		}

		printf("Case #%d: %d\n", nc, total);
	}

	return 0;
}
