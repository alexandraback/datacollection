#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define INF 1<<30
#define MAXN 10010
#define MOD 1000000007
using namespace std;

double num1[1010] ,num2[1010];
int n;

int solve(double a[] ,double b[])
{
	int j = n - 1;
	int ans = 0;
	for(int i = n - 1;i>=0;i--)
	{
		while(j >=0 && b[j] > a[i])
		{
			j--;
		}
		if(j < 0)
		{
			break;
		}
		j--;
		ans++;
	}
	return ans;
}

int main()
{
	/*freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);*/
	int t;
	scanf("%d",&t);
	for(int r = 1;r <= t;r++)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%lf",&num1[i]);
		}
		sort(num1,num1+n);
		for(int i = 0;i < n;i++)
		{
			scanf("%lf",&num2[i]);
		}
		sort(num2,num2+n);
		int ans1 = solve(num1,num2);
		int ans2 = solve(num2,num1);
		printf("Case #%d: ",r);
		printf("%d %d\n",ans1,n - ans2);
	}
	return 0;
}