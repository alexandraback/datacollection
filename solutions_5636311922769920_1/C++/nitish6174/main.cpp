#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	int t,k,c,s;
	long long int segment,p,max;
	int itr,i;

	cin>>t;
	for(itr=1;itr<=t;itr++)
	{
		cin>>k>>c>>s;
		printf("Case #%d: ",itr);
		if(c==1)
		{
			if(s<k)
				cout<<"IMPOSSIBLE";
			else
			{
				for(i=1;i<=s;i++)
					cout<<i<<" ";
			}
		}
		else
		{
			if(s<(k+1)/2)
				cout<<"IMPOSSIBLE";
			else
			{
				segment = (long long int)pow(k,c-1);
				max = (long long int)segment*k;
				for(i=0;i<s;i+=2)
				{
					p = (long long int)i*segment+i+2;
					if(p>max)
						p=(long long int)max;
					cout<<p<<" ";
				}
			}
		}
		cout<<'\n';
	}

	return 0;
}