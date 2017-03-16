#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main()
{
	int T,ca=0;
	freopen("inb.txt","r",stdin);
	freopen("outb.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof a);
		int n;
		long long m;
		scanf("%d%lld",&n,&m);

		printf("Case #%d: ", ++ca);
		if ((1ll<<((long long)(n-2)))<m) puts("IMPOSSIBLE");
		else {
			puts("POSSIBLE");
			m--;
			for (int i=2;i<=n;i++)
				for (int j=i+1;j<=n;j++)
					a[i][j]=1;
			for (long long i=0;i<n;i++)
				if ((1ll<<i)&m) a[1][n-i-1]=1;
			a[1][n]=1;
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
					printf("%d", a[i][j]);
				puts("");
			}
		}
	}
}