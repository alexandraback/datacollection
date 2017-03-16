/**
Coded by:-   Rogue
**/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

bool palin(long long int i)
{
	long long j=0, tmpi=i;
	long long mul=10;
	while(i)
	{
		j=(j*mul)+(i%10);
		i/=10;
	}
	if(tmpi==j)
		return true;
	return false;
}

int main()
{
	long long i,a,b,t,cases,cnt;
	cin>>cases;
	for(t=0; t<cases; t++)
	{
		cin>>a>>b;
		cnt=0;
		i=sqrt(a);
		for(; i*i<=b; i++)
		{
			if(palin(i) && palin(i*i) && i*i>=a)
				cnt++;
		}
		cout<<"Case #"<<t+1<<": "<<cnt<<endl;
	}
	return 0;
}

