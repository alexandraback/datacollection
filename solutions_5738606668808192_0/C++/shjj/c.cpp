//shjj-c

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m,A[30],g[60],ls;
long long now;

const int pri[5]={2,3,5,7,11};

int check(int Jc)
{
	for (int i=0;i<5;i++)
	{
		int last=0;
		for (int j=ls;j;j--)
			(((last*=Jc)+=g[j])%=pri[i]);
		if (!last) return pri[i];
	}
	return 0;
}

int main()
{
	freopen("C0.in","r",stdin);
	freopen("C0.out","w",stdout);
	int T;scanf("%d",&T);
	scanf("%d%d",&n,&m);
	puts("Case #1:");
	now=1<<(n-1);
	now++;
	long long Up=1<<n;
	for (;now<Up;now+=2)
	{
		ls=0;
		for (long long y=now;y;y>>=1) g[++ls]=y&1;
		int x=check(2);
		if (!x) continue;
		bool p=1;
		A[2]=x;
		for (int i=3;i<=10;i++)
		{
			x=check(i);
			if (!x) p=0;
			if (!p) break;
			A[i]=x;
		}
		if (!p) continue;
		for (int i=ls;i;i--) printf("%d",g[i]);
		for (int i=2;i<=10;i++) printf(" %d",A[i]);
		puts("");
		m--;
		if (!m) break;
		
	}
}