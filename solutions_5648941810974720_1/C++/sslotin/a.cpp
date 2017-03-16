#include <bits/stdc++.h>
using namespace std;
// ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

int main(){
	
	int T;
	cin >> T;

	for(int t = 0; t < T; t++){
		map<char, int> a;
		vector<int> b(10, 0);
		string s;
		cin >> s;
		for(int i = 0; i < 26; i++)
			a[ (char) ('A'+i) ] = 0;
		for(size_t i = 0; i < s.size(); i++)
			a[s[i]]++;
		
		b[0] += a['Z'];
		a['E'] -= a['Z'];
		a['R'] -= a['Z'];
		a['O'] -= a['Z'];
		
		b[8] += a['G'];
		a['E'] -= a['G'];
		a['I'] -= a['G'];
		a['H'] -= a['G'];
		a['T'] -= a['G'];

		b[6] += a['X'];
		a['S'] -= a['X'];
		a['I'] -= a['X'];

		b[2] += a['W'];
		a['T'] -= a['W'];
		a['O'] -= a['W'];

		b[3] += a['T'];
		a['H'] -= a['T'];
		a['R'] -= a['T'];
		a['E'] -= a['T'];
		a['E'] -= a['T'];

		b[4] += a['R'];
		a['F'] -= a['R'];
		a['O'] -= a['R'];
		a['U'] -= a['R'];

		b[5] += a['F'];
		a['I'] -= a['F'];
		a['V'] -= a['F'];
		a['E'] -= a['F'];

		b[1] += a['O'];
		a['N'] -= a['O'];
		a['E'] -= a['O'];

		b[9] += a['I'];

		b[7] += a['S'];

		cout << "Case #" << t+1 << ": ";
		for(int i = 0; i <= 9; i++)
			for(int j = 0; j < b[i]; j++)
				cout << i;
		cout << endl;
	}

	return 0;
}
