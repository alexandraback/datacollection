#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 110
#define K 2000010
int a[N], d[K], p[K];
int main()
{
	int r, n, i, j, k, l, t, ts, b;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		for(scanf("%d%d", &b, &n), i=0; i<n; scanf("%d", &a[i]), i++);
		sort(a, a+n);
		for(i=0; i<K; d[i]=n, i++);
		d[b]=0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<K; p[j]=n, j++);
			for(j=0; j<K; j++)
			{
				if(d[j]==n) continue;
				p[j]=min(p[j], d[j]+1);
				if(j>1)
				{
					for(l=0, k=j; k<=a[i]; l++, k=k*2-1);
					k+=a[i];
					k=min(k, K-1);
					p[k]=min(p[k], d[j]+l);
				}
			}
			for(j=0; j<K; d[j]=p[j], j++);
		}
		for(r=n, i=0; i<K; r=min(r, d[i]), i++);
		printf("%d\n", r);
	}
	return 0;
}
