#include <cstdio>
#include <cstring>

int dp[10000001];

bool isPal(long long tar)
{
	char temp[20];
	sprintf(temp, "%lld", tar);
	int len = strlen(temp);
	for(int i=0;i<len;i++)
	{
		int opp = len - i - 1;
		if(opp <= i) break;
		if(temp[i] != temp[opp]) return false;
	}

	return true;
}

int calc(long long lim)
{
	if(lim <= 0) return 0;
	long long s = 1, e = 10000001, mid, ind;
	while(s < e)
	{
		mid = (s + e) / 2;
		if(mid * mid <= lim) { ind = mid; s = mid + 1; }
		else e = mid;
	}

	if(dp[ind] != -1) return dp[ind];

	int &ret = dp[ind];
	ret = 0;
	for(long long i=1;i<=ind;i++) if(isPal(i) && isPal(i*i)) ret++;
	return ret;
}

int main(void)
{
	memset(dp, -1, sizeof(dp));
	int T;
	scanf("%d", &T);
	for(int caseN=1;caseN<=T;caseN++)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("Case #%d: %d\n", caseN, calc(b) - calc(a - 1));
	}

	return 0;
}
