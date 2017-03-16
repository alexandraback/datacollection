#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++)
	{
		double C, F, X;
		cin >> C >> F >> X;
		
		double curtime=0, rate=2, best=X/rate;
		while(rate<(X-C)*F/C)
		{
			curtime+=C/rate;
			rate+=F;
			best=min(best, curtime+X/rate);
		}
		
		cout << "Case #" << tc << ": ";
		printf("%.7f",best);
		cout << endl;
	}
}
