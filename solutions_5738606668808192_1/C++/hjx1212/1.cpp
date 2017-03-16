#include<bits/stdc++.h>
using namespace std;

char s[100],s2[100];

inline void pnt(long long x,int i,char *s)
{
	while(i--)
	{
		s[i]=x&1?'1':'0';
		x/=2;
	}
}

int main()
{
//	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);
	puts("Case #1:");
	int n=32,m=500;
	for(int i=1;i<=m;i++)
	{
		long long x=(1ll<<n/2)-i-i+1;
		long long x2=(x<<n/2)+x;
		pnt(x2,n,s2);
		printf("%s",s2);
		for(int k=2;k<=10;k++)
			printf(" %I64d",(long long)powl(k,n/2)+1ll);
		puts("");
	}
	return 0;
}