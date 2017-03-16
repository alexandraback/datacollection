#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
int t,M;
cin>>t;
M = t;
while( t-- )
{
	int n,a,b;
	cin>>a>>b;
	vector <double> prob(a);
	for( int i = 0; i < a; i++ )
	{
		double temp;
		scanf("%lf",&temp);
		prob[i] = double (temp); 
	}

	double tot, nos, frac;
	int count = 0;
	nos = (float) b-a+1+2*a + b+1;
	frac = (float) b+1;

	double gmin = nos-frac;

	while( count < a )
	{
		nos -= 2.0 ;
		frac *= prob[count];

		gmin = min( gmin, nos - frac );
		count++;
//		cout << " count:"<< count << "nos:" << nos <<" frac:"<<frac<<endl;
	}

	gmin = min( gmin, (double) b+2 );
	cout<<"Case #"<<M-t<<": ";
	printf("%0.10lf\n",gmin);
	 
	
}
	

	return 0;
}
		 
