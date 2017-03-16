#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long double num;

int main()
{
	int t;
	cin >> t;
	for(int tc=1;tc<=t;++tc)
	{
		cout << "Case #" << tc << ": ";
		num c,f,x;
		cin >> c >> f >> x;
		num bestt=3000000;
		num curt=0,curprod=2;
		while(curt < bestt)
		{
			bestt = min(bestt, curt + (x/curprod));
			curt = curt + (c/curprod);
			curprod = curprod + f;
		}
		printf("%.7Lf\n",bestt);
	}
}
