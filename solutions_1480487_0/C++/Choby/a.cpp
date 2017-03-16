#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	int t;
	int n;
	double nums[n];
	double suma;
	
	
	scanf("%d",&t);
	
	for(int i=1; i<=t; i++)
	{
		scanf("%d",&n);	
		suma=0;
		
		for(int j=0; j< n; j++)
		{
			scanf("%lf",nums+j);
			suma+=nums[j];
		}
		
		double tope=2*suma/n;
		double auxSuma=suma;
		int aux=n;
		
		for(int j=0; j<n; j++)
		{
			if (nums[j]>tope)
			{
				aux--;
				auxSuma-=nums[j];
			}
		}
		
		double aux2=(suma+auxSuma)/aux;
		double resp;
		printf("Case #%d:",i);
		
		for(int j=0; j<n; j++)
		{
			resp=(nums[j]>tope)?(0):((aux2-nums[j])/suma);
			printf(" %.6lf",resp*100 );
		}
		printf("\n");
	
	}
	
	return 0;
}
