#include <fstream>

using namespace std;

int main() {
	ifstream fin("a.in");
	ofstream fout("a.out");
	bool pd;
	char c;
	int t, x, y, i, j, k;
	long long p, q, a, b, r;
	fin >> t;
	for(x = 1; x <= t; x++) {
		fin >> p >> c >> q;
		a = p;
		b = q;
		while(b > 0) {
			r = a % b;
			a = b;
			b = r;
		}
		p /= a;
		q /= a;
		pd = true;
		a = q;
		while(a > 1) {
			if(a & 1) {
				pd = false;
				break;
			} 
			a = a >> 1;
		}
		if(pd) {
			y = 0;
			while(p < q) {
				y++;
				if(q & 1) p = p << 1;
				else q = q >> 1;
			}
			fout << "Case #" << x << ": " << y << "\n";
		}
		else fout << "Case #" << x << ": impossible\n";
	}
	return 0;
} 
