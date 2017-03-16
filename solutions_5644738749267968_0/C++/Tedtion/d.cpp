#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
#define NN 1008

int main()
{
	int T, n;
	double a[NN],b[NN];
	int i,j;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("d.out", "w", stdout);
	scanf("%d",&T);
	for (int cas=1; cas<=T; cas++)
	{
		scanf("%d",&n);
		for (i=0; i<n; i++) scanf("%lf", a+i);
		for (i=0; i<n; i++) scanf("%lf", b+i);
		sort(a,a+n);
		sort(b,b+n);
		int p=0;
		j=n-1;
		for (i=n-1; i>=0; i--)
		{
			while (j>=0 && b[j]>a[i]) j--;
			if (j>=0) p++,j--;
		}
		int p2=n;
		j=0;
		for (i=0; i<n; i++)
		{
			while (j<n && b[j]<a[i]) j++;
			if (j<n) p2--, j++;
		}
		printf("Case #%d: %d %d\n", cas, p, p2);
	}
	return 0;
}

