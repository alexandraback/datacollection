#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <set>
using namespace std;

struct Str {
	char buffer[10001];
	int64_t L;
	int64_t X;
	char operator[](size_t idx) const { return buffer[idx % L]; }
	int64_t length() { return L * X; }
} S;

struct Num {
	char c;
	int sign;

	Num() : c('1'), sign(1)
	{
	}

	Num(char obj) : c(obj), sign(1)
	{
	}

	Num& operator*=(const Num& obj)
	{
		switch (c) {
		case '1': 
			switch (obj.c) {
			case '1': c = '1'; sign *=  obj.sign; break;
			case 'i': c = 'i'; sign *=  obj.sign; break;
			case 'j': c = 'j'; sign *=  obj.sign; break;
			case 'k': c = 'k'; sign *=  obj.sign; break;
			}
			break;
		case 'i':
			switch (obj.c) {
			case '1': c = 'i'; sign *=  obj.sign; break;
			case 'i': c = '1'; sign *= -obj.sign; break;
			case 'j': c = 'k'; sign *=  obj.sign; break;
			case 'k': c = 'j'; sign *= -obj.sign; break;
			}
			break;
		case 'j':
			switch (obj.c) {
			case '1': c = 'j'; sign *=  obj.sign; break;
			case 'i': c = 'k'; sign *= -obj.sign; break;
			case 'j': c = '1'; sign *= -obj.sign; break;
			case 'k': c = 'i'; sign *=  obj.sign; break;
			}
			break;
		case 'k':
			switch (obj.c) {
			case '1': c = 'k'; sign *=  obj.sign; break;
			case 'i': c = 'j'; sign *=  obj.sign; break;
			case 'j': c = 'i'; sign *= -obj.sign; break;
			case 'k': c = '1'; sign *= -obj.sign; break;
			}
			break;
		}
		return *this;
	}

	Num operator*(const Num& obj)
	{
		return Num(*this) *= obj;
	}

	bool operator==(char x) const
	{
		return (sign == 1 && c == x);
	}
	bool operator!=(char x) const
	{
		return !(*this == x);
	}
} Ni, Nj, Nk;

bool solve()
{
	const int64_t length = S.length();

	Ni = Num();
	int64_t i = 0;
	while (Ni != 'i') {
		Ni *= S[i];
		if (i++ == length) return false;
	}
	for (;;) {
		Ni *= S[i];
		if (Ni != 'i') break;
		if (i++ == length) return false;
	}

	Nk = Num();
	int64_t k = length - 1;
	while (Nk != 'k') {
		Nk = Num(S[k]) * Nk;
		if (k-- == i) return false;
	}
	for (;;) {
		Nk *= S[k];
		if (Nk != 'k') break;
		if (k-- == i) return false;
	}

	Nj = Num();
	for (int64_t j = i; j <= k; j++) {
		Nj *= S[j];
	}

	return Nj == 'j';
}

int main(int argc, char* argv[])
{
#ifdef _MSC_VER
	if (argc > 1) {
		FILE* fp;
		freopen_s(&fp, argv[1], "r", stdin);
	}
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> S.L >> S.X;
		cin >> S.buffer;
		cout << "Case #" << t << ": " << (solve() ? "YES" : "NO") << endl;
	}

	return 0;
}
