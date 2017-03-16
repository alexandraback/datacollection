#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int ct = 1; ct <= T; ct++) {
		string input;
		cin >> input;

		map<char, int> m;

		string::iterator it = input.begin();

		while (it != input.end()) {
			m[*it]++;
			it++;
		}

		vector<int> qtd(10, 0);

		if (m['Z']) {
			qtd[0] += m['Z'];
			m['E'] -= m['Z'];
			m['R'] -= m['Z'];
			m['O'] -= m['Z'];
		}

		if (m['W']) {
			qtd[2] += m['W'];
			m['T'] -= m['W'];
			m['O'] -= m['W'];
		}

		if (m['X']) {
			qtd[6] += m['X'];
			m['S'] -= m['X'];
			m['I'] -= m['X'];
		}

		if (m['S']) {
			qtd[7] += m['S'];
			m['E'] -= m['S'];
			m['V'] -= m['S'];
			m['E'] -= m['S'];
			m['N'] -= m['S'];
		}

		if (m['V']) {
			qtd[5] += m['V'];
			m['F'] -= m['V'];
			m['I'] -= m['V'];
			m['V'] -= m['V'];
			m['E'] -= m['V'];
		}

		if (m['F']) {
			qtd[4] += m['F'];
			m['O'] -= m['F'];
			m['U'] -= m['F'];
			m['R'] -= m['F'];
		}

		if (m['G']) {
			qtd[8] += m['G'];
			m['E'] -= m['G'];
			m['I'] -= m['G'];
			m['H'] -= m['G'];
			m['T'] -= m['G'];
		}

		if (m['T']) {
			qtd[3] += m['T'];
			m['H'] -= m['T'];
			m['R'] -= m['T'];
			m['E'] -= m['T'];
			m['E'] -= m['T'];
		}

		qtd[1] += m['O'];
		qtd[9] += m['I'];

		cout << "Case #" << ct << ": ";

		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < qtd[i]; j++) 
				cout << i;
		}
		cout << endl;

	}


	return 0;
}