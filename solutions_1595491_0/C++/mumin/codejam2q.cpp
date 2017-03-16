#include<cstdio>

using namespace std;

int main()
{
	int t, n, s, p, norm[110], supr[110], x;
	scanf("%d", &t);
	for(int d = 1; d <= t; ++d)
	{
		scanf("%d %d %d", &n, &s, &p);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			if(x % 3 == 0)
			{
				norm[i] = x / 3;
				if(x != 0)
					supr[i] = x / 3 + 1;
				else
					supr[i] = 0;
			}
			if(x % 3 == 1)
			{
				norm[i] = x / 3 + 1;
				supr[i] = x / 3 + 1;
			}
			if(x % 3 == 2)
			{
				norm[i] = x / 3 + 1;
				supr[i] = x / 3 + 2;
			}
		}
		int ans, normp = 0, suprp = 0;
		for(int i = 0; i < n; ++i)
		{
			if(norm[i] >= p)
				normp++;
			if(norm[i] < p && supr[i] >= p)
				suprp++;
		}
		if(suprp > s)
			ans = normp + s;
		else
			ans = normp + suprp;
		printf("Case #%d: %d\n", d, ans);
	}
}