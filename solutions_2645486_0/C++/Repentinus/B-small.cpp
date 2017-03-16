#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int add(int E, int const R, int const max) {
	E += R;
	if (E > max) {
		E = max;
	}
	return E;
}

int solve(int E, int max, int R, vector <int> const& v, int o) {
	vector <int> a;
	for (int i = 0; i <= E; ++i) {
		a.push_back(i * v[o] + (o < v.size() - 1 ? solve(add(E-i,R,max),max,R,v,o+1) : 0));
	}
	return *max_element(a.begin(), a.end());
}

int main(int const argc, char const* const* argv)
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; ++i) {
		int E, R, N;
		cin >> E >> R >> N;
		vector <int> v;
		for (int j = 0; j < N; ++j) {
			int a; cin >> a; v.push_back(a);
		}
		cout << "Case #" << (i + 1) << ": " << solve(E, E, R, v, 0) << endl;
	}
	return 0;
}
