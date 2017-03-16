#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{int t;
scanf("%d",&t);
int c=1;
while(t--)
{
	int n;
	scanf("%d",&n);
	double naomi[n],ken[n];
	int i,j;
	for(i=0;i<n;i++)
	scanf("%lf",&naomi[i]);
	for(i=0;i<n;i++)
	scanf("%lf",&ken[i]);
 
	if(n==1)
 
{if(naomi[0]>ken[0])
printf("Case #%d: 1 1\n",c);
else printf("Case #%d: 0 0\n",c);
 
}
else
{int a=0,b,count=0;
	sort(naomi,naomi+n);
	sort(ken,ken+n);
 
 
	int k=0;
	for(i=0;i<n;i++)
{int flag=0;
 
	for(j=k;j<n;j++)
	{
		if(naomi[i]<ken[j])
		{count++;
		flag=1;
 
		k=j+1;}
		if(flag)
		break;}
}
b=n-count;
 
for(i=0,j=0;i<n;i++)
{
	if(naomi[i]>ken[j])
	{
		j++;
		a++;
	}
}
 
printf("Case #%d: %d %d\n",c,a,b);
}
 
c++;}
return 0;}
