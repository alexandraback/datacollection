#include<stdio.h>
#include<algorithm>
#include<iostream>
 
using namespace std;
 
long long int B[50];
 
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
 
void gen()
{
	long  long int i = 1,j;
	B[0] = i; 
	for(j=1;j<=44;j++)
	{
		i *= 2;
		B[j] = i;
	}
 
}
 
 
int main()
{
    freopen("qw.txt","r",stdin);
    freopen("out.txt","w",stdout);
 
	int T,i,j,k;
	long long int P,Q,W;
	scanf("%d",&T);
	gen();
	char c;
	for(k=1;k<=T;k++)
	{
		scanf("%lld %c %lld",&P,&c,&Q);
		W = gcd(Q,P);
		P /= W;
		Q /= W;
 
		if(binary_search(B,B+41,Q))
		{
			j = 1;
			bool o = true;
			if(P>Q)
			{
				printf("Case #%d: impossible\n",k);
				o = false;
			}
			while(j<=40 && o)
			{
				if(P>=Q/2)
				{
					printf("Case #%d: %d\n",k,j);
					o = false;
				}
				Q /= 2;
				j++;
			}
			if(o==true)
			printf("Case #%d : impossible\n",k);
		}
		else
		{
			printf("Case #%d: impossible\n",k);
		}
 
	}
}
