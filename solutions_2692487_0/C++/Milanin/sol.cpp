#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 110
int a[N];
int main()
{
	int r, n, i, k, ts, t, b, m, s;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		printf("Case #%d: ", t);
		for(scanf("%d%d", &b, &n), i=0; i<n; scanf("%d", &a[i]), i++);
		sort(a, a+n);
		if(b==1) r=n;
		else
			for(r=n, m=0; m<(1<<n); m++)
			{
				for(s=b, k=0, i=0; i<n; i++)
					if((m>>i)&1)
					{
						for(; s<=a[i]; k++, s=s*2-1);
						s+=a[i];
					}
					else k++;
				if(k<r) r=k;
			}
		printf("%d\n", r);
	}
	return 0;
}
