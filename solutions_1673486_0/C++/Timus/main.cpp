#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int d[100][5];
double ps[100];

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int testnum = 1; testnum <= tests; ++testnum) {
		int A, B;
		cin >> A >> B;
//		cerr << "__________________________" << endl;
		double a[3];
		for (int i = 0; i < A; ++i) {
			cin >> a[i];
			a[i] = 1 - a[i];
		}
		
		memset(d, 0, sizeof(d));
		memset(ps, 0, sizeof(ps));

//		for (int i = 0; i < A; ++i)
//			cerr << a[i] << " ";
//		cerr << endl;

		for (int mask = 0; mask < (1<<A); ++mask) {
			double p = 1;
			for (int i = 0; i < A; ++i)
				if ((1<<i)&mask)
					p *= a[i];
				else p *= (1 - a[i]);
			ps[mask] = p;
//			cerr << "@" << p << endl;
			d[mask][0] = mask == 0 ? B - A + 1 : B - A + 1 + B + 1;
			d[mask][1] = 1 + B + 1;
			for (int i = 0; i < A; ++i) {
				bool h = false;
				for (int j = A - i - 2; j >= 0; --j)
					if ((1<<j)&mask)
						h = true;
//				cerr << i << " " << h << endl;
				d[mask][2 + i] = h ? i + 1 + (B - (A - i - 1)) + 1 + B + 1 : i + 1 + (B - (A - i - 1)) + 1;
			}
		}
/*		for (int j = 0; j < (1<<A); ++j)
			cerr << ps[j] << "     ";
		cerr << endl;
		for (int j = 0; j < (1<<A); ++j) {
			for (int i = 0; i <= 1 + A; ++i)
				cerr << d[j][i] << "    ";
			cerr << endl;
		}*/
		double best = 1e9;
		for (int i = 0; i <= 1 + A; ++i) {
			double tek = 0;
			for (int j = 0; j < (1<<A); ++j)
				tek += ps[j] * d[j][i];
//			cerr << i << " " << tek << endl;
			best = min(tek, best);
		}
		printf("Case #%d: %.7f\n", testnum, best);
	}
	return 0;
}
