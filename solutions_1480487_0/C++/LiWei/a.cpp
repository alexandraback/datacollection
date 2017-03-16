#include <iostream>
#include <stdio.h>
#define MAX(a,b) (a)>(b)?(a):(b)
using namespace std;
int main()
{
	int c,t,n,i,j,sum,sum2,n2;
	double a,a2;
	cin>>t;
	int s[202];
	for(c=0;c<t;c++)
	{
		cin>>n;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>s[i];
			sum+=s[i];
		}
		a = sum*2.0f/n;
		sum2=sum;n2=n;
		for(i=0;i<n;i++)
		{
			if(s[i]>a)
			{
				sum2-=s[i];
				n2--;
			}
		}
		a2=((double)sum+sum2)/n2;
		cout<<"Case #"<<c+1<<": ";
		if(s[0]>a)
		{
			cout<<"0.000000";
		}else
		{
			printf("%6lf",(a2-s[0])/sum*100);
		}
		for(i=1;i<n;i++)
		{
			if(s[i]>a)
			{
				cout<<" 0.000000";
			}else
			{
				printf(" %6lf",(a2-s[i])/sum*100);
			}
		}
		cout<<endl;
	}
}
