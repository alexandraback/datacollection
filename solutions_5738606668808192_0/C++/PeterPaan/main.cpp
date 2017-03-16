#include <iostream>
#include <bitset>
#include <array>

using namespace std;

typedef unsigned long long Int;

constexpr int N = 16;
constexpr int J = 50;
constexpr Int MAX_N = 1 << (N-2);
constexpr Int LEFT_1 = 1 << (N-1);

Int bin_to_base(Int bin, int base) {
	Int acc = 0;
	auto bits = bitset<N>(bin);
	for (int i = bits.size() - 1; i >= 0; --i) {
		acc = acc * base + (bits[i]? 1 : 0);
	}
	return acc;
}

bool find_divisor(Int n, Int & divisor) {
	if (n % 2 == 0) {
		divisor = 2;
		return true;
	} else {
		for (Int i = 3; i*i <= n; i += 2) {
			if (n % i == 0) {
				divisor = i;
				return true;
			}
		}
	}
	return false;
}

int main(int, char **) {
	cout << "Case #1:" << endl;
	int found = 0;
	for (Int n = 0; n < MAX_N && found < J; ++n) {
		Int candidate = LEFT_1 + (n << 1) + 1;
		array<Int, 11> divisors_for_base;
		bool ok = true;
		int base = 2;
		while ( ok && base <= 10) {
			if (! find_divisor(bin_to_base(candidate, base), divisors_for_base[base])) {
				ok = false;
			}
			++base;
		}
		if (ok) {
			cout << bitset<N>(candidate);
			for (auto base = 2; base <= 10; ++base) {
				cout << ' ' << divisors_for_base[base];
			}
			cout << endl;
			found++;
		}
	}
    return 0;
}
