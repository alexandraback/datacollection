#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<math.h>
using namespace std;

#define N 105
int t,n,s,p,score[N];
int min(int a,int b)
{
	return (a<b)?a:b;
}

int main()
{
	//freopen("B-large.in","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d",&t);
	int i,j;
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&n,&s,&p);
		for(j=0;j<n;j++)
			scanf("%d",&score[j]);

		int needs=0,ok=0;
		for(j=0;j<n;j++)
		{
			if(score[j]>=3*p-2)ok++;
			else if(score[j]<3*p-4);
			else if(score[j]>=2)needs++;
		}
		printf("Case #%d: %d\n",i+1,ok+min(s,needs));
	}

	return 0;
}