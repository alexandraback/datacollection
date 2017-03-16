#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int s[1000];
	double need[1000];
	bool assi[1000];
	int t;
	int n;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		memset(assi,0,sizeof(assi));
		int sum=0;
		for (int j=0;j<n;j++)
		{
			cin>>s[j];
			sum+=s[j];
		}

		double avr = sum * 2.0/n;
		int cnt=n;
		int newsum= 2.0* sum;
		bool flag=true;
		while(flag)
		{
			flag=false;
			for (int j=0;j<n;j++)
			{
				if (assi[j]==false && s[j]>=avr)
				{
					need[j]=0;
					assi[j]=true;
					cnt--;
					newsum-=s[j];
				}
			}
			avr = newsum * 1.0/cnt;
		}

		for (int j=0;j<n;j++)
		{
			if (assi[j]==false)
			{
				need[j]=avr-s[j];
				assi[j]=true;
			}
		}
		printf("Case #%d:",i);
		for (int j=0;j<n;j++)
		{
			printf(" %.6f",need[j] * 100.0/sum);
		}
		printf("\n");
		//cout<<"Case #"<<i<<": "<<mini<<endl;
	}
	return 0;
}