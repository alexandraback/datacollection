#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int sum,J[210],n,T;
double ans;

bool judge(double Yi,int x)
{
	double no=0;
	for (int i=1;i<=n;i++)
	{
		if (i!=x)
		{
			no+=max(double(J[x]-J[i]+sum*Yi)/sum,double(0));
		}
	}
	return no+Yi>1-1e-10;
}

double work(int x)
{
	double Left=0,Right=1;
	while (Right-Left>1e-9)
	{
		double Mid=(Left+Right)/2;
		if (judge(Mid,x)) Right=Mid;
		else Left=Mid;
	}
	return Left;
}

int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d:",TT);
		sum=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&J[i]),sum+=J[i];
		for (int i=1;i<=n;i++)
		{
		//	ans=work(i);
			printf(" %.6f",work(i)*100);
		}
		printf("\n");
	}
	
	return 0;
}
