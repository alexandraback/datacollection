#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 1005

using namespace std;

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static pair<int, int> a[MAXN];
	static char b[MAXN][2];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		scanf("%d",&N);
		int i;
		memset(b,0,sizeof(b));
		for (i = 0; i < N; i++)
		{
			int x, y;
			scanf("%d %d",&x,&y);
			a[i] = make_pair(x,-y);
		}
		sort(&(a[0]),&(a[N]));
		for (i = 0; i < N; i++)
		{
			a[i].second *= -1;
		}
		int cnt = 0;
		int res = 0;
		int rem = 2*N;
		i = 0;
		char flag;
		int j;
		printf("Case #%d: ",iT+1);
		while (1)
		{
			flag = 0;
			for (j = 0; j < N; j++)
			{
				if ((b[j][1] == 0) && (a[j].second <= cnt))
				{
					flag = 1;
					if (b[j][0] == 0)
					{
						rem -= 2;
						cnt += 2;
					}
					else
					{
						rem--;
						cnt++;
					}
					b[j][0] = 1;
					b[j][1] = 1;
					res++;
				}
			}
			if (!flag) break;
		}
		while (i < N)
		{
			if (b[i][0]) i++;
			else
			{
				if (a[i].first > cnt) break;
				res++;
				rem--;
				cnt++;
				b[i][0] = 1;
				while (1)
				{
					flag = 0;
					for (j = 0; j < N; j++)
					{
						if ((b[j][1] == 0) && (a[j].second <= cnt))
						{
							flag = 1;
							if (b[j][0] == 0)
							{
								rem -= 2;
								cnt += 2;
							}
							else
							{
								rem--;
								cnt++;
							}
							b[j][0] = 1;
							b[j][1] = 1;
							res++;
						}
					}
					if (!flag) break;
				}
			}
		}
		if ((i < N) || (rem)) printf("Too Bad\n");
		else printf("%d\n",res);
	}
	return 0;
}
