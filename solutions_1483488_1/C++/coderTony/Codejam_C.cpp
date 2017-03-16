//acm header include 
#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<map>
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
//#ifndef ONLINE_JUDGE
//	freopen("data.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//#endif

	int T, t, A, B, m, n;

	scanf("%d", &T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d%d", &A, &B);
		map<pair<int,int>, bool> vis;
		int ans = 0;
		for (n=A; n<B; ++n)
		{
			for (int k=10; k<n; k*=10)
			{				
				m = shift(n, k);
				if (m<=B && n<m && vis.find(make_pair(n, m)) == vis.end()) {
					vis[make_pair(n,m)] = 1;
					++ans;
				}
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
