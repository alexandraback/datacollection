#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int T;
	freopen("a.in", "r", stdin);
	ofstream fout("a.out");
	
	scanf("%d\n", &T);
	for (int t = 1; t <= T; ++t) {
		long long p = 0, q = 0;
		scanf("%lld/%lld", &p, &q);
		cout << p << " " << q << endl;
		fout << "Case #" << t << ": ";
		long long tmp = gcd(p, q);
		p /= tmp; q /= tmp;
		
		int count = 0;
		for (long long bit = 1; bit <= q; bit <<= 1) {
			if (q & bit) ++ count;
		}
		
		if (count > 1) fout << "impossible" << endl;
		else {
			cout << p << " " << q << endl;
			long long a = 0, b = 1, c = 1, d = 1;
			int tt = 0;
			while (tt <= 40) {
				++tt;
				tmp = gcd(b, d);
				long long mp = d / tmp * a + b / tmp * c, mq = b / tmp * d * 2;
				tmp = gcd(mp, mq);
				mp /= tmp; mq /= tmp;
				if (mp * q > p * mq) {
					c = mp; d = mq;
				} else break;
				cout << a << " " << b << " " << c << " " << d << endl;
			}
			if (tt <= 40) fout << tt << endl;
			else fout << "impossible" << endl;
		}
	}
	return 0;
}
