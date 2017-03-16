#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b) {
	ull c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

ull solve(ull P, ull Q, int n) {
	ull Paux = P, Qaux = Q;
	if (n > 40)
		return 0;
	ull gcdPQ = gcd(P, Q);
	P /= gcdPQ;
	Q /= gcdPQ;
	ull aux = 1ull << n;
	gcdPQ = gcd(aux, Q);
	Q /= gcdPQ;
	aux /= gcdPQ;
	P *= aux;
	if (P < Q)
		return solve(Paux, Qaux, n + 1);
	P -= Q;
	if ((Q & (Q-1)) == 0)
		return n;
	return solve(Paux, Qaux, n + 1);
}

int numCase = 0;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	ull P, Q;
	char c;
	cin >> T;
	while (T--) {
		cin >> P >> c >> Q;
		cout << "Case #" << ++numCase << ": ";
		ull x = solve(P, Q, 1);
		if (x == 0)
			cout << "impossible\n";
		else
			cout << x << "\n";
	}
	return 0;
}