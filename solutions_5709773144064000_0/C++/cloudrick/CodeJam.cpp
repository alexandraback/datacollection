// CodeJam.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<set>
#include<iomanip>
#include<cstdio>

using namespace std;

void A();
void B();

int main()
{
	//A();
	B();
	return 0;
}
void B()
{
	int cases = 0;

	cin >> cases;
	for(int n = 1 ; n<=cases ; ++n)
	{
		double c = 0.0L;
		double f = 0.0L;
		double x = 0.0L;
		double sec = 0.0L;
		double out = 2.0;

		cin >> c >> f >> x;
		while( (c/out+x/(out+f)) < x/out )
		{
			sec += c/out;
			out += f;          
		}
		sec += x/out;

		printf("Case #%d: %.7lf\n", n, sec);
		//cout << "Case #" << n << ": " << setprecision(7) << sec << endl;
	}
}
