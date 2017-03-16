#include <iostream>
using namespace std;
#include<algorithm>
#include<stdio.h>
#include<fstream>
#include<math.h>
using namespace std;
 
int main() {
	int t,M=0,m,max=10000,i,j,n,k;
	cin>>t;
	while(t--)
	{
		M++;
		max=1000000;
		cin>>n>>m>>k;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(2*j+2*i+i*j>=k)
			if(2*(j+i)<max)
			{
				max=2*(j+i);
			}
			if(2*j+2*i+i*j+1>=k)
			if(2*(j+i)+1<max)
			{
				max=2*(j+i)+1;
			}
		}
		if(n==1||m==1)
		{
			if(k<=2)
			printf("Case #%d: %d\n",M,k);
			else
			printf("Case #%d: %d\n",M,(k/3)*2+k%3);
		}
		else if(n==2||m==2)
		{
			if(k<=5)
			printf("Case #%d: %d\n",M,k);
			else
			printf("Case #%d: %d\n",M,(k/6)*5+k%6);
		}
		else
		{
			if(k==4)
			printf("Case #%d: 3\n",M);
			else
			printf("Case #%d: %d\n",M,max);
		}
	}
	return 0;
}
