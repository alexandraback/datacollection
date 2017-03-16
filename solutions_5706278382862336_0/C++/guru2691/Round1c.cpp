#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

long long int B[50];

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
	
	int T,P,Q,i,j,k;
	scanf("%d",&T);
	gen();
	char c;
	for(k=1;k<=T;k++)
	{
		scanf("%d %c %d",&P,&c,&Q);
		if(binary_search(B,B+41,Q))
		{
			j = 1;
			bool o = true;
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
			printf("Case #%d : Impossible\n",k);
		}
		else
		{
			printf("Case #%d: Impossible\n",k);
		}
		
	}
}
