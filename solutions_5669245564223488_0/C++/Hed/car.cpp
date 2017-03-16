#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

const int maxn = 105;

int T,N,ans,c[maxn],last[26];
char s[maxn][maxn];
bool bz[maxn];

void dfs(int x)
{
	if (x > N)
	{
		memset(last,0,sizeof last);
		bool ok = 1;
		int sumlen = 0;
		fo(i,1,N)
		{
			int len = strlen(s[c[i]]+1);
			fo(j,1,len)
			{
				int z = s[c[i]][j] - 97;
				if (last[z] && last[z] != sumlen+j-1)
				{
					ok = 0;
					break;
				}
				last[z] = sumlen + j;
			}
			if (!ok) break;
			sumlen += len;
		}
		if (ok) ans ++;
		return;
	}
	fo(i,1,N)
		if (!bz[i])
		{
			bz[i] = 1;
			c[x] = i;
			dfs(x+1);
			bz[i] = 0;
		}
}

int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	scanf("%d",&T);
	fo(cs,1,T)
	{
		scanf("%d",&N);
		fo(i,1,N) scanf("%s",s[i]+1);
		ans = 0;
		memset(bz,0,sizeof bz);
		dfs(1);
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}
