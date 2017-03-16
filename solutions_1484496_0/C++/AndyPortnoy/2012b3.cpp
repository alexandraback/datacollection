#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

using namespace std;

const int maxn = 500;
int numbers[maxn];
int set1[maxn], set2[maxn];
int n, total;
string line;
int count1, count2;


void count()
{

}

void read() {
	scanf("%d",&n);
	unsigned long int i;
	for (i=0;i<n;i++)
	{
		scanf("%d", &numbers[i]);	
//printf("i:%d numbers[i]:%d\n",i,numbers[i]);
		set1[i]=0;
		set2[i]=0;
	}
	int temp,cur,k,j;
	for(i=0;i<4000000000;i++)
	{
		temp=i;
		for(k=0;k<n;k++)
		{
			cur = temp%3;
			//printf("%d",cur);
			if(cur==0)
			{
				set1[k]=0;
				set2[k]=0;
			}
			if(cur==1)
			{
				set1[k]=1;
				set2[k]=0;
			}
			if(cur==2)
			{
				set1[k]=0;
				set2[k]=1;
			}
			temp = temp/3;
		}
		//count();

		count1=0;
		count2=0;
		for(j=0;j<n;j++)
		{
			if(set1[j]>0)
				count1=count1+numbers[j];	

			if(set2[j]>0)
				count2=count2+numbers[j];
		}
		//printf("count1 %d, count2 %d, i %d\n", count1, count2, i);
		if(count1==count2 && count1>0)
			break;
	}
	if(count1==count2 && count1>0)
	{
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(set1[i])
			printf("%d ",numbers[i]);

	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(set2[i])
			printf("%d ",numbers[i]);

	}
	printf("\n");
	}
	else
		printf("Impossible\n");


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
