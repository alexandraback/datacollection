#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <algorithm>
#include <cstring>

using namespace std;

#define LOCAL_TEST 0

#define rep(i,a,b) for(int i = a;i < b;i++)
#define REP(i,n) rep(i,0,n)
#define per(i,a,b) for(int i = b - 1;i >= a;i--)
#define PER(i,n) per(i,0,n)
#define CLR(v) memset(v,0,sizeof(v))

int f(int n)
{
	int f[10];
	int c = 0;
	int res = -1;
	if (n == 0)
	{
		return res;
	}
	CLR(f);
	for (int i = 1;;i++)
	{
		long long temp = n * i;
		while (temp)
		{
			if (f[temp % 10] == 0)
			{
				f[temp % 10] = 1;
				c++;
			}
			temp /= 10;
		}
		if (c == 10)
		{
			res = n * i;
			break;
		}
	}
	return res;
}

int main()
{
#if !LOCAL_TEST
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	rep(CASE, 1, T + 1)
	{
		long long n;
		scanf("%I64d", &n);
		long long res = f(n);

		printf("Case #%d: ", CASE);
		if (res == -1)
		{
			puts("INSOMNIA");
		}
		else
		{
			printf("%d\n", res);
		}
	}
}