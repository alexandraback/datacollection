#include <fstream>
#include <iostream>
using namespace std;

ifstream ifs("1.in");
ofstream ofs("1.out");

int res;
int ores;
#define INT64 long long

INT64 GCD(INT64 u, INT64 v) {
    while ( v != 0) {
        INT64 r = u % v;
        u = v;
        v = r;
    }
    return u;
}

void process() {
	INT64 p, q;
	char c;
	ifs >> p >> c >> q;
	INT64 gcd = GCD(p, q);
	cout << p << "," << q << "," << gcd << endl;
	p /= gcd;
	q /= gcd;

	res = 0;
	ores = -1;
	
	// make p = 1 first
	while (p > 1) {
		if (q % 2 != 0) {
			ores = -1;
			return;
		}

		if (p > q/2) {
			p -= q/2;
			res ++;
			if (ores < 0) ores = res;
			//return;		// first elf
		}
		q /= 2;
		res ++;
	}

	while (q > 1) {
		if (q % 2 == 0) {
			q /= 2;
			res ++;
		} else {
			ores = -1;
			return;
		}
	}
	if (ores < 0) ores = res;
}

int main() {
	int cnt;
	ifs >> cnt;

	for (int i=0; i<cnt; i++) {
		process();
		if (ores > 0) {
			ofs << "Case #" << (i+1) << ": " << ores << endl;
		} else {
			ofs << "Case #" << (i+1) << ": impossible" << endl;
		}
	}

	ofs.close();
	ifs.close();

	return 0;
}
