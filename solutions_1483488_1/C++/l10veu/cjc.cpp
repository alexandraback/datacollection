#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 2000001;

bool visit[MAX];
char ds[15];

int toi(char* a, int f, int t)
{
	int i = 0;

	for (char* c = a+f; c != a+t; ++c)
		i = i*10 + ((*c)-'0');

	return i;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		std::fill(visit, visit+MAX, false);

		long long res = 0;
		
		for (int i=a; i<=b; ++i)
		{
			if (visit[i])
				continue;
			
			sprintf(ds, "%d", i);
			int dc = strlen(ds);
			sprintf(ds+dc, "%d", i);
			
			long long cnt = 0;
			for (int j=0; j<dc; ++j)
			{
				int num = toi(ds, j, j+dc);
				if (a<=num && num<=b)
				{
					if (visit[num])
						break;
					
					visit[num] = true;
					cnt++;
				}
			}

			res += cnt*(cnt-1)>>1;
		}

		printf("Case #%d: %lld\n", c, res);
	}
	
	return 0;
}