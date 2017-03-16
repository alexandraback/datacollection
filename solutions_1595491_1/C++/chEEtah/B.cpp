#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, S, p;
int nt;

int sum[100];


int main()
{
	scanf("%d", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		printf("Case #%d: ", tt);
		
		scanf("%d %d %d", &n, &S, &p);
		for(int i = 0; i < n; i++) scanf("%d", &sum[i]);
		
		sort(sum, sum + n);
		
		int cnt = 0;
		
		for(int i = 0; i < n; i++)
		{
			int a = sum[i] / 3;
			int b = (sum[i] + 1) / 3;
			int c = (sum[i] + 2) / 3;
			
			if (!S)
			{
				if (c >= p) cnt++;
				continue;
			}
			
			if (a == b && a == c && a > 0 && c < 10 && c + 1 >= p)
			{
				a--;
				c++;
				S--;
			}
			else
			{
				if (b == c && c < 10 && b > 0 && c + 1 >= p)
				{
					b--;
					c++;
					S--;
				}
			}
			
			if (c >= p) cnt++;
		}
		
		printf("%d\n", cnt);		
	}
	
	return 0;
}
