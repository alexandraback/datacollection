#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int T,L,x;
bool ans;
char ch;
int a[20000];
int r[20000];
const int c[5][5]=
{
	{0,1,2,3,4},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};

int calc(int x,int y)
{
	int z=c[abs(x)][abs(y)];
	if (x<0 || y<0) z=-z;
	return z;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	for (int test=1;test<=T;++test)
	{
		scanf("%d%d",&L,&x);
		scanf("%c",&ch);
		for (int i=1;i<=L;++i)
		{
			scanf("%c",&ch);
			if (ch=='i') a[i]=2;
			if (ch=='j') a[i]=3;
			if (ch=='k') a[i]=4;
		}
		for (int j=1;j<x;++j)
			for (int i=1;i<=L;++i) a[i+j*L]=a[i];
		r[L*x]=a[L*x];
		for (int i=L*x-1;i>0;--i) r[i]=calc(a[i],r[i+1]);
		int s1=a[1],s2;
		ans=0;
		for (int i=1;i<L*x;++i)
		{
			if (ans==1) break;
			if (i>1) s1=calc(s1,a[i]);
			if (s1!=2) continue;
			s2=a[i+1];
			for (int j=i+1;j<L*x;++j)
			{
				if (j>i+1) s2=calc(s2,a[j]);
				if (s2==3 && r[j+1]==4) ans=1; 
			}
		}
		printf("Case #%d: ",test);
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


