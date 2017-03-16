#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

double store[100002] ; 

int main()
{
	int t ;
	int a , b ;
	int left ; 
	double prob ; 
	double ans ; 
	double val ;
	int total = 1 ;
	int i ; 
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d",&a,&b);
		left = b - a ; 
		for(i = 0 ; i < a  ; i++)
		{
			scanf("%lf",&prob);
			if(i == 0)
				store[i] = prob ; 
			else
				store[i] = store[i-1] * prob ; 
		}
		ans = store[a-1]*(left + 1) + (1 - store[a-1])*(left + b + 2);

		for(i = 1 ; i <=a ; i++)
		{
			val = store[a -i -1]*(i + left + i + 1) + (1 - store[a-i-1])*(i + left + i + 1 + b + 1);

			ans = min(ans , val);
		}

		ans = min(ans , (double)(b + 2));


		printf("Case #%d: %lf\n",total++,ans);
	}
	return 0;
}
