#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma warning (disable : 4996)

//int mul[] = { { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 }, { 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };
vector<vector<int>> mul;

int mult(int a, int b) {
	int ans = 1;
	if (a < 0)
		ans *= -1, a *= -1;
	if (b < 0)
		ans *= -1, b *= -1;
	ans *= mul[a][b];
	return ans;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	mul.resize(5);
	mul[1] = { 0, 1, 2, 3, 4 };
	mul[2] = { 0, 2, -1, 4, -3 };
	mul[3] = { 0, 3, -4, -1, 2 };
	mul[4] = { 0, 4, 3, -2, -1 };
	int K, KK = 0;
	cin >> K;
	while (K-- && ++KK) {
		cout << "Case #" << KK << ": ";
		int n, x;
		cin >> n >> x;
		string s = "", b;
		cin >> b;
		//x = min(x)
		for (int i = 0; i < x; i++)
			s += b;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'i')
				s[i] = 2;
			if (s[i] == 'j')
				s[i] = 3;
			if (s[i] == 'k')
				s[i] = 4;
		}
		string v = s;
		int m = v.length();
		bool ii = false, kk = false, mm = false;
		for (int i = 1; i < m; i++) {
			v[i] = mult(v[i - 1], v[i]);
		}
		for (int i = 0; i < m; i++) {
			if (v[i] == 2)
				ii = true;
			if (v[i] == 4 && ii)
				kk = true;
		}
		if (v[m - 1] == -1)
			mm = true;
		if (ii && kk && mm)
			cout << "YES";
		else
			cout << "NO";
		cout << "\n";
	}
	return 0;
}
