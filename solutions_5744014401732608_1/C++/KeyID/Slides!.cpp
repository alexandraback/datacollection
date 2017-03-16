#include <bits/stdc++.h>
using namespace std;

const int MAXN=55;

typedef long long LL;

LL d[MAXN];
char s[MAXN][MAXN];

inline void preprocess()
{
	d[1]=1;
	for (int i=2;i<=50;i++)
		for (int j=1;j<i;j++)
			d[i]+=d[j];
}

inline void solve()
{
	int n;
	LL m;
	scanf("%d%lld",&n,&m);
	if (m>d[n])
	{
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	if (m==d[n])
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=i;j++) putchar('0');
			for (int j=i+1;j<=n;j++) putchar('1');
			puts("");
		}
		return;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			s[i][j]='0';
	for (int i=1;i<n;i++)
		for (int j=i+1;j<n;j++)
			s[i][j]='1';
	for (int i=n-1;i>=2;i--)
		if (m&d[i])
			s[i][n]='1';
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) putchar(s[i][j]);
		puts("");
	}
}

int main()
{
	freopen("read.txt","r",stdin);
	freopen("write.txt","w",stdout);
	preprocess();
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
