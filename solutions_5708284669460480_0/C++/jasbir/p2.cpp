#include<cstdio>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int lps[105];
void compute(string p, int len)
{
	int i = 1, j = 0;
	lps[0] = 0;
	while(i < len)
	{
		if(p[i] == p[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if(j != 0)
				j = lps[j - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
double dp[105][105];
int cnt_dp[105][105];
int n, m, s;
string str1, str2;
double fun(int pos, int pre)
{
	if(dp[pos][pre] != -1.0)
		return dp[pos][pre];
	if(pos == s)
		return 0.0;
	double res = 0.0;
	int i;
	for(i=0;i< n;i++)
	{
		double val = 0.0;
		int tmp = pre;
		while((str2[tmp] != str1[i]) && tmp > 0)
			tmp = lps[tmp - 1];
		if(tmp == 0 && str2[0] != str1[i])
			tmp = 0;
		else
			tmp++;
		if(tmp == m)
		{
			val = 1.0;
			tmp = lps[tmp - 1];
		}
		res = res + (1.0 / n) * (val + fun(pos + 1, tmp));
	}
	return dp[pos][pre] = res;
}
int f1(int pos, int pre)
{
	if(cnt_dp[pos][pre] != -1)
		return cnt_dp[pos][pre];
	if(pos == s)
		return 0;
	int res = 0;
	int i;
	for(int i=0;i<n;i++)
	{
		int val = 0;
		int ttt = pre;
		while((str2[ttt] != str1[i]) && ttt > 0)
			ttt = lps[ttt - 1];
		if(ttt == 0 && str2[0] != str1[i])
			ttt = 0;
		else
			ttt++;
		if(ttt == m)
		{
			val = 1;
			ttt = lps[ttt - 1];
		}
		res = max(res, val + f1(pos + 1, ttt));
	}
	return cnt_dp[pos][pre] = res;
}
int main()
{
	int t, tcase,ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int i, j, k;
		scanf("%d %d %d",&n,&m,&s);
		cin>>str1>>str2;
		//scanf("%s",&str1); scanf("%s",&str2);
		for(int i=0;i<105;i++)
		{
		for(int i=0;i<105;i++)
			for(int j=0;j<105;j++)
			{
				dp[i][j] = -1.0;
				cnt_dp[i][j] = -1;
			}
		}
		compute(str2, str2.length());
		
		double res1 = fun(0, 0);
		
		int res2 = f1(0, 0);
		
		double final_res = fabs(res2 * 1.0 - res1);
		printf("%.6lf\n", final_res);
	}
	return 0;
}
