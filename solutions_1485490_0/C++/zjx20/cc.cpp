#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;


int n,m;
__int64 a[10];
int A[10];
__int64 b[120];
int B[120];
__int64 ans;

void dfs(int nn, int mm, __int64 num, __int64 rest)
{
	if(nn >= n || mm >= m)
	{
		if(ans == -1 || ans < num) ans = num;
		return;
	}

	if(A[nn] == B[mm])
	{
		__int64 tmp = std::min(rest, b[mm]);
		if(tmp == b[mm] && tmp == rest)
		{
			dfs(nn + 1, mm + 1, num + tmp, a[nn+1]);
		}
		else if(tmp == b[mm] && tmp != rest)
		{
			dfs(nn, mm+1, num+tmp, rest-tmp);
		}
		else if(tmp != b[mm] && tmp == rest)
		{
			dfs(nn+1, mm, num+tmp, a[nn+1]);
		}
	}
	else
	{
		dfs(nn, mm+1, num, rest);
		dfs(nn+1, mm, num, a[nn+1]);
	}
}

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t,ca=0;

	int i,j;

	scanf("%d: ",&t);
	while(t--)
	{
		printf("Case #%d: ",++ca);

		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%I64d%d",&a[i], &A[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%I64d%d",&b[i], &B[i]);
		}

		ans = -1;
		dfs(0,0,0,a[0]);
		printf("%I64d\n", ans);
	}
	return 0;
}