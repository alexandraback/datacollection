#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n,l,k;
int a[200],b[200];

void rec(int i)
{
	if(k<=0)
		exit(0);
	int j,o;
	for(j=0;j<n;j++)
		printf("%d",b[j]);
	long long x;
	for(j=2;j<=10;j++)
	{
		x=0;
		for(o=0;o<l;o++)
			x=x*j+a[o];
		printf(" %lld",x);
	}
	puts("");
	k--;
	if(k<=0)
		exit(0);
	for(j=i;j<=n-l;j++)
	{
		for(o=0;o<l;o++)
			if(a[o]&&b[j+o])
				break;
		if(o==l)
		{
			for(o=0;o<l;o++)
				b[j+o]+=a[o];
			rec(j+1);
			for(o=0;o<l;o++)
				b[j+o]-=a[o];
		}
	}
}

int main()
{
	freopen("c.out","w",stdout);
	printf("Case #1:\n");
	int i,m;
	scanf("%d%d%d",&m,&n,&k);
	for(l=2;;l++)
		for(m=0;m<1<<l-2;m++)
		{
			a[0]=1;
			for(i=1;i<l-1;i++)
				a[i]=m>>i-1;
			a[l-1]=1;
			for(i=0;i<l;i++)
			{
				b[i]=a[i];
				b[n-l+i]=a[i];
			}
			rec(1);
		}
	return 0;
}