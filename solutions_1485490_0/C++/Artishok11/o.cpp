#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <string>
#include <set>

using namespace std;

pair<int,long long> a[200],b[200];
long long f[200][200];
long long ans = 0;
int n,m;

void rec(int t,int i,long long sum)
{
	if (t >= n || i >= m) { ans = max(ans,sum); return; }
	rec(t+1,i,sum);
	if (b[i].first == a[t].first) 
	{
		long long X = min(a[t].second,b[i].second);
		sum += X;
		a[t].second -= X;
		b[i].second -= X;
		if (a[t].second == 0) rec(t+1,i,sum);
		else rec(t,i+1,sum);
		a[t].second += X;
		b[i].second += X;
	}
	else rec(t,i+1,sum);
};

int main()
{
	int T;
	scanf("%d",&T);	
	for (int T_t = 1; T_t <= T; T_t++)
	{
		printf("Case #%d: ",T_t);

 		scanf("%d%d",&n,&m);
		for (int i = 0; i < n; i++)
			scanf("%I64d%d",&a[i].second,&a[i].first);
		for (int i = 0; i < m; i++)
			scanf("%I64d%d",&b[i].second,&b[i].first);

		for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			f[i][j] = 0;
		}
		ans = 0;
		rec(0,0,0);
		printf("%I64d\n",ans);
	}

	return 0;	
}
