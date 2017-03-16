#include<iostream>
#include<stdio.h>
typedef unsigned long long ull;
int main()
{	int t,i;
	ull r,used,cnt,j,x;
	std::cin>>t;
	for(i=1;i<=t;i++)
	{	std::cin>>r>>x;
		for(used=0,cnt=0,j=0;used<=x;used+=((2*r)+(((j+1)*(j+1))-(j*j))),j+=2,cnt++);
		printf("Case #%d: %llu\n",i,cnt-1);
	}
	return 0;
}