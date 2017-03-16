#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 110
int a[N], b[N];
int main()
{
	int ts, t, i, n, k, j, h;
	for(scanf("%d", &ts), t=1; t<=ts; printf("Case #%d: %d\n", t, j), t++)
	{
		for(scanf("%d%d%d", &n, &k, &h), i=0; i<n; scanf("%d", &a[i]), i++);
		sort(a, a+n);
		for(i=0; i<n; i++)
			if(a[i]<2 || a[i]>28) b[i]=a[i];
			else { b[i]=(a[i]+4)/3; a[i]=(a[i]+2)/3; }
		for(j=0, i=n-1; i>=0; i--)
			if(a[i]>=h) j++;
			else if(b[i]>=h && k>0) { k--; j++; }
	}
	return 0;
}