#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int n;
char s[1002];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d", &n);
		scanf("%s", s);
		
		int res = 0, clapping = 0;

		for(int i = 0; i <= n; i++)
		if (s[i] != '0')
		{
			if (clapping < i)
			{
				res += i - clapping;
				clapping = i;
			}

			clapping += s[i] - '0'; 
		}

		printf("%d\n", res);
	}
	return 0;
}