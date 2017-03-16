#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPower(long x) {
	if (x == 1)
		return true;
	else if (x%2 == 1)
		return false;
	else 
		return isPower(x/2);
}

long parent(long a, long b) {
	if (a*2 >= b) {
		return 1;
	} else {
		return 1 + parent(a*2, b);
	}
}

long gcd(long a, long b) {
	long tmp;
	while(b != 0) {
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

void divide(long &a, long &b) {
	long t = gcd(a, b);
	a = a/t;
	b = b/t;
}

int main() {
	int T;
	long P, Q;
	char c;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> P >> c >> Q;
		cout << "Case #" << i+1 << ": ";
		divide(P, Q);
		if (!isPower(Q)) {
			cout << "impossible" << endl;
		} else {
			cout << parent(P, Q) << endl;
		}
	}
	return 0;
}