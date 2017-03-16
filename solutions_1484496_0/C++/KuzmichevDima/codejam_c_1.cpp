//#include <stdafx.h>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cassert>

using namespace std;

long a[501];
long list1[501];
long list2[501];
long n;
bool found;

void go(long step,long first,long second,long amount1,long amount2)
{
	if (found) return;
	if (step==n+1)
	{
		if ((first!=second)||(first==0))
			return;
		for (long j=1;j<=amount1;j++)
			printf("%ld ",list1[j]);
		printf("\n");
		for (long j=1;j<=amount2;j++)
			printf("%ld ",list2[j]);
		printf("\n");
		found=true;
		return;
	}
	go(step+1,first,second,amount1,amount2);
	list1[amount1+1]=a[step];
	go(step+1,first+a[step],second,amount1+1,amount2);
	list2[amount2+1]=a[step];
	go(step+1,first,second+a[step],amount1,amount2+1);
	
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	long tests;
	scanf("%ld",&tests);
	for (long test=1;test<=tests;test++)
	{
		scanf("%ld",&n);
		for (long q=1;q<=n;q++)
			scanf("%ld",&a[q]);
		found=false;
		printf("Case #%ld:\n",test);
		go(1,0,0,0,0);
		if (!found)
			printf("Impossible\n");
	}
}