#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define INF 1000000.0

int main()
{
	int A, B, T;
	double pc;
	double minExp;
	cin>>T;
	for (int t=1; t<=T; t++)
	{
		cin>>A>>B;
		vector<double> p(A);
		for (int i=0; i<A; i++)
			cin>>p[i];
		pc = 1.0;
		minExp = 1+B+1;
		
		for (int bs=A; bs>=0; bs--)
		{			
			minExp = min( minExp, bs*2+(B-A)+1 + (B+1)*(1-pc) );
			pc *= (p[A-bs]);
			
		}	
		
		
		cout<<"Case #"<<t<<": "<<fixed<<setprecision(7)<<minExp<<endl;
	}
	return 0;
}
