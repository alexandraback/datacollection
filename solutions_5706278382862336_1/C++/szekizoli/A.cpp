#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	for (;;)
	{
		if (a == 0) return b;
		b %= a;
		if (b == 0) return a;
		a %= b;
	}
}

bool checkIfTwo(unsigned long long i) {
	int count = 0;;
	while (i > 0) {
		if (i & 1 == 1) {
			++count;
		}

		i = i / 2;
	}

	return count == 1;
}

void solveCase() {
	unsigned long long P, Q;
	scanf_s("%llu/%llu", &P, &Q);

	unsigned long long g = gcd(P, Q);
	P /= g;
	Q /= g;
	bool ok = checkIfTwo(Q);
	if (!ok) {
		cout << "impossible";
		return;
	}

	unsigned long long i = Q / P;
	if (Q > P * i) {
		++i;
	}
	unsigned long long m = 2;
	unsigned long long c = 1;
	while (i > m) {
		m = m * 2;
		++c;
	}

	cout << c;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	std::cin >> T;
	for (int i = 1; i < T + 1; ++i)
	{
		std::cout << "Case #" << i << ": ";
		solveCase();
		if (i < T)
			std::cout << std::endl;
	}
	return 0;
}