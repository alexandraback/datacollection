#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 128;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	freopen("A-small-attempt4.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	
	//freopen("A-large-practice.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int i, j, k;
	int cas;
	int T;
	scanf("%d", &T);
	int a[256], b[256];
	for(cas = 1; cas <= T; cas ++)
	{
		int n;
		double sum = 0;
		scanf("%d", &n);
		for(i = 0; i < n; i ++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
			sum += a[i];
		}
		sort(b, b+n);
		double y[256], sumy = 0;
		for(i = 0; i < n; i ++)
		{
			y[i] = (2.0*sum-n*a[i])/(n*sum);
			double ss = 0, tmp;
			for(j = 0; j < n; j ++)
			{
				ss += b[j];
				if(b[j] >= a[i])
				{
					tmp = (ss + sum - (j+1)*a[i]) / ((j+1)*sum);
				}
				else {
					tmp = (ss + sum - (j+1)*a[i]) / ((j+2)*sum);
				}
				//printf("%d %lf\n", a[i], tmp);
				if(tmp < y[i])y[i] = tmp;
			}
			if(y[i] < 0)y[i] = 0;
			//sumy += y[i];
		}
		printf("Case #%d:", cas);
		for(i = 0; i < n; i ++)
		{
			printf(" %lf", y[i]*100);
		}
		putchar('\n');
	}
	return 0;
}
