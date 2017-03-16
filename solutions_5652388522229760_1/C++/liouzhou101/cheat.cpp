#include <cstdio>
#include <cstdlib>
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
		int n;
		scanf("%d", &n);
		if (n==0)
		{
			puts("INSOMNIA");
			continue;
		}
		bitset<10> s;
		for (int x=n; ; x+=n)
		{
			for (int y=x; y; y/=10)
				s[y%10]=1;
			if (s.all())
			{
				printf("%d\n", x);
				break;
			}
		}
	}
	return 0;
}
