#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define P 1000000007
using namespace std;

struct st
{
	int l,r;
} a[256];
int N,c[256],d[256],e[256],p[105],f[256],g[256];
bool b[256];

void doit()
{
	scanf("%d",&N);
	char s[105];
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int i=1,l; i<=N; i++)
	{
		scanf("%s",s+1),l=strlen(s+1);
		for (int j=1,k; j<=l; j=k)
		{
			for (k=j; k<=l&&s[k]==s[j]; k++);
			if (j>1&&k<=l) if (b[s[j]]||s[1]==s[l]&&s[j]!=s[1]) {puts("0"); return;}
			b[s[j]]=1;
		}
		a[i].l=s[1],a[i].r=s[l];
		if (a[i].l!=a[i].r)
		{
			if (c[a[i].l]||d[a[i].r]) {puts("0"); return;}
			c[a[i].l]=d[a[i].r]=g[a[i].r]=i;
		}
		else e[a[i].l]++,f[a[i].l]=i;
	//	cout<<i<<' '<<a[i].l<<' '<<a[i].r<<endl;
	}
	int ans=1,t=0;
	for (int i='a'; i<='z'; i++) if (e[i])
	{
		ans=1ll*ans*p[e[i]]%P;
		if (!d[i]) d[i]=f[i];
		if (!c[i]) c[i]=f[i];
	}
	for (int i='a',j; i<='z'; i++) if (!g[i]&&c[i])
	{
	//	cout<<i<<' '<<c[i]<<' '<<d[i]<<endl;
		bool bg=0;
		for (j=c[i]; d[a[j].r]; j=d[a[j].r]) if (a[j].r!=i) bg=1;
		if (a[j].r!=i||bg) t++; else {puts("0"); return;}
	}
	ans=1ll*ans*p[t]%P;
	cout<<ans<<endl;
}

void work()
{
	p[0]=1;
	for (int i=1; i<=100; i++) p[i]=1ll*p[i-1]*i%P;
}

int main()
{
	int T;
	//freopen("bb.in","r",stdin);
	//freopen("bbb.out","w",stdout);
	work();
	scanf("%d",&T);
	for (int i=1; i<=T; i++) printf("Case #%d: ",i),doit();
	return 0;
}
/*
1
4
a abc a ca
*/

