#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


int cnt[1<<15] = {0};
char s[105][105];
int m[105];
int l[105];
int a[1<<15][30][2] = {0};
int mod = 1000000007;


int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	for(int i = 0; i < (1<<15); i++)
	{
		for(int j = 0; j < 15; j++)
			cnt[i] += (i & (1<<j)) != 0;
	}

	int TT;
	scanf("%d", &TT);
	for(int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		int n;
		memset(a, 0, sizeof(a));
		memset(m, 0, sizeof(m));
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%s", s[i]);
			l[i] = strlen(s[i]);
		}
		bool f = 1;
		for(int i = 0; i < n && f; i++)
		{
			m[i] = 0;
			for(int j = 0; s[i][j]; j++)
			{
				if((m[i] & (1<<(s[i][j] - 'a'))) && s[i][j] != s[i][j-1])
				{
					f = 0;
					break;
				}
				m[i] |= (1<<(s[i][j] - 'a'));
			}
			a[1<<i][s[i][l[i]-1] - 'a'][0] = 1;
			a[1<<i][s[i][l[i]-1] - 'a'][1] = m[i];
		}
		if(!f)
		{
			printf("0\n");
			continue;
		}

		for(int i = 1; i < (1<<n); i++)
		{
			for(int j = 0; j < 26; j++)
			{
				if(a[i][j][0] > 0)
				{
					for(int k = 0; k < n; k++)
					{
						if(i & (1<<k))
							continue;
						int m1 = a[i][j][1], m2 = m[k];
						int mm = m1 & m2;
						if (cnt[mm & ((1<<15)-1)] + cnt[mm>>15] == 1 && j == s[k][0] - 'a' ||
							cnt[mm & ((1<<15)-1)] + cnt[mm>>15] == 0)
						{
							a[i | (1<<k)][s[k][l[k]-1] - 'a'][0] += a[i][j][0];
							if(a[i | (1<<k)][s[k][l[k]-1] - 'a'][0] >= mod)
								a[i | (1<<k)][s[k][l[k]-1] - 'a'][0] -= mod;
							a[i | (1<<k)][s[k][l[k]-1] - 'a'][1] = m1 | m2;
						}
					}
				}
			}
		}

		int res = 0;
		for(int i = 0; i < 26; i++)
		{
			res += a[(1<<n)-1][i][0];
			if(res >= mod)
				res -= mod;
		}
		printf("%d\n", res);
	}

	return 0;
}