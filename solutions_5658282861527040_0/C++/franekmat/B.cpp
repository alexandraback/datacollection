#include "cstdio"
long long n,a,b,k,w,q;
int main()
{
	scanf ("%lld", &n);
	for (int i=0; i<n; i++)
	{
		scanf ("%lld%lld%lld", &a, &b, &k);
		w=0;
		for (int x=0; x<a; x++)
		{
			for (int y=0; y<b; y++)
			{
				q=x&y;
				if (q<k) w++;
			}
		}
		printf ("Case #%d: %lld\n", i+1, w);
	}
	
	return 0;
}
