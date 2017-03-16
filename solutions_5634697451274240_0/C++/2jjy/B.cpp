#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);++i)
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
char ind[103];
void task()
{
	int n;
	scanf("%s",ind+1);
	n=strlen(ind+1);
	ind[n+1]='+';
	int tct=0;
	rep(i,n)
	{
		if(ind[i]!=ind[i+1])
		{
			++tct;
		}
	}
	/*for(int i=n;i;--i)
	{
		if(ind[i]=='-')
		{
			if(ind[1]=='+')
			{
				++tct;
				ind[1]='-';
			}
			++tct;
			rep(j,i/2)
			{
				swap(ind[j],ind[i-j+1]);
			}
			rep(j,i)
			{
				ind[j]=ind[j]=='+'?'-':'+';
			}
		}
	}*/
	printf("%d\n",tct);
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int nt;scanf("%d",&nt);
	rep(i,nt)
	{
		printf("Case #%d: ",i);
		task();
	}
}
