#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int dp[4096][8];
char ss[3844500];
int len[521196+4];
int loc[521196+4];
int sl;

void init()
{
	freopen("garbled_email_dictionary.txt", "r", stdin);
	char s[1024];
	int i;
	loc[0] = 0;
	for(i = 0; i < 521196; i ++)
	{
		scanf("%s", s);
		len[i] = strlen(s);
		loc[i+1] = loc[i]+len[i];
		strcpy(ss+loc[i], s);
	}
}

char s[4096];

int Check(int k, int j, int &st, int &ed)
{
	int i;
	int ans = 0;
	int pre = -5;
	st = len[j]+1;
	ed = -1;
	for(i = 0; i < len[j]; i ++)
	{
		if(ss[loc[j]+i] != s[k+i])
		{
			if(i - pre <= 4)
			{
				return -1;
			}
			else 
			{
				pre = i;
				ans ++;
			}
			if(i < st)st = i;
			if(i > ed)ed = i;
		}
	}
	return ans;
}

void show(int j)
{
	int i;
	for(i = 0; i < len[j]; i ++)
	{
		//printf("%d\n", len[j]);
		putchar(ss[i+loc[j]]);
	}
	putchar('\n');
}

int main()
{
	init();
	//printf("Input File Name ?");
	char FileName[128];
	//scanf("%s", FileName);
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		int a, n;
		scanf("%s", s);
		int i, j, k, kk;
		sl = strlen(s);
		memset(dp, -1, sizeof(dp));
		for(i = 0; i < 8; i ++)dp[0][i] = 0;
		for(i = 0; i < sl; i ++)
		{
			for(j = 0; j < sl; j ++)
			{
			//	printf("%d ", dp[j][0]);
			}
			//putchar('\n');
			for(j = 0; j < 521196; j ++)
			if(len[j]+i <= sl)
			{
				int s, e, num;
				num = Check(i, j, s, e);
				if(num == -1)continue;
				if(num == 0)
				{
					for(k = 7; k >= 0; k --)
					if(dp[i][k] != -1)
					{
						for(kk = 7; kk >= 0; kk --)
						{
							int ll = k + len[j];
							if(ll >= kk)
							{
								if(dp[i+len[j]][kk] == -1 || dp[i+len[j]][kk] > dp[i][k])
								{
									dp[i+len[j]][kk] = dp[i][k];
									//printf("%d %d %d %d %d %d\n", i, k, ll, i+len[j], kk);
								}
							}
						}
						
						
					}
					//show(j);
					//printf("%d %d\n", i, dp[i][0]);
				}
				if(num > 0)
				{
					for(k = 7; k >= 0; k --)
					if(dp[i][k] != -1)
					{
						for(kk = 7; kk >= 0; kk --)
						{
							int ll = k + s;
							int lll = len[j]-e;
							if(ll >= 5 && lll >= kk)
							{
								if(dp[i+len[j]][kk] == -1 || dp[i+len[j]][kk] > dp[i][k]+num)
								{
									dp[i+len[j]][kk] = dp[i][k]+num;
								}
							}
						}
					}
				}
			}
		}
		
		int ans = 2000000000;
		for(i = 0; i < 7; i ++)
		{
			if(dp[sl][i] < ans && dp[sl][i] != -1)ans = dp[sl][i];
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	
	return 0;
}
