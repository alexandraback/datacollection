#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> all;

long long rev(long long a) {
	long long r = 0;
	while (a > 0) {
		long long u = a % 10;
		r = r * 10 + u;
		a = a / 10;
	}
	return r;
}

void f(long long A, long long B) {
	for (long long i = ceil(sqrt(A)); i * i <= B; i++) {
		if (rev(i) == i && rev(i * i) == i * i) all.push_back(i * i);
	}
}

int main() {
	ifstream in("C-large-1.in");
	ofstream out("C-large-1.out");

	int T; in >> T;

	f(1, 100000000000005LL);
	cout << all.size() << endl;
	for (int x = 1; x <= T; x++) {
		long long A, B; in >> A >> B;
		long long c = 0;
		for (int i = 0; i < all.size(); i++) if (all[i] >= A && all[i] <= B) c++;
		out << "Case #" << x << ": " << c << endl;
	}

	return 0;
}
