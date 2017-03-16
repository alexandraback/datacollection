//acm header include 
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

int shift(int n, int k)
{
	if (n%k == n%(k/10))
		return 0;

	int ans = n%k, nn=n/k;
	while (nn) { ans *= 10; nn/=10; }
	ans += n/k;
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T, t, A, B, m, n;

	scanf("%d", &T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d%d", &A, &B);
		int ans = 0;
		for (m=A+1; m<=B; ++m)
		{
			for (int k=10; k<m; k*=10)
			{
				n = shift(m, k);
				if (n>=A && n<m) ++ans;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
