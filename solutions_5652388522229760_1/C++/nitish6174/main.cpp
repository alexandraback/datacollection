#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool record(bool seen[],long long int m);

int main()
{
	int t;
	long long int n,m;
	int itr;

	cin>>t;
	for(itr=1;itr<=t;itr++)
	{
		bool seen[10]={0};
		cin>>n;
		if(n==0)
			printf("Case #%d: INSOMNIA\n",itr);
		else
		{
			m = n;
			while(record(seen,m)==0)
			{
				m+=n;
			}
			printf("Case #%d: %lld\n",itr,m);
		}
	}

	return 0;
}

bool record(bool seen[],long long int m)
{
	int i;
	while(m>0)
	{
		seen[m%10]=1;
		m/=10;
	}
	for(i=0;i<10;i++)
	{
		if(seen[i]==0)
			return 0;
	}
	return 1;
}