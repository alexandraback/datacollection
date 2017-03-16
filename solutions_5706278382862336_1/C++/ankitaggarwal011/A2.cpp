#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

long long int checker[50];

void check()
{
	long  long int k = 1,s;
	checker[0] = k; 
	for(s=1;s<=44;s++)
	{
		k *= 2;
		checker[s] = k;
	}
	
}


int main()
{
	freopen("A-large.in", "r", stdin);
    freopen("output_A_large.txt", "w", stdout);
	long long int Test,A,B;
	long long int i,j,t;
	scanf("%lld",&Test);
	char c;
	check();
	
	for(t=1;t<=Test;t++)
	{
		scanf("%lld %c %lld",&A,&c,&B);
		if(binary_search(checker,checker+41,B))
		{
			j = 1;
			bool output = true;
			while(j<=40 && output)
			{
				if(A>=B/2)
				{
					printf("Case #%lld: %lld\n",t,j);
					output = false;
				}
				B /= 2;
				j++;
			}
			if(output==true)
			printf("Case #%lld : impossible\n",t);
		}
		else
		{
			printf("Case #%lld: impossible\n",t);
		}
		
	}
}
