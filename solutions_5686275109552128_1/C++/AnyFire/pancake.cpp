#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int T, n;
int a[N];

int work()
{
	scanf("%d", &n), a[0]=0;
	for(int i=1; i<=n; i++) scanf("%d", &a[i]), a[0]=max(a[0],a[i]);
	
	int r(2e9);
	for(int i=1; i<=a[0]; i++)
	{
		int p=i;
		for(int j=1; j<=n; j++) p+=(a[j]-1)/i;
		r=min(r,p);
	}
	return r;
}

int main()
{
	freopen("pancake.in", "r", stdin);
	freopen("pancake.out", "w", stdout);
	
	scanf("%d", &T);
	for(int i=1; i<=T; i++) printf("Case #%d: %d\n", i, work());
	
	return 0;
}
