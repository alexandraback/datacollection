#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
#include<utility>
#include<algorithm>
#define LL long long int
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define F(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int dp[60][60],st[60][60],x,n;
void dfs(int y)
{
	int i;
	F(i,1,n)
	{
		if (st[y][i]==1)
		{
			dp[x][i]++;
			dfs(i);
		}
	}
	return;
}
int main()
{
	int t,i,j,v,ca=0,k,fl;
	s(t);
	while(t--)
	{
		ca++;
		s(n);
		F(i,1,n)	
			F(j,1,n)
			{
				dp[i][j] = 0;
				st[i][j] = 0;
			}
		F(i,1,n)
			dp[i][i] = 0;
		F(i,1,n)
		{
			s(j);
			F(k,1,j)
			{
				s(v);
				st[i][v] = 1;
			}
		}
		fl = 0;
		F(i,1,n)
		{
			F(j,1,n)
				F(k,1,n)
					dp[j][k] = 0;
			x = i;
			dfs(x);
			F(j,1,n)
				if (dp[i][j] >= 2)
				{
					fl = 1;
					break;
				}
		}
		if (fl==1)
			printf("Case #%d: Yes\n",ca);
		else
			printf("Case #%d: No\n",ca);
	}
	return 0;
}
