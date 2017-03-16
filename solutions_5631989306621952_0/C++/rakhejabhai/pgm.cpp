#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	int T, len, c = 0, lens, i, j;
	char str[1005], s[1005];

	scanf("%d", &T);

	while(T--)
	{
		lens = 1;
		c++;
		scanf("%s", str);

		len = strlen(str);
		s[0] = str[0];
		s[1] = 0;

		for(i = 1; i < len; i++)
		{
			if(str[i] < s[0])
			{
				s[lens] = str[i];
				s[lens + 1] = 0;
				lens++;
			}
			else
			{
				for(j = lens; j >= 0; j--)
				{
					s[j + 1] = s[j];
				}
				s[0] = str[i];
				lens++;
			}
		}
		printf("Case #%d: %s\n", c, s);
	}
	return 0;
}