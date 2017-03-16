#include "bits/stdc++.h"
using namespace std;

int main()
{
	int t;
	int J,P,S,K;
	cin>>t;
	int sum = 0;
	for (int i = 1; i <=t; ++i)
	{
		cin>>J;
		cin>>P;
		cin>>S;
		cin>>K;
		int days = 0;
		if(S == 1)
		{
			days = 1;
			cout<<"Case #"<<i<<": "<<days<<endl;
			cout<<1<<" "<<1<<" "<<1<<endl;
		}
		else if(S==2 || S == 3)
		{
			days = J * K * P;
			int s = 1;	
			cout<<"Case #"<<i<<": "<<days<<endl;
			for(int j=1; j<=J; j++)
			{
				for(int p=1; p<=P; p++)
				{
					for (int k=1; k<=K; ++k)
					{
						cout<<j<<" "<<p<<" "<<s<<endl;
						s++;
						if( s > S)
							s = 1;
					}
				}
			}
		}
	}
}