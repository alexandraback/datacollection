#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
	freopen("try.in", "r", stdin);
	freopen("try.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int TT=1; TT<=Test; ++TT)
	{
		printf("Case #%d: ", TT);
		char s[111];
		scanf("%s", &s);
		int n = strlen(s);
		s[n]='+';
		int ans = 0;
		for (int i=0; i<n; ++i)
		{
			if (s[i]!=s[i+1])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
