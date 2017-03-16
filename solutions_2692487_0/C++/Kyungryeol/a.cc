#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long int a[128];
long long int b[128][128];

int main()
{
	int tn, ti = 0;
	scanf("%d",&tn);
	while(tn--)
	{
		long long int x;
		int n;
		scanf("%lld %d",&x, &n);
		for(int i = 0; i < n; ++i)
			scanf("%lld",&a[i]);
		sort(a, a+n);
		memset(b, 0, sizeof(b));
		b[0][0] = x;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j <= n; ++j)
			{
				if(b[i][j] == 0) continue;
				if(b[i][j] > a[i]) 
				{
					if(b[i+1][j] < b[i][j] + a[i]) b[i+1][j] = b[i][j] + a[i];
				}
				else 
				{
					long long int t = b[i][j];
					if(t > 1)
					{
						int tt = 0;
						do
						{
							t += t-1;
							++tt;
						} while(t <= a[i]);
						if(b[i+1][j+tt] < t + a[i]) b[i+1][j+tt] = t + a[i];
					}
					if(b[i+1][j+1] < b[i][j]) b[i+1][j+1] = b[i][j];
				}
			}
		int answer;
		for(int i = 0; i <= n; ++i)
			if(b[n][i] != 0) {answer = i; break;}
		printf("Case #%d: %d\n", ++ti, answer);
	}
}
