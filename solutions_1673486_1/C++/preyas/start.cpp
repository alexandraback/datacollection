#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int casenum = 1; casenum <= t; casenum++)
	{
		int a,b;
		cin>>a>>b;
		long double p[a];
		for(int i = 0; i<a; i++)
			cin>>p[i];

		long double ans = (long double)(b+2);

		long double curp = 1.0;
		for(int i = 0; i<=a; i++)
		{
			long double numkeys = a - i;
			numkeys = curp*(numkeys + b - i + 1) + (1- curp)*(numkeys + b - i + 1 + b + 1);
			ans = min(ans, numkeys);
			curp *= p[i];
		}
		cout << fixed;
		cout<<"Case #"<<casenum<<": "<<setprecision (6)<<ans<<endl;
	}
	return 0;
}
