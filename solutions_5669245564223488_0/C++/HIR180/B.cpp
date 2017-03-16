#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
typedef long long ll;

int t;
int dp[1025][27];

int main()
{
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		printf("Case #%d: ",test);
		int n;
		string str[15];
		int maskv[15]={};
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin >> str[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<str[i].size();j++)
			{
				maskv[i] |= (1<<(str[i][j]-'a'));
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][26] = 1;
		for(int mask = 0; mask < (1<<n) ; mask++)
		{
			for(int jj=0;jj<=26;jj++)
			{
				if(!dp[mask][jj]) continue;
				
				int cur = 0;
				for(int a=0;a<n;a++)
				{
					if(((mask >> a)&1))
					{
						cur |= maskv[a];
					}
				}
				int gen = cur;
				for(int a=0;a<n;a++)
				{
					if(!((mask >> a)&1))
					{
						cur = gen;
						char last = jj<26?jj+'a':' ';
						for(int j=0;j<str[a].size();j++)
						{
							if(last != ' ' && last != str[a][j] && ((cur >>(str[a][j]-'a'))&1))
							{
								goto fail;
							}
							last = str[a][j]; cur |= (1<<(last-'a'));
						}
						dp[mask | (1<<a)][last-'a'] = (dp[mask | (1<<a)][last-'a']+dp[mask][jj])%mod;
						fail:;
					}
				}
			}
		}
		ll res = 0;
		for(int i=0;i<26;i++) res = (res+dp[(1<<n)-1][i])%mod;
		cout << res << endl;
	}
}