#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

typedef long long LL;

typedef pair<int, char> Q;

char* mult_table[4] = { "1ijk", "i1kj", "jk1i", "kji1" };

int sign_table[4][4] = { { 1, 1, 1, 1 }, { 1, -1, 1, -1 }, { 1, -1, -1, 1 }, {
		1, 1, -1, -1 } };

int ind(char x) {
	switch (x) {
	case '1':
		return 0;
	case 'i':
		return 1;
	case 'j':
		return 2;
	case 'k':
		return 3;
	}
	assert(0);
	return -1;
}

Q operator*(const Q& a, const Q& b) {
	Q x; // = a*b
	x.first = a.first * b.first * sign_table[ind(a.second)][ind(b.second)];
	x.second = mult_table[ind(a.second)][ind(b.second)];
	return x;
}

Q inv(const Q& a) {
	if (a.second == '1')
		return a;
	return Q(-a.first, a.second);
}

Q from[10005];
Q inv_from[10005];

Q interval(int a, int b) {
	assert(a <= b);

	return from[a] * inv_from[b + 1];
}

bool possible(const string& s) {
	int n = s.size();

	from[n] = Q(1, '1');
	for (int i = n - 1; i >= 0; --i) {
		from[i] = Q(1, s[i]) * from[i + 1];
	}
	inv_from[n] = Q(1, '1');
	for (int i = n - 1; i >= 0; --i) {
		inv_from[i] = inv_from[i + 1] * inv(Q(1, s[i]));
	}

	for (int i = 0; i < n - 2; ++i) {
		Q left = interval(0, i);
		if (left.first == 1 && left.second == 'i') {
			for (int j = i + 1; j < n - 1; ++j) {
				Q mid = interval(i + 1, j);
				if (mid.first == 1 && mid.second == 'j') {
					Q right = interval(j + 1, n - 1);
					if (right.first == 1 && right.second == 'k') {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
	int cases;

	cin >> cases;

	for (int caseid = 1; caseid <= cases; ++caseid) {
		cout << "Case #" << caseid << ": ";
		int L, X;
		cin >> L >> X;
		string s_tmp;
		cin >> s_tmp;
		string s;
		for (int i = 0; i < X; ++i)
			s += s_tmp;
		if (possible(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

