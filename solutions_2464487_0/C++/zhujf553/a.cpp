#include <iostream>
#include <stdio.h>
#include <string.h>
#define sqr(x) ((x)*(x))

using namespace std;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, tt, r, t, s;
	cin >> T;
	for(tt = 1  ; tt <= T ; tt++)
	{
		cin >> r >> t;
		s = t;
		r--;
		int i = 1;
		while(s >= 0)
		{
			s -= sqr(i * 2 + r) - sqr(i * 2 + r - 1); 
			//cout << s << endl;
			i++;
		};
		i--;
		i--;
		cout << "Case #" << tt << ": " << i << endl;
	}
	return 0;
}
