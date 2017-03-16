#include <stdio.h>
#include <string.h>
#include <algorithm>

int n, size, ans1, ans2;
char ar[30], br[30];

long long a(int ind)
{
	long long cn =0, c= 1;
	for(int i=ind;i>=1;i--)
	{
		cn+=c*(ar[i]-'0');
		c*=10;
	}
	return cn;
}
long long b(int ind)
{
	long long cnb =0, c= 1;
	for(int i=ind;i>=1;i--)
	{
		cnb+=c*(br[i]-'0');
		c*=10;
	}
	return cnb;
}

void dfs(int k)
{
	//printf("pass %d\n", k);
	if(k==size+1)
	{
		long long g = 0, h = 0, c = 1;
		for(int i=size;i>=1;i--)
		{
			g+=c*(ar[i]-'0');
			h+=c*(br[i]-'0');
			c*=10;
		}
		if(ans1==-1)
		{
			ans1 = g;
			ans2 = h;
		}
		else
		{
			if(abs(ans1-ans2)==abs(g-h))
			{
				if(ans1==g)
				{
					if(ans2>h)ans2=h;
				}
				else if(ans1>g)
				{
					ans1=g;
					ans2=h;
				}
			}
			
			else if(abs(ans1-ans2)>abs(g-h))
			{
				ans1=g;
				ans2=h;
			}
		}
		return;
	}
	
	if(ar[k]=='?'&&br[k]=='?')
	{
		if(a(k-1)==0&&b(k-1)==0)
		{
			ar[k]='0', br[k]='0';
			dfs(k+1);
			ar[k]='?', br[k]='?';
			ar[k]='1', br[k]='0';
			dfs(k+1);
			ar[k]='?', br[k]='?';
			ar[k]='0', br[k]='1';
			dfs(k+1);
			ar[k]='?', br[k]='?';
		}
		else{
			
				ar[k]='9', br[k]='0';
				dfs(k+1);
				ar[k]='?', br[k]='?';
			
				ar[k]='0', br[k]='0';
				dfs(k+1);
				ar[k]='?', br[k]='?';
			
				ar[k]='0', br[k]='9';
				dfs(k+1);
				ar[k]='?', br[k]='?';
			
		}
	}
	else if(ar[k]=='?')
	{
		if(b(k-1)<a(k-1))
		{
			ar[k]='0';
			dfs(k+1);
			ar[k]='?';
		}
		else if(b(k-1)>a(k-1))
		{
			ar[k]='9';
			dfs(k+1);
			ar[k]='?';
		}
		else
		{
			if(br[k]<'9')
			{
				ar[k]=br[k]+1;
				dfs(k+1);
				ar[k]='?';
			}
			if(br[k]>'0')
			{
				ar[k]=br[k]-1;
				dfs(k+1);
				ar[k]='?';
			}
			ar[k]=br[k];
			dfs(k+1);
			ar[k]='?';
		}
	}
	
	else if(br[k]=='?')
	{
		if(b(k-1)<a(k-1))
		{
			br[k]='9';
			dfs(k+1);
			br[k]='?';
		}
		else if(b(k-1)>a(k-1))
		{
			br[k]='0';
			dfs(k+1);
			br[k]='?';
		}
		else
		{
			if(ar[k]<'9')
			{
				br[k]=ar[k]+1;
				dfs(k+1);
				br[k]='?';
			}
			if(ar[k]>'0')
			{
				br[k]=ar[k]-1;
				dfs(k+1);
				br[k]='?';
			}
			br[k]=ar[k];
			dfs(k+1);
			br[k]='?';
		}
	}
	
	else dfs(k+1);
	return;
}

void solve()
{
	ans1 = -1;
	ans2 = -1;
	size = strlen(ar+1);
	//printf("size %d\n", size);
	dfs(1);
	int i = size;
	int A1[30]={}, A2[30]={};
	//printf("ans1 : %d ans2 : %d\n", ans1, ans2);
	while(ans1>0)
	{
		A1[i--]=ans1%10;
		ans1/=10;
	}
	i=size;
	while(ans2>0)
	{
		A2[i--]=ans2%10;
		ans2/=10;
	}
	for(int j=1;j<=size;j++)
	{
		printf("%d", A1[j]);
		A1[j]=0;
	}
	printf(" ");
	for(int j=1;j<=size;j++)
	{
		printf("%d", A2[j]);
		A2[j]=0;
	}
}

int main()
{
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("B_result.txt", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("\n%s %s", ar+1, br+1);
		printf("Case #%d: ", i);
		solve();
		puts("");
	}
	return 0;
}
