#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;
int k,l,s;
long long max1;
double sum,num;
char str1[103],str2[103];
void func(int node,char str[])
{
	if(node==s)
	{
		long long count=0;
		double count2=0.0;
		int flag;
		for(int i=0;i<(s-l+1);i++)
		{
			flag=1;
			for(int j=0;j<l;j++)
			{
				if(str[i+j]!=str2[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				count++;
				count2 = count2+1;
			}
		}
		max1 = max(max1,count);
		sum = sum + count2;
		num=num+1;
		return;
	}
	for(int i=0;i<k;i++)
	{
		str[node]=str1[i];
		str[node+1]='\0';
		func(node+1,str);
	}
}
int main()
{
	int t;
	double sum2;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&k);
		scanf("%d",&l);
		scanf("%d",&s);
		scanf("%s",str1);
		scanf("%s",str2);
		char str[103]="";
		max1=0;
		sum=0.0;
		num=0.0;
		func(0,str);
		sum = sum/num;
		sum2 = (double) max1;
		sum2 = sum2 - sum;
		printf("Case #%d: %.7lf\n",i,sum2);
	}
	return 0;
}