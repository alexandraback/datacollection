#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

const int maxn = 100000;
double numbers[maxn];

int n, total;
string line;


void read() {

	scanf("%d",&n);
//printf("n:%d\n",n);
	int onestar[n], twostar[n];
	int i,k;
	for (i=0;i<n;i++)
	{
		scanf("%d", &onestar[i]);
		scanf("%d", &twostar[i]);	
//printf("one:%d two:%d\n",onestar[i],twostar[i]);
	}
	int mystars = 0;
	int myturns = 0;

//sort it
int flag=1, temp;
	for(i=1;(i<=n)&&flag;i++)
	{
		flag=0;
		for(k=0;k<(n-1);k++)
		{
			if(twostar[k+1]>twostar[k])
			{
				temp = twostar[k];
				twostar[k] = twostar[k+1];
				twostar[k+1] = temp;
				temp = onestar[k];
				onestar[k] = onestar[k+1];
				onestar[k+1] = temp;
				flag=1;
			}
		}
	}


	for (i=0;i<n;i++)
	{
//printf("one:%d two:%d\n",onestar[i],twostar[i]);
	}

	int hit;
	for(k=0;k<2*n;k++)
	{
//if i can solve a 2 star, do it
		hit=0;		
		for(i=0;i<n;i++)
		{
						
			if((hit==0)&&(mystars>=twostar[i]))
			{
				
				hit=1;
				myturns++;				
				mystars = mystars+1;
				twostar[i]=1000000;
				if(onestar[i]<1000000)
				{
					mystars = mystars+1;					
					onestar[i]=1000000;
				}
//				printf("[2] myturns:%d mystars:%d i:%d\n",myturns, mystars, i);
//				printf("onestar[i]:%d twostar[i]:%d i:%d\n",onestar[i], twostar[i]);
			}
		}

//if I can't solve any 2 starts, order the 1 stars by lowest 2 star rating, and solve the 1 star		
		if(hit==0){		
		for(i=0;i<n;i++)
		{
			if((hit==0)&&(mystars>=onestar[i]))
			{
				hit=1;
				myturns++;				
				mystars = mystars+1;
				onestar[i] = 1000000;
//				printf("[1] myturns:%d mystars:%d i:%d\n",myturns, mystars, i);
//				printf("onestar[i]:%d twostar[i]:%d i:%d\n",onestar[i], twostar[i]);
			}
		}}
	}
	if(mystars==2*n)
		printf("%d\n",myturns);	
	else
		printf("Too Bad\n");
}

int main()
{
	int i,t;
	int k;
	int outoforder;
	scanf("%d",&t);
	getline(cin,line);
	for(i = 1; i<=t; i++)
	{
		printf("Case #%d: ", i);
		read();

		//cout<<line;

//		printf("\n");
	}
	return 0;
}
