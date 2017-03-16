#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

unsigned long long nod(unsigned long long x, unsigned long long y){
    if (y == 0)
    	return x;
    return nod(y, x % y);
}

int count_bits(unsigned long long n) {
	int c;
	for (c = 0; n; c++)
		n &= n - 1;
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";

		string s;
		cin >> s;

		unsigned long long p, q, n, r;
		int i, j;

		p = atoll(s.c_str());
		q = atoll(s.substr(s.find("/")+1).c_str());

		n = nod(p, q);

		p = p/n;
		r = q/n;

		if (count_bits(r) == 1) {
			i = 0;
			while (r>0) {
				r = r>>1;
				i++;
			}
			j = 0;
			while (p>0) {
				p = p>>1;
				j++;
			}
			j = max(0, j-1);
			cout << (i-1) - j << endl;
		}
		else
			cout << "impossible" << endl;
	}

	return 0;
}
