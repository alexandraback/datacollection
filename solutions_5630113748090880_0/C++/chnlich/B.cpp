#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
int T,n;
int A[2510],x;

int main()
{
	freopen("B.in","r",stdin);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d:", tt);
		scanf("%d",&n);
		memset(A,0,sizeof A);
		for(int i=1;i<=2*n-1;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&x);
				A[x]++;
			}
		for(int i=1;i<=2500;i++) if (A[i]%2==1) printf(" %d", i);
		printf("\n");
	}
	return 0;
}