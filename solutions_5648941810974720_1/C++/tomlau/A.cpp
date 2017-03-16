#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	cin >> T;
	for (int t=1; t<=T; t++) {
		string s;
		cin >> s;
		map <char, int> MC;
		vector <int> C(10);
		for (auto c:s) MC[c]++;

		C[0] = MC['Z'];
		MC['E'] -= C[0];
		MC['O'] -= C[0];

		C[2] = MC['W'];
		MC['O'] -= C[2];

		C[4] = MC['U'];
		MC['F'] -= C[4];
		MC['O'] -= C[4];
		C[5] = MC['F'];

		C[6] = MC['X'];
		MC['S'] -= C[6];

		C[8] = MC['G'];
		MC['H'] -= C[8];

		C[1] = MC['O'];
		MC['N'] -= C[1];

		C[3] = MC['H'];
		C[7] = MC['S'];
		MC['N'] -= C[7];
		MC['V'] -= C[7];

		C[9] = MC['N'] / 2;

		string ans;
		for (int i=0; i<=9; i++)
			ans += string(C[i], '0'+i);

		cout << "Case #" << t << ": " << ans << endl;
	}
}
