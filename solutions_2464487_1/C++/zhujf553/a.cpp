#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#define sqr(x) ((x)*(x))

using namespace std;

typedef unsigned long long ull;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, tt;
	ull r, t, s;
	cin >> T;
	for(tt = 1  ; tt <= T ; tt++)
	{
		cin >> r >> t;
		/*s = t;
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
		*/
		r--;
		
		double ll, rr, mid;
		ll = 1, rr = sqrt(t);
		
		while(rr - ll > 1e9)
		{
			mid = (ll + rr) /2;
			if(2*mid*mid + (2*r+1)*mid < t) ll = mid;
			else rr = mid;
		}
		
		ull l1 = ll, r1 = rr, m1;
		//cout << l1 << ' ' << r1 << endl;
		while(l1 + 1 < r1)
		{
			m1 = (r1 + l1) / 2;
			if(2*m1*m1 + (2*r+1)*m1 <= t) l1 = m1;
			else r1 = m1;
		}
		m1 = l1 + 1;
		if(2*m1*m1 + (2*r+1)*m1 <= t) l1 = m1;
		cout << "Case #" << tt << ": " << l1 << endl;
	}
	return 0;
}
