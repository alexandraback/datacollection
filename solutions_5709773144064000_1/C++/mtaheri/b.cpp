#include <stdio.h>
#include <iostream>
using namespace std;

void main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		printf("Case #%d: ",i+1);
		double C,F,X;
		cin>>C>>F>>X;
		double bestt=10e36;
		double acct=0;
		double rate=2.0;
		for(int k=0;;k++)
		{
			double t=acct+X/rate;
			if(t>bestt)
			{
				printf("%.7Lf\n",bestt);
				break;
			}
			bestt=t;
			acct+=C/rate;
			rate+=F;
		}
	}
}