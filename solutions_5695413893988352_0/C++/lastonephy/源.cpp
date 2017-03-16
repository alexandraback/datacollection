#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define INF 1000000000000000000LL
#define LL __int64
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define zero(x) ((x > +eps) - (x < -eps))
#define MAX 2010
using namespace std;

char str1[20], str2[20];

struct NODE
{
	int flag;
	string a, b;
}dp[2][2010];

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%s%s",str1,str2);
		int len = strlen(str1);
		for(int i = 0; i <= 2000; i ++)
		{
			dp[0][i].flag = 0;
			dp[0][i].a = "";
			dp[0][i].b = "";
		}
		int pos = 1000;
		dp[0][1000].flag = 1;
		int pre = 0, now = 1;
		int x = 1;
		for(int i = 1; i < len; i ++)
		{
			x *= 10;
		}
		for(int r = 1; r <= len; r ++)
		{
			for(int j = 0; j <= 2000; j ++)
			{
				dp[now][j].flag = 0;
				dp[now][j].a = "";
				dp[now][j].b = "";
			}
			for(int j = 0; j < 2000; j ++)
			{
				if(!dp[pre][j].flag) continue;
				if(str1[r - 1] == '?')
				{
					if(str2[r - 1] == '?')
					{
						for(int i = 0; i < 10; i ++)
						{
							for(int k = 0; k < 10; k ++)
							{
								int y = j + (i - k) * x;
								if(!dp[now][y].flag)
								{
									dp[now][y].flag = 1;
									dp[now][y].a = dp[pre][j].a + (char)(i + '0');
									dp[now][y].b = dp[pre][j].b + (char)(k + '0');
								}
								else
								{
									if(dp[now][y].a > dp[pre][j].a + (char)(i + '0'))
									{
										dp[now][y].a = dp[pre][j].a + (char)(i + '0');
										dp[now][y].b = dp[pre][j].b + (char)(k + '0');
									}
									else if(dp[now][y].a == dp[pre][j].a + (char)(i + '0'))
									{
										if(dp[now][y].b > dp[pre][j].b + (char)(k + '0'))
										{
											dp[now][y].b = dp[pre][j].b + (char)(k + '0');
										}
									}
								}
							}
						}
					}
					else
					{
						for(int i = 0; i < 10; i ++)
						{
							int y = j + (i - (str2[r - 1] - '0')) * x;
							if(!dp[now][y].flag)
							{
								dp[now][y].flag = 1;
								dp[now][y].a = dp[pre][j].a + (char)(i + '0');
								dp[now][y].b = dp[pre][j].b + str2[r - 1];
							}
							else
							{
								if(dp[now][y].a > dp[pre][j].a + (char)(i + '0'))
								{
									dp[now][y].a = dp[pre][j].a + (char)(i + '0');
									dp[now][y].b = dp[pre][j].b + str2[r - 1];
								}
								else if(dp[now][y].a == dp[pre][j].a + (char)(i + '0'))
								{
									if(dp[now][y].b > dp[pre][j].b + str2[r - 1])
									{
										dp[now][y].b = dp[pre][j].b + str2[r - 1];
									}
								}
							}
						}
					}
				}
				else
				{
					if(str2[r - 1] == '?')
					{
						for(int i = 0; i < 10; i ++)
						{
							int y = j + (str1[r - 1] - '0' - i) * x;
							if(!dp[now][y].flag)
							{
								dp[now][y].flag = 1;
								dp[now][y].a = dp[pre][j].a + str1[r - 1];
								dp[now][y].b = dp[pre][j].b + (char)(i + '0');
							}
							else
							{
								if(dp[now][y].a > dp[pre][j].a + str1[r - 1])
								{
									dp[now][y].a = dp[pre][j].a + str1[r - 1];
									dp[now][y].b = dp[pre][j].b + (char)(i + '0');
								}
								else if(dp[now][y].a == dp[pre][j].a + str1[r - 1])
								{
									if(dp[now][y].b > dp[pre][j].b + (char)(i + '0'))
									{
										dp[now][y].b = dp[pre][j].b + (char)(i + '0');
									}
								}
							}
						}
					}
					else
					{
						int y = j + (str1[r - 1] - str2[r - 1]) * x;
						if(!dp[now][y].flag)
						{
							dp[now][y].flag = 1;
							dp[now][y].a = dp[pre][j].a + str1[r - 1];
							dp[now][y].b = dp[pre][j].b + str2[r - 1];
						}
						else
						{
							if(dp[now][y].a > dp[pre][j].a + str1[r - 1])
							{
								dp[now][y].a = dp[pre][j].a + str1[r - 1];
								dp[now][y].b = dp[pre][j].b + str2[r - 1];
							}
							else if(dp[now][y].a == dp[pre][j].a + str1[r - 1])
							{
								if(dp[now][y].b > dp[pre][j].b + str2[r - 1])
								{
									dp[now][y].b = dp[pre][j].b + str2[r - 1];
								}
							}
						}
					}
				}
			}
			x /= 10;
			swap(pre,now);
		}
		string ansa, ansb;
		ansa = ansb = "";
		int f = 0;
		for(int i = 1000, j = 0; i + j <= 2000;j ++)
		{
			if(dp[pre][i + j].flag)
			{
				ansa = dp[pre][i + j].a;
				ansb = dp[pre][i + j].b;
				f = 1;
			}
			if(dp[pre][i - j].flag)
			{
				f = 1;
				if(ansa == "")
				{
					ansa = dp[pre][i - j].a;
					ansb = dp[pre][i - j].b;
				}
				else
				{
					if(ansa > dp[pre][i - j].a)
					{
						ansa = dp[pre][i - j].a;
						ansb = dp[pre][i - j].b;
					}
					else if(ansa == dp[pre][i - j].a)
					{
						if(ansb > dp[pre][i - j].b)
						{
							ansb = dp[pre][i - j].b;
						}
					}
				}
			}
			if(f)
			{
				break;
			}
		}
		printf("Case #%d: %s %s\n",ii,ansa.c_str(),ansb.c_str());
	}
	return 0;
}
