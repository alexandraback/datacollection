#include <string>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;
vector<string> dict;
char s[1000];
int main(void)
{
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int b[10] = {1,6,15,28};
	for (int q = 1; q <= T; q++)
	{
		int n;
		int x,y;
		scanf("%d",&n);
		scanf("%d%d",&x,&y);
		int j = 0;
		while (b[j] < n)
			j++;
		j *= 2;
		int sum = abs(x) + abs(y);
		if (sum > j)
		{
			printf("Case #%d: 0.0\n",q);
			continue;
		}
		if ((b[j / 2] == n) || (sum < j))
		{
			printf("Case #%d: 1.0\n",q);
			continue;
		}
		int diff = n - b[j / 2-1];
		double a[10][10];
		a[0][0] = 1;
		for (int i = 0; i <= j; i++)
			for (int k = 0; k <= j; k++)
				if (i + k)
				{
					a[i][k] = 0;
					if (i)
					{
						if (k == j)
							a[i][k] += a[i-1][k]; else
							a[i][k] += a[i-1][k] * 1/2;
					}
					if (k)
					{
						if (i == j)
							a[i][k] += a[i][k-1]; else
							a[i][k] += a[i][k-1] * 1/2;
					}
				}
		double res = 0;
		for (int i = 0 ; i <= j; i++)
			for (int k = 0; k <= j; k++)
			{
				if (((i + k) == diff) && (((x > 0) && (k >= (y+1))) || ((x < 0) && (i >= (y+1)))))
					res += a[i][k];
			}
		printf("Case #%d: %.6lf\n",q,res);
	}
	return 0;
}