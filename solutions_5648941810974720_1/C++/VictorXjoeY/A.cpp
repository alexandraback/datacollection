#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define N 300

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;

int m[N];
int v[10];

int main(void){
	string str;
	int i, j, k, t;

	// Z means ZERO 0
	// W means TWO 2
	// U means FOUR 4
	// X means SIX 6
	// G means EIGHT 8

	ios::sync_with_stdio(false);

	cin >> t;

	for (i = 0; i < t; i++){
		cin >> str;

		for (j = 0; j < str.size(); j++){
			m[str[j]]++;
		}


		// cout << "para " << str << ": " << endl;

		// cout << "Temos " << m['Z'] << " zeros" << endl;
		// ZERO
		v[0] += m['Z'];
		m['E'] -= m['Z'];
		m['R'] -= m['Z'];
		m['O'] -= m['Z'];
		m['Z'] = 0;

		// cout << "Temos " << m['W'] << " dois" << endl;
		// TWO
		v[2] += m['W'];
		m['T'] -= m['W'];
		m['O'] -= m['W'];
		m['W'] = 0;

		// cout << "Temos " << m['U'] << " quatros" << endl;
		// FOUR
		v[4] += m['U'];
		m['F'] -= m['U'];
		m['O'] -= m['U'];
		m['R'] -= m['U'];
		m['U'] = 0;

		// cout << "Temos " << m['X'] << " seis" << endl;
		// SIX
		v[6] += m['X'];
		m['S'] -= m['X'];
		m['I'] -= m['X'];
		m['X'] = 0;

		// cout << "Temos " << m['G'] << " oitos" << endl;
		// EIGHT
		v[8] += m['G'];
		m['E'] -= m['G'];
		m['I'] -= m['G'];
		m['H'] -= m['G'];
		m['T'] -= m['G'];
		m['G'] = 0;

		// cout << "Temos " << m['F'] << " cincos" << endl;
		// FIVE
		v[5] += m['F'];
		m['I'] -= m['F'];
		m['V'] -= m['F'];
		m['E'] -= m['F'];
		m['F'] = 0;

		// cout << "Temos " << m['H'] << " tres" << endl;
		// THREE
		v[3] += m['H'];
		m['T'] -= m['H'];
		m['R'] -= m['H'];
		m['E'] -= m['H'];
		m['E'] -= m['H'];
		m['H'] = 0;

		// cout << "Temos " << m['I'] << " noves" << endl;
		// NINE
		v[9] += m['I'];
		m['N'] -= m['I'];
		m['N'] -= m['I'];
		m['E'] -= m['I'];
		m['I'] = 0;

		// cout << "Temos " << m['O'] << " uns" << endl;
		// ONE
		v[1] += m['O'];
		m['N'] -= m['O'];
		m['E'] -= m['O'];
		m['O'] = 0;

		// cout << "Temos " << m['V'] << " setes" << endl;
		// SEVEN
		v[7] += m['V'];
		m['S'] -= m['V'];
		m['E'] -= m['V'];
		m['E'] -= m['V'];
		m['N'] -= m['V'];
		m['V'] = 0;

		cout << "Case #" << i + 1 << ": ";
		for (j = 0; j < 10; j++){
			for (k = 0; k < v[j]; k++){
				cout << j;
			}
		}
		cout << endl;

		memset(m, 0, sizeof(m));
		memset(v, 0, sizeof(v));
	}

	return 0;
}