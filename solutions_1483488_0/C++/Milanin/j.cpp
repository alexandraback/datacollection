#include <stdio.h>
#include <algorithm>
using namespace std;
int p[10], m[10];
int main()
{
	int i, j, ts, t, r, a, b, l;
	for(p[0]=1, i=1; i<10; p[i]=p[i-1]*10, i++);
	for(scanf("%d", &ts), t=1; t<=ts; printf("Case #%d: %d\n", t, r), t++)
	{
		for(scanf("%d%d", &a, &b), l=1; a>=p[l]; l++);
		for(r=0, i=a; i<=b; i++)
		{
			for(j=1; j<l; m[j-1]=i%p[j]*p[l-j]+i/p[j], j++);
			sort(m, m+l-1);
			for(j=0; j<l-1; r+=m[j]>i && m[j]<=b && (!j || m[j]!=m[j-1]), j++);
		}
	}
	return 0;
}