#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int q = 1; q <= T; q++)
	{
		long long r,t;
		scanf("%lld%lld",&r,&t);
		double D = ( (double) (2 * r - 1) ) * ((double) (2 * r - 1)) + 8.0 * t;
		double x = (sqrt(D) - ((double) (2 * r - 1))) / 4;
		long long ans = (long long)x;
		while (true)
		{
			double diff = ((double) (2 * r) + 2 * ans - 1) * ans - t;
			if (diff > 1e-9)
				ans--; else
				break;
		}
		printf("Case #%d: %lld\n",q,ans);
	}
	return 0;
}