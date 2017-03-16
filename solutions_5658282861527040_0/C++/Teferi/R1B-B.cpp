#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LINT;

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int a,b,k;
		cin>>a>>b>>k;

		int sol=0;

		for(int i=0; i<a; i++)
			for(int j=0; j<b; j++)
			{
				if( (i&j) < k)
					sol++;
			}

		cout<<"Case #"<<ii+1<<": "<<sol<<endl;
	}
}
