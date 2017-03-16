#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define cin(x) scanf("%d",&x)
using namespace std;
int a[1000005];
int sub(int &A,int x)
{
	int j=0;
	while (A<=x)
	{
		A=A*2-1;
		j++;
	}
	A+=x;
	return j;
}
int main()
{
	int tt,z;
	cin(tt);
	for (z=1;z<=tt;z++)
	{
		int n,A,i,j,k,l,ans;
		cin(A);
		cin(n);
		for (i=1;i<=n;i++)
		{
			cin(a[i]);
		}
		sort(a+1,a+1+n);
		ans=n;
		j=0;
		for (i=1;i<=n;i++)
		{
			if (A==1) {break;}
			j=j+sub(A,a[i]);
			ans=min(j+n-i,ans);
		}
		printf("Case #%d: %d\n",z,ans);
	}
}