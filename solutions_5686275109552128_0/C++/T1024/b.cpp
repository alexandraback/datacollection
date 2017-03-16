#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int d, t;
	int p[1001];
	
	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		cin >> d;
		for(int i=0; i<d; ++i)
		{
			cin >> p[i];
		}
		
		int res = 9999;
		for(int maxp=1000; 0<maxp; --maxp)
		{
			int spec = 0;
			for(int i=0; i<d; ++i)
			{
				int div = (p[i] + maxp-1) / maxp - 1;
				spec += div;
			}
			int days = maxp + spec;
			res = min(res, days);
		}
		
		cout << "Case #" << tt << ": " << res << "\n";
	}

	return 0;
}
