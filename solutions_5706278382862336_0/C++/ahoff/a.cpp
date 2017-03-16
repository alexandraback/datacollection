#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

long long gcd(long long a, long long b) {
	while(b != 0) {
		long long t = b;
		b = a % b;
		a = t;
	} return a;
}

bool power(long long x) {
	while(x > 1) {
		if(x & 1) return false;
		x /= 2;
	} return true;
}

int main() {
	int T;
	cin >> T;
	for(int count = 1; count <= T; count++) {
		string s;
		cin >> s;
		long long p,q;
		p = atoi(s.substr(0, s.find('/')).c_str());
		q = atoi(s.substr(s.find('/')+1).c_str());
		/*long long g = gcd(p, q);
		p /= g;
		q /= g;*/
		cout << "Case #" << count << ": ";
		if(!power(q)) {
			cout << "impossible" << endl;
			continue;
		}
		long long depth = 0;
		while(p/q < 1) {
			depth++;
			q /= 2;
		}
		cout << depth << endl;
	}
	return 0;
}
