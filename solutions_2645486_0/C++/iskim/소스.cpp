#include <stdio.h>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

int v[10000000];
int e,r,n;
map<pair<int,int>, int> A;

int getmax(int N, int R)
{
	if (N == -1) return 0;
	auto ret = A.insert(make_pair(make_pair(N, R), 0));
	int ans = 0;
	if (ret.second)
	{
		int i;
		for (i = R; i < r; i++)
		{
			ans = max(ans, getmax(N - 1, 0) + v[N] * (r - i));
		}
		for (; i <= e; i++)
		{
			ans = max(ans, getmax(N - 1, i - r) + v[N] * (i - R));
		}
		return ret.first->second = ans;
	}
	else return ret.first->second;	
}

int main()
{
	int T;
	freopen("c:\\temp\\b.in","r",stdin);
	freopen("c:\\temp\\b.out","w",stdout);
	scanf("%d",&T);
	for (int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);

		scanf("%d%d%d",&e,&r,&n);if(r>e) r=e;

		for (int i = 0; i < n; i++)
		{
			scanf("%d",&v[i]);
		}

		getmax(1, 2);

		printf("%d\n", getmax(n - 1, 0));

		A.clear();
	}
	return 0;
}