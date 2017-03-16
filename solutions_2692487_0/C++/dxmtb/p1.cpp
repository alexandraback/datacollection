#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int A, N;
int mote[MAXN];
int d[MAXN][105];

void solve()
{
	scanf("%d%d", &A, &N);
	for(int i = 0;i < N;i++)
		scanf("%d", mote+i);
	sort(mote, mote + N);
	memset(d, 0, sizeof(d));
	d[0][0] = A;
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j <= 100;j++)
			if (d[i][j] != 0)
			{
				if (d[i][j] > mote[i])
				{
					int nd = d[i][j] + mote[i];
					if (nd > d[i+1][j])
						d[i+1][j] = nd;
				}
				else
				{
					//remove
					int nd = d[i][j];
					if (j+1 < 100 && nd > d[i+1][j+1])
					{
						d[i+1][j+1] = nd;
					}
					//add
					nd = d[i][j] + d[i][j] - 1;
					if (j+1 < 100 && nd > d[i][j+1])
					{
						d[i][j+1] = nd;
					}
				}
			}
	}
	for(int j = 0; j< 100;j++)
		if (d[N][j] != 0)
		{
			printf("%d\n", j);
			return;
		}
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T;i ++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
