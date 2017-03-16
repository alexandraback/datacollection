#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int n, m;

int a[105][105];
bool ur[105];
bool uc[105];

void CheckR(int r, int h)
{
	for(int j = 0; j < m; j++)
	{
		if(!uc[j])
		{
			if(a[r][j] != h)
				return;
		}
	}
	ur[r] = 1;
}


void CheckC(int c, int h)
{
	for(int i = 0; i < n; i++)
	{
		if(!ur[i])
		{
			if(a[i][c] != h)
				return;
		}
	}
	uc[c] = 1;
}
int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T, tc = 1;
	scanf("%d", &T);
	while(T > 0)
	{
		printf("Case #%d: ", tc);
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);

		memset(ur, 0, sizeof(ur));
		memset(uc, 0, sizeof(uc));

		bool totBr = 0;

		for(int h = 1; h <= 100; h++)
		{
			for(int i = 0; i < n; i++)
			{
				if(!ur[i])
				{
					CheckR(i, h);
					if(ur[i])
						continue;
					for(int j = 0; j < m; j++)
					{
						if(!uc[j])
						{
							if(a[i][j] == h)
							{
								CheckC(j, h);
								if(!uc[j])
								{
									totBr = 1;
									break;
								}
							}
						}
					}
				}
				if(totBr)
					break;
			}
			if(totBr)
				break;
		}
		if(totBr)
			printf("NO\n");
		else
			printf("YES\n");

		T--;
		tc++;
	}

	return 0;
}