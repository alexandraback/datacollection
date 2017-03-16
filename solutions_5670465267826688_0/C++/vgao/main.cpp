#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#pragma warning(disable : 4996)

using namespace std;

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
		for (size_t j = 0; j < 8; ++j) {
			divide[multiply[i][j]][i] = j;
			//divide[multiply[i][j]][j] = i;
		}
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
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	initialize_table();
	size_t cases; cin >> cases;
	for (size_t _ = 0; _ < cases; ++_) {
		size_t n, m; cin >> n >> m;
		string s, t; cin >> t;
		for (size_t i = 0; i < m; ++i)
			s += t;
		vector<size_t> v(s.size());
		for (size_t i = 0; i < v.size(); ++i) {
			v[i] = convert(s[i]);
			if (i != 0)
				v[i] = multiply[v[i - 1]][v[i]];
		}
		bool flag = false;
		for (size_t i = 0; i < v.size() - 2; ++i) {
			for (size_t j = i + 1; j < v.size() - 1; ++j) {
				size_t x = v[i], y = divide[v[j]][v[i]], z = divide[v.back()][v[j]];
				if (x == I && y == J && z == K) {
					flag = true;
					goto label;
				}
			}
		}
	label:
		cout << "Case #" << (_ + 1) << ": " << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}