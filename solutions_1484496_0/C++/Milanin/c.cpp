#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#define N 100
#define K 1100000
using namespace std;
int a[N], s[K], u[K];
bool cmp(int i, int j) { return s[i]<s[j]; }
int main()
{
	int t, ts, i, j, n, f;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		for(scanf("%d", &n), i=0; i<n; scanf("%d", &a[i]), i++);
		for(i=0; i<(1<<n); u[i]=i, i++)
			for(s[i]=0, j=0; j<n; j++)
				if((i>>j)&1) s[i]+=a[j];
		sort(u, u+(1<<n), cmp);
		for(i=0; i<(1<<n)-1 && s[u[i]]<s[u[i+1]]; i++);
		printf("Case #%d:\n", t);
		if(i<(1<<n)-1)
		{
			for(f=0, j=0; j<n; j++)
				if((u[i]>>j)&1) { if(f) printf(" "); f=1; printf("%d", a[j]); }
			printf("\n");
			for(f=0, j=0; j<n; j++)
				if((u[i+1]>>j)&1) { if(f) printf(" "); f=1; printf("%d", a[j]); }
			printf("\n");
		}
		else printf("Impossible\n");
	}
	return 0;
}