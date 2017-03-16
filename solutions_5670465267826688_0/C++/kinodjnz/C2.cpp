#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int sign(int x) {
	return (x > 0 ? 1 : (x < 0 ? -1: 0));
}

class qt {
public:
	int x;
	explicit qt(int a = 0): x(a) {}
};

qt operator*(qt lhs, qt rhs) {
	int m[4][4] = {
		{1, 2, 3, 4},
		{2, -1, 4, -3},
		{3, -4, -1, 2},
		{4, 3, -2, -1},
	};
	qt q = qt(sign(lhs.x)*sign(rhs.x)*m[abs(lhs.x)-1][abs(rhs.x)-1]);
	return q;
}

bool solve(int X, const string &s)
{
	string t;
	for (int i = 0; i < X; i++)
		t += s;
	int n = t.size();
	vector<qt> v;
	for (int i = 0; i < n; i++) {
		v.emplace_back(t[i]-'i'+2);
	}
	vector<qt> pi;
	pi.resize(n+1);
	pi[0] = qt(1);
	for (int i = 0; i < n; i++) {
		pi[i+1] = pi[i] * v[i];
	}
	vector<qt> pk;
	pk.resize(n+1);
	pk[n] = qt(1);
	for (int i = n-1; i >= 0; i--) {
		pk[i] = v[i] * pk[i+1];
	}
	for (int i = 0; i < n-2; i++) {
		if (pi[i+1].x == 2) {
			qt b = qt(1);
			for (int j = i+1; j < n-1; j++) {
				b = b * v[j];
				if (b.x == 3) {
					if (pk[j+1].x == 4)
						return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		bool ans = solve(X, s);
		cout << "Case #" << t+1 << ": " << (ans ? "YES" : "NO") << endl;
	}
}
