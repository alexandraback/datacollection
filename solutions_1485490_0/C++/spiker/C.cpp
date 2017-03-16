#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue> 
using namespace std;
long long a[200], b[200];
int A[200], B[200];
long long solve(int n, int m)
{
	if (!n || !m)
		return 0;
	long long ans = 0;
	for (int i = 1; i <= 100; i++)
	{
		int N = n, M = m;
		while (N && A[N-1] != i)
			N--;
		while (M && B[M-1] != i)
			M--;
		if (N && M)
		{
			long long tmp1 = min(a[N-1], b[M-1]);
			long long tmp = tmp1;
			a[N-1] -= tmp;
			b[M-1] -= tmp;
			if (a[N-1] == 0)
				N--;
			if (b[M-1] == 0)
				M--;
			tmp += solve(N,M);
			ans = max(ans,tmp);
			if (a[N] == 0)
				N++;
			if (b[M] == 0)
				M++;
			a[N-1] += tmp1;
			b[M-1] += tmp1;
		}
	}
	return ans;
}
int main(void)
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q = 1; q <= t; q++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i = 0 ;  i < n; i++)
			scanf("%lld %d", &a[i], &A[i]);
		for (int i  = 0 ; i < m; i++)
			scanf("%lld %d", &b[i], &B[i]);
		long long res = solve(n,m);
		printf("Case #%d: %lld\n", q, res);
	}
	return 0;
}