#include <set>
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

typedef long long ll;
const ll MAXV=1000000000000;

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		ll n;
		scanf("%lld",&n);
		int used[10]={};
		char buf[30];
		int i;
		for(i=1;n!=0;i++)
		{
			assert(i*n<MAXV);
			sprintf(buf,"%lld",i*n);
			for(int j=0;buf[j];j++)
				used[buf[j]-'0']=true;
			if(*min_element(used,used+10)==1)
				break;
		}
		if(n==0)
			printf("Case #%d: INSOMNIA\n",test);
		else
			printf("Case #%d: %lld\n",test, i*n);
	}
	return 0;
}
