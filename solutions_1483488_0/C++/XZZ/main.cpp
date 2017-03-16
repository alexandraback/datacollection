#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int pows[] = {10, 100, 1000, 10000, 100000, 1000000, 1000000};
short mark[2000005];
vector<int> v;

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, a, b;
	int i, j;
	int Case = 1;
	int res, now, aa, bb, newnow, newpow;
	memset(mark, 0, sizeof(mark));
	scanf("%d", &T);
	while(T--) 
	{
		scanf("%d%d", &a, &b);
		if(b<10) 
		{
			printf("Case #%d: %d\n", Case++, 0);
			continue;
		}
		res = 0;
		for (i = b; i >= a; --i)
		{
			now = i;
			v.clear();
			for (j = 6; j >= 0; --j)
			{
				if(now < pows[j]) continue;
				aa = now / pows[j];
				bb = now % pows[j];
				newpow = (int)log10(aa*1.0);
				newnow = bb * (int)pow(10.0, newpow + 1.0) + aa;
				if(newnow >= a && newnow <=b && newnow < now) 
				{ 
					if(mark[newnow]==0)
					{
						res++; 
						mark[newnow]=1;
						v.push_back(newnow);
					}
				}
			}
			for(j=0; j<v.size(); j++)
			{
				mark[v[j]]=0;
			}
		}
		printf("Case #%d: %d\n", Case++, res);
	}
	return 0;
}