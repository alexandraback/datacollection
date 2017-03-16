#include <stdio.h>
#include <set>
using namespace std;

int main()
{
	int ca,cc;
	int a,b;
	long long i,j,k;

	long long f[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};


	scanf("%d", &ca);
	for(cc=1; cc<=ca; cc++)
	{
		int r=0;
		scanf("%d %d", &a, &b);
		for(i=a; i<=b; i++)
		{
			for(j=0; j<9; j++)
				if (i < f[j])
					break;

			set<long long> s;
			for(k=0; k<j-1; k++)
			{
				long long n = (i%f[k+1])*(f[j-k-1])+i/f[k+1];
				if (n > i && n >= a && n <= b)
				{
					s.insert(n);
				}
			}
			r += s.size();
		}
		printf("Case #%d: %d\n", cc, r);
	}
}
