#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		long long a, b;
		cin >> a;
		char ch;
		cin >> ch;
		cin >> b;
		long long g = __gcd(a, b);
		a /= g, b /= g;
		int pw = 0;
		while ((1LL << pw) < b)
			++pw;
		if ((1LL << pw) != b) {
			puts("impossible");
			continue;
		}
		int gen = 0;
		while (a < b)
			b /= 2, ++gen;
		if (gen > 40)
			puts("impossible");
		else
			printf("%d\n", gen);
	}
}
