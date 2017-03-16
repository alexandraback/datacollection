#include <iostream>
#include <fstream>

using namespace std;

long long x[10000];

int main()
{
	int i,j;
	x[0]=1;
	for(i=1;i<=9;i++)
	{
		x[i]=2*x[i-1];
	}
	int T;
	long long P,Q;
	cin >> T;
	int r=0;
	while(T--)
	{
		r++;
		cin >> P >> Q;
		cout << "Case #"<<r<<": " ;
		int found;
		found=0;
		
		for(i=1;i<=9;i++)
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
		for(i=1;i<=9;i++)
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
