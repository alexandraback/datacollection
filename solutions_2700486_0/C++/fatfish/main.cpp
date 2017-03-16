#include <stdio.h>
#include <math.h>

int n, x, y;
void inputData()
{
	scanf("%d%d%d", &n, &x, &y);
}

double CC(int m, int a)
{
	double ret = 1.0;
	for (int i = 0; i < a; ++ i)
	{
		ret *= (m - i);
		ret /= (a - i);
	}

	return ret;
}

double selectRemain(int m, int a)
{
	double ret = 0.0;
	for (int i = a; i <= m; ++ i)
	{
		if (i * 2 > m)
		{
			ret += CC(m, m - i);
		}
		else
		{
			ret += CC(m, i);
		}
	}
	
	return ret * pow(0.5, m);
}

double process()
{
	int m = 1;
	for (m = 1; m <= n; m += 2)
	{
		if (m * (m + 1) > 2 * n)
		{
			break;
		}
	}

	m -= 2;
	int maxPos = m - 1;
	
	if (x < 0)
	{
		x = 0 - x;
	}

	if (x + y <= maxPos)
	{
		return 1.0;
	}
	
	int remain = n - m * (m + 1) / 2;
	if (remain == 0)
	{
		return 0.0;
	}
	
	if (x + y > maxPos + 2)
	{
		return 0.0;
	}
	
	if (y + 1 > remain || x == 0)
	{
		return 0.0;
	}
	
	++ m;
	++ y;
	if (remain > m)
	{
		int leastY = remain - m;
		if (y <= leastY)
		{
			return 1.0;
		}

		y -= leastY;
		remain -= 2 * leastY;
	}
	return selectRemain(remain, y);
}

int main()
{
	//freopen("E:\\codejam\\B\\B-small-attempt5.in", "r", stdin);
	//freopen("E:\\codejam\\B\\B.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; ++ i)
	{
		inputData();
		printf("Case #%d: %f\n", i, process());
	}

	//printf("%f\n", 1.0);
	
	return 0;
}