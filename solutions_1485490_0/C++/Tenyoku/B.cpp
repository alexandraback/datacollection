#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
unsigned long long int nc[3];
int nt[3];
unsigned long long int mc[120];
int mt[120];

int main()
{
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("out.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cnt=1; cnt<=T; ++cnt)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) scanf("%I64d %d", &nc[i], &nt[i]);
		for(int i=0; i<m; ++i) scanf("%I64d %d", &mc[i], &mt[i]);
		unsigned long long int sa=0, sb, sc ,ans = 0;
		for(int i=0; i<m; ++i)
		{
			unsigned long long int back = mc[i];
			if(mt[i]==nt[0])
			{
				if(sa+mc[i] > nc[0])
				{
					mc[i] -= nc[0] - sa;
					sa = nc[0];
				}
				else
				{
					sa += mc[i];
					mc[i] = 0;
				}
			}
			sb = 0;
			for(int j=i; j<m; ++j)
			{
				long long int back = mc[j];
				if(mt[j]==nt[1])
				{
					if(sb+mc[j]>nc[1])
					{
						mc[j] -= nc[1]-sb;
						sb = nc[1];
					}
					else
					{
						sb += mc[j];
						mc[j] = 0;
					}
				}
				sc = 0;
				for(int l=j; l<m; ++l) if(mt[l]==nt[2]) sc+=mc[l];
				sc = min(sc, nc[2]);
				if(sa+sb+sc > ans) ans = sa+sb+sc;
				mc[j] = back;
			}
			mc[i] = back;
		}
		printf("Case #%d: %I64d\n", cnt, ans);
	}
}
