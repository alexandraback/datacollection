#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXD = 521196;

char str[MAXD + 10][11];
int len[MAXD + 10];
char s[20000];
int n;
int dp[20000][6];

int aabs(int x)
{
	if (x < 0)
		return -x;
	return x;
}

int dis(char a, char b)
{
	int x = aabs(a - b);
	return x;
}

int mis[20], top; 

int main()
{
	freopen("dic.txt", "r", stdin);
	for(int i = 1; i <= MAXD; i++)
		gets(str[i] + 1), len[i] = strlen(str[i] + 1);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d\n", &T);
	for(int t = 1; t <= T; t++) {
		gets(s + 1);
		n = strlen(s + 1);
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= 4; j++)
				dp[i][j] = 10000000;
		dp[0][4] = 0;
		for(int i = 0; i < n; i++)
				for(int k = 1; k <= MAXD; k++)
				if (i + len[k] <= n)
					for(int j = 0; j <= 4; j++)
					{
						if (k == 122758)
							k = 122758;
						int flag = 1, cnt = 0;
						for(int l = 1; l <= len[k]; l++)
							if (str[k][l] != s[i + l])
								mis[++cnt] = l;
						for(int l = 2; l <= cnt; l++)
							if (mis[l] - mis[l - 1] < 5)
								flag = 0;
						if (cnt && mis[1] + j < 5)
							flag = 0;
						if (!flag)
							continue;
						int tmp;
						if (cnt)
							tmp = min(4, len[k] - mis[cnt]);
						else
						if (len[k] >= 5)
							tmp = 4;
						else
							tmp = min(4, len[k] + j);
						dp[i + len[k]][tmp] = min(dp[i + len[k]][tmp], dp[i][j] + cnt);
					}
		//for(int i = 1; i <= n; i++)
		//	printf("%d ", dp[i]);
		//printf("\n");
		int ans = 100000000;
		for(int i = 0; i <= 4; i++)
			ans = min(ans, dp[n][i]);
		printf("Case #%d: %d\n", t, ans);
	}
}
