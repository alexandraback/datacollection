#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[65],N;
bool b[65][65];
ll M;

void init()
{
	scanf("%d%lld",&N,&M);
}

void doit()
{
	int n=0,p=1;
	memset(b,0,sizeof(b));
	for (ll i=M; i; i/=2) a[++n]=i%2;
	if (N<n+1||(N==n+1&&M!=(1<<n-1))) {puts("IMPOSSIBLE"); return;}
	for (int i=1; i<n+1; i++)
		for (int j=i+1; j<=n+1; j++) b[i][j]=1;
	for (int i=1; i<=n; i++) if (a[i]) b[i+1][N]=1;
	puts("POSSIBLE");
	for (int i=1; i<=N; i++)
	{
		for (int j=1; j<=N; j++) printf("%d",b[i][j]);
		puts("");
	}
}

int main()
{
	freopen("B2.in","r",stdin);
	freopen("B2.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: ",i);
		doit();
	}
	return 0;
}
