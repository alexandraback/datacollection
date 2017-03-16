#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
int nt;
int a[200];
double b[200];

int main()
{
	scanf("%d", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		printf("Case #%d: ", tt);
		
		scanf("%d", &n);
		
		int sum = 0;
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		for(int i = 0; i < n; i++) b[i] = (double)a[i] / sum;
		
		double M = b[0];
		for(int i = 1; i < n; i++) M = max(M, b[i]);
		
		for(int i = 0; i < n; i++)
		{
			if (i) printf(" ");
			
			double L = 0, R = 1;
			for(int iter = 100; iter--; )
			{
				double p = (L + R) / 2;
				double score = b[i] + p;
				double used = p;
				for(int j = 0; j < n; j++)
					if (j != i)
						if (b[j] < score) used += score - b[j];
				if (used >= 1.0) R = p; else L = p;
			}			
			
			printf("%.10lf", L * 100);
		}
		puts("");
	}
	
	return 0;
}
