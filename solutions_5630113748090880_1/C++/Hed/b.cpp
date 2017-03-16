#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

int T,cas,n,m,a[2505];

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	for (scanf("%d",&T);T;T --)
	{
		printf("Case #%d: ",++cas);
		memset(a,0,sizeof a);
		m = 0;
		scanf("%d",&n);
		fo(i,1,2*n-1)
			fo(j,1,n)
			{
				int x;
				scanf("%d",&x);
				if (x > m) m = x;
				a[x] ^= 1;
			}
		int cnt = 0;
		fo(i,1,m)
			if (a[i] == 1)
			{
				cnt ++;
				if (cnt < n) printf("%d ",i);
				else printf("%d\n",i);
			}
	}
	return 0;
}
