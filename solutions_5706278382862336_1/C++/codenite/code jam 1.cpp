#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long int S[50];

long long int gcd(long long int d,long long int c)
{
	if(c==0)
	return d;
	else return gcd(c,d%c);
}

void intial()
{
	long long  i = 1,j;
	S[0] = i;
	for(j=1;j<=44;j++)
	{
		i *= 2;
		S[j] = i;
	}
}
int main()
{
	int test,i,j,cs;
	long long  P,Q,w;
	freopen("inAL.in","r",stdin);
	freopen("output.txt", "w", stdout);
    scanf("%d",&test);
	intial();
	for(cs=1;cs<=test;cs++)
	{
		scanf("%lld/%lld",&P,&Q);
		w = gcd(Q,P);
		P = P/w;
		Q = Q/w;

		if(binary_search(S,S+41,Q))
		{
			j = 1;
			bool answ = true;
			if(P>Q)
			{
				printf("Case #%d: impossible\n",cs);
				answ = false;
			}
			while(j<=40 && answ)
			{
				if(P>=Q/2)
				{
					printf("Case #%d: %d\n",cs,j);
					answ = false;
				}
				Q = Q/2;
				j++;
			}
			if(answ)
			printf("Case #%d : impossible\n",cs);
		}
		else
		{
			printf("Case #%d: impossible\n",cs);
		}
	}
	return 0;
}
