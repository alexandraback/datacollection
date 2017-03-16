#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	int tttt;
	cin>>tttt;
	for(int ttt=1;ttt<=tttt;ttt++)
	{
		int n;
		cin>>n;
		double a[n+1],sum=0,x=0;
		int flag[n];
		int left=0;
			for(int i=0;i<n;i++)
			{
				cin>>a[i]; 
				x+=a[i];
				flag[i]=0;
			}
		while(true)
		{
			sum=0;
			for(int i=0;i<n;i++)
			{
				if(flag[i]==0)
					sum+=a[i];
			}
			sum=(sum+x)/(1.0*(n-left));
			
			//cout<<sum<<endl<<x<<endl;
			int bit=0;
			for(int i=0;i<n;i++)
			{
				if(sum-a[i] < 0 && flag[i]==0)
				{
					flag[i]=1; bit=1;
					left++;	
				} 
			}
			if(bit==0)break;
		}

		cout<<"Case #"<<ttt<<": ";


		for(int i=0;i<n;i++)
{		
if(flag[i]==0)
	printf("%.7lf ",((sum-a[i])/(1.0*x)*100));
else
printf("0.00000000 ");
}	
	cout<<endl;

	}

}
