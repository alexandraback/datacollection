#include <iostream>
using namespace std;

int T;
double C, F, X, farmcount, Time;

int main()
{
	ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(7);
	
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		cin >> C >> F >> X;
		farmcount = (X*F - C*2.)/(C*F);
		
		Time = 0.;
		double i;
		for (i=1; i<farmcount; i+=1.)
			Time += C/(2.+ (i-1.)*F);
		Time += X/(2. + (i-1.)*F);
		
		cout << "Case #" << t << ": " << Time << endl;
	}
	
	return 0;
}
