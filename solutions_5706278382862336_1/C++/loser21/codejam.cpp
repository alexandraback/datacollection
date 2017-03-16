#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

long long x[10000];

long long euclid(long long a , long long b)
{
	if(b==0)
	return a;
	return euclid(b,a%b);
}

int main()
{
	int i,j;
	x[0]=1;
	for(i=1;i<=39;i++)
	{
		x[i]=2*x[i-1];
	}
	int T;
	long long P,Q,X;
	cin >> T;
	int r=0;
	while(T--)
	{
		r++;
		cin >> P >> Q;
		X=euclid(P,Q);
		P/=X;
		Q/=X;
		cout << "Case #"<<r<<": " ;
		int found;
		found=0;
		
		for(i=1;i<=39;i++)
		{
			if(Q==x[i])
			{
				found=1;
				break;
			}
		}
		if(found==0)
		{
			cout << "impossible" << endl;
			continue;
		}	
		double a;
		a=(double)P/Q;
		for(i=1;i<=39;i++)
		{
			if(a>=(double)1/x[i])
				{
					cout << i << endl;
					break;
				}
		}	
	}
	
	return 0;
}
