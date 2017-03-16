#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll calc(ll a,ll rad)
{
	return rad*a*2+(2*a-1)*a;
}
int main()
{
	FILE *fr=fopen("a-small-attempt0.in","r");
	FILE *fw=fopen("out0.txt","w");
	int test;
	fscanf(fr,"%d",&test);
	for(int p=0;p<test;p++)
	{
		ll rad,gen;
		fscanf(fr,"%lld%lld",&rad,&gen);
		ll beg=0,end=min(1000000000LL,2100000000000000000LL/(rad*2));
		for(;;)
		{
			ll med=(beg+end)/2+1;
			if(calc(med,rad)>gen)
			{
				end=med-1;
			}
			else
			{
				beg=med;
			}
			if(beg==end)
			{
				fprintf(fw,"Case #%d: %lld\n",p+1,beg);
				break;
			}
		}
	}
}