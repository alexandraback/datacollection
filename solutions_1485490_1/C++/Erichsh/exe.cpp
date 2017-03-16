#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <cstring>
#include <string>
using namespace std;

long long na, nb, a[500], b[500], ta[500], tb[500], dp[500][500];

int main ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long tc;		scanf("%lld", &tc);
	for (long long T = 1; T <= tc; T++)
	{
		printf("Case #%lld: ", T);
		
		scanf("%lld%lld", &na, &nb);
		for (long long i = 1; i <= na; i++)
		{
			scanf("%lld%lld", &a[i], &ta[i]);
		}
		for (long long i = 1; i <= nb; i++)
		{
			scanf("%lld%lld", &b[i], &tb[i]);
		}
		memset (dp, 0, sizeof(dp));
		for (long long i = 1; i <= na; i++)
			for (long long j = 1; j <= nb; j++)
			{
				if (ta[i] == tb[j])	
				{
					dp[i][j] = max(dp[i][j], min(a[i], b[j]) + dp[i-1][j-1]);
					long long cur = min(a[i], b[j]), cura = a[i] - cur, curb= b[j] - cur, ti = i, tj = j;
					while(1)
					{
						if (cura == 0 && curb == 0)		break;
						if (cura != 0)
						{
							for ( tj--; tj >= 1; tj--)
								if (tb[tj] == ta[ti])
								{
									long long tem = min(cura, b[tj]);
									cur += tem;		cura -= tem;	curb = b[tj] - tem;	
									break;
								}
							/*if (tj == 0)	dp[i][j] = max(dp[i][j], cur);
							else			dp[i][j] = max(dp[i][j], cur + dp[*/
						}
						else
						{
							for ( ti--; ti >= 1; ti--)
								if (ta[ti] == tb[tj])
								{
									long long tem = min(curb, a[ti]);
									cur += tem;		cura = a[ti] - tem;	curb -= tem;	break;
								}
						}
						if (ti == 0 || tj == 0)		dp[i][j] = max(dp[i][j], cur);
							else dp[i][j] = max(dp[i][j], cur + dp[ti-1][tj-1]);
						if (ti == 0 || tj == 0)	break;
					}
					/*if (ti == 0 || tj == 0)	dp[i][j] = max(dp[i][j], cur);
					else dp[i][j] = max(dp[i][j], cur + dp[--ti][--tj]);*/
				}
				else dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
			}
		printf("%lld\n", dp[na][nb]);
	}
}