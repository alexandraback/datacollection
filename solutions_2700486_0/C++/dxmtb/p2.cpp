#include <cstdio>
#include <cassert>

const int MAXN=2000;

double d[MAXN][MAXN];
int N, X, Y;

void solve()
{
	scanf("%d%d%d", &N, &X, &Y);
	int height = 0;
	while(true)
	{
		height++;
		int tot = (4*height-2)*height/2;
		if (tot > N)
			break;
	}
	height--;
	int tot = (4*height-2)*height/2;

	int left = N - tot;
	int headY = 2*height; //unreach
	int most = headY;

	assert(Y>=0);
	assert(left < 2000);

	if (X < 0)
		X = -X;

	if (X + Y < headY)
	{
		printf("1.0\n");
		return ;
	}
	else if (X + Y > headY || left == 0)
	{
		printf("0.0\n");
		return ;
	}


	if (left - most >= Y+1)
	{
		printf("1.0\n");
		return ;
	}

	d[0][0] = 1;
	for(int i = 1; i <= left; i++)
	{
		for(int j = 0; j <= i; j++)
			if (j <= most && i-j<=most)
			{
				d[j][i-j] = 0;
				if (j - 1 >=0)
				{
					if (i-j == most)
						d[j][i-j] += d[j-1][i-j];
					else
						d[j][i-j] += d[j-1][i-j] * 0.5;
				}
				if (i-j-1 >=0)
				{
					if (j == most)
						d[j][i-j] += d[j][i-j-1];
					else
						d[j][i-j] += d[j][i-j-1] * 0.5;
				}
			}
	}
	double ret = 0;
	for(int i = Y+1; i<=most; i++)
		ret += d[i][left-i];
	printf("%lf\n", ret);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T;i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
