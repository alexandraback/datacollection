#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;
#define READ(s) freopen(s, "r", stdin)
#define WRITE(s) freopen(s, "w", stdout)

long long int A[50];

long long int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

void fun()
{
	long  long int i = 1,j;
	A[0] = i;
	for(j=1;j<=44;j++)
	{
		i *= 2;
		A[j] = i;
	}

}


int main()
{
   //READ("A-large.in");
    //WRITE("A-large.out");
	int T,i,j,k;
	long long int P,Q,W;
	scanf("%d",&T);
	fun();
	char c;
	for(k=1;k<=T;k++)
	{
		scanf("%lld %c %lld",&P,&c,&Q);
		W = gcd(Q,P);
		P /= W;
		Q /= W;

		if(binary_search(A,A+41,Q))
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
