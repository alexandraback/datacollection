#include <fstream>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

typedef vector<int> VI;

int f(const VI& a, int s, int p) {
	int n = a.size();
	int nx = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < 2) {
			nx += (a[i] >= p);
			continue;
		}
		int q = a[i] / 3;
		int r = a[i] % 3;
		switch (r) {
			case 0:
				if (q >= p)
					++nx;
				else if (q + 1 == p && s) {
					++nx;
					--s;
				}
				break;
			case 1:
				nx += (q + 1 >= p);
				break;
			case 2:
				if (q + 1 >= p)
					++nx;
				else if (q + 1 == p - 1 && s) {
					++nx;
					--s;
				}
				break;
		}
	}
	return nx;
}

int main() {
	ifstream in("DancingWithGooglers.in");
	ofstream out("DancingWithGooglers.out");
	int nt;
	in >> nt;
	for (int i = 1; i <= nt; ++i) {
		int n, s, p;
		in >> n >> s >> p;
		VI a(n);
		for (int j = 0; j < n; ++j)
			in >> a[j];
		int nx = f(a, s, p);
		out << "Case #" << i << ": " << nx << endl;
	}
	return 0;
}

