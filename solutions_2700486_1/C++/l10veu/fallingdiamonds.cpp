#include <cstdio>

int arr[710];
double cp[3000][3000];

int n, x, y;

int main()
{	
	//freopen("C:\\Users\\l10veu\\Documents\\Visual Studio 2008\\Projects\\ProblemSolving\\ProblemSolving\\Debug\\B-small-attempt0.in", "r", stdin);
	
	for (int i=0; ;++i)
	{
		int a = 2*i+1;
		int sum = a*(a+1)/2;
		arr[i] = sum;
		if (sum>1000000)
			break;
	}

	cp[0][0] = 1;
	for (int i=1; i<3000; ++i)
	{
		cp[i][0] = cp[i-1][0] / 2;
		cp[i][i] = cp[i-1][i-1] / 2;
		for (int j=1; j<i; ++j)
			cp[i][j] = (cp[i-1][j-1] + cp[i-1][j])/2;
	}

	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; ++c)
	{
		scanf("%d %d %d", &n, &x, &y);
		if (x<0)
			x = -x;

		int level = (x+y)/2;

		double ans = 0;
		if (level>707)
			ans = 0;
		else if (n>=arr[level])
			ans = 1;
		else if (n<=arr[level-1])
			ans = 0;
		else if (y<2*level)
		{
			int num = arr[level] - arr[level-1];
			int cnt = n - arr[level-1];
			int res = cnt-2*level;
			if (res>=(y+1))
				ans = 1;
			else
			{
				for (int i=y+1; i<=cnt; ++i)
					ans += cp[cnt][i];
			}
		}

		printf("Case #%d: %.7f\n", c, ans);
	}
	
	return 0;
}