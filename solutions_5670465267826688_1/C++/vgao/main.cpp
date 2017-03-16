#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

#pragma warning(disable : 4996)

using namespace std;

typedef unsigned long long ull;

const size_t ONE = 0, I = 1, J = 2, K = 3, 
	MINUS_ONE = 4, MINUS_I = 5, MINUS_J = 6, MINUS_K = 7;

size_t multiply[8][8] = {
	{ONE, I, J, K},
	{I, MINUS_ONE, K, MINUS_J},
	{J, MINUS_K, MINUS_ONE, I},
	{K, J, MINUS_I, MINUS_ONE}
}, divide[8][8] = {};

size_t negate[8] = { MINUS_ONE, MINUS_I, MINUS_J, MINUS_K, ONE, I, J, K };

void initialize_table()
{
	for (size_t i = 0; i < 8; ++i) {
		for (size_t j = 0; j < 8; ++j) {
			bool x = i < 4, y = j < 4;
			if (x && y)
				continue;
			multiply[i][j] = multiply[x ? i : negate[i]][y ? j : negate[j]];
			if (x != y)
				multiply[i][j] = negate[multiply[i][j]];
		}
	}
	for (size_t i = 0; i < 8; ++i) {
		for (size_t j = 0; j < 8; ++j)
			divide[multiply[i][j]][i] = j;
	}
}

size_t convert(char c)
{
	if (c == 'i')
		return I;
	else if (c == 'j')
		return J;
	else if (c == 'k')
		return K;
	return numeric_limits<size_t>::max();
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	initialize_table();
	size_t cases; cin >> cases;
	for (size_t _ = 0; _ < cases; ++_) {
		size_t n; ull m;
		cin >> n >> m;
		string s, t; cin >> t;
		size_t mx = m < 8 ? size_t(m) : 8;
		for (size_t i = 0; i < mx; ++i)
			s += t;
		vector<size_t> v(s.size());
		for (size_t i = 0; i < v.size(); ++i) {
			v[i] = convert(s[i]);
			if (i != 0)
				v[i] = multiply[v[i - 1]][v[i]];
		}
		bool flag = false;
		if (v[n + size_t((m - 1) % 4) * n - 1] != MINUS_ONE)
			goto label;
		size_t pos = numeric_limits<size_t>::max();
		for (size_t i = 0; i < min(v.size(), n * 4); ++i) {
			if (v[i] == I) {
				pos = i;
				break;
			}
		}
		if (pos == numeric_limits<size_t>::max())
			goto label;
		for (size_t i = pos + 1; i < min(v.size(), n * 8); ++i) {
			if (divide[v[i]][v[pos]] == J) {
				flag = true;
				break;
			}
		}
	label:
		cout << "Case #" << (_ + 1) << ": " << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}