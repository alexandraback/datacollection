#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>
#include <cmath>

using namespace std;

ifstream fin ("a.in");
ofstream fout ("a.out");

long long T, P, Q;
char s;

long long gcd (long long a, long long b) {
	//cerr << "gcd(" << a << ", " << b << ")\n";
	if (a > b)
		return gcd(b,a);
	if (a == 0)
		return b;
	return gcd(b - (b/a)*a, a);

}

int main () {
	fin >> T;
	for (long long i =  1; i <= T; i++) {
		fout << "Case #" << i << ": ";
		fin >> P >> s >> Q;
		long long g = gcd(P,Q);
		P /= g;
		Q /= g;
		long long A = 0;
		long long B = 0;
		while ((Q % 2) == 0) {
			Q /= 2;
			A++;
			if (P > 1) {
				P /= 2;
				B++;
			}
		}
		if ((Q > 1) or (A > 40)) {
			fout << "impossible\n";
			continue;
		}
		cerr << "A = " << A << " & B = " << B << '\n';
		fout << A - B << '\n';
	}	
	return 0;
}
