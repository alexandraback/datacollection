#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

string next(string s) {
	int num = stoi(s) + 1;
	return to_string(num);
}

bool check(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '?')
			continue;
		if (a[i] != b[i])
			return false;
	}
	return true;
}

int main() {
	int c, t, i, m, diff, gamb;
	char aux1[20], aux2[20];
	string coder, jammer, temp1, temp2, res1, res2, reset;

	c = 1;
	scanf("%d", &t);
	while (t--) {
		m = INT_MAX;
		scanf("%s", aux1);
		scanf("%s", aux2);
		res1 = temp1 = coder = string(aux1);
		res2 = temp2 = jammer = string(aux2);

		for (int i = 0; i < coder.size(); i++) {
			if (temp1[i] == '?')
				temp1[i] = '0';
			if (temp2[i] == '?')
				temp2[i] = '0';
			res1[i] = '9';
			res2[i] = '9';
		}

		reset = temp2;
		while (true) {
			if (temp1.size() > coder.size())
				break;
			temp2 = reset;
			gamb = INT_MAX;
			while (true) {
				if (temp2.size() > jammer.size())
					break;
				diff = abs(stoi(temp1) - stoi(temp2));
				if (gamb < diff) {
					break;
				}
				gamb = diff;
				if (diff <= m) {
					if (diff == m) {
						if (stoi(temp1) <= stoi(res1) && stoi(temp2) <= stoi(res2)) {
							res1 = temp1;
							res2 = temp2;
							m = diff;
						}
					}
					else {
						res1 = temp1;
						res2 = temp2;
						m = diff;
					}
				}
				
				temp2 = next(temp2);
				while (temp2.size() < jammer.size())
					temp2 = "0" + temp2;
				while (!check(jammer, temp2) && temp2.size() == jammer.size()) {
					temp2 = next(temp2);
					while (temp2.size() < jammer.size())
						temp2 = "0" + temp2;
				}
			}
			temp1 = next(temp1);
			while (temp1.size() < coder.size())
				temp1 = "0" + temp1;
			while (!check(coder, temp1) && temp1.size() == coder.size()) {
				temp1 = next(temp1);
				while (temp1.size() < coder.size())
					temp1 = "0" + temp1;
			}
			if (m == 0)
				break;
		}

		cout << "Case #" << c << ": ";
		c++;
		for (int i = 0; i < res1.size(); i++)
			cout << res1[i];
		cout << " ";
		for (int i = 0; i < res2.size(); i++)
			cout << res2[i];
		cout << endl;
	}

	/*
	int c, t, i;
	char s[2001];
	unordered_map<char, int> m;
	string output, aux[10];

	c = 1;
	scanf("%d", &t);
	while (t--) {
		for (i = 0; i < 10; i++)
			aux[i] = "";
		output = "";
		scanf("%s", s);
		for (i = 0; s[i] != '\0'; i++) 
			m[s[i]] = 0;
		for (i = 0; s[i] != '\0'; i++) 
			m[s[i]]++;

		if (m['Z'] > 0) {
			for (i = 0; i < m['Z']; i++)
				aux[0] += "0";
			m['E'] -= m['Z'];
			m['R'] -= m['Z'];
			m['O'] -= m['Z'];
			m['Z'] = 0;
		}
		if (m['W'] > 0) {
			for (i = 0; i < m['W']; i++)
				aux[2] += "2";
			m['T'] -= m['W'];
			m['O'] -= m['W'];
			m['W'] = 0;
		}
		if (m['X'] > 0) {
			for (i = 0; i < m['X']; i++)
				aux[6] += "6";
			m['S'] -= m['X'];
			m['I'] -= m['X'];
			m['X'] = 0;
		}
		if (m['S'] > 0) {
			for (i = 0; i < m['S']; i++)
				aux[7] += "7";
			m['E'] -= m['S'] * 2;
			m['V'] -= m['S'];
			m['N'] -= m['S'];
			m['S'] = 0;
		}
		if (m['V'] > 0) {
			for (i = 0; i < m['V']; i++)
				aux[5] += "5";
			m['F'] -= m['V'];
			m['I'] -= m['V'];
			m['E'] -= m['V'];
			m['V'] = 0;
		}
		if (m['G'] > 0) {
			for (i = 0; i < m['G']; i++)
				aux[8] += "8";
			m['E'] -= m['G'];
			m['I'] -= m['G'];
			m['H'] -= m['G'];
			m['T'] -= m['G'];
			m['G'] = 0;
		}
		if (m['U'] > 0) {
			for (i = 0; i < m['U']; i++)
				aux[4] += "4";
			m['F'] -= m['U'];
			m['O'] -= m['U'];
			m['R'] -= m['U'];
			m['U'] = 0;
		}
		if (m['O'] > 0) {
			for (i = 0; i < m['O']; i++)
				aux[1] += "1";
			m['N'] -= m['O'];
			m['E'] -= m['O'];
			m['O'] = 0;
		}
		if (m['N'] > 0) {
			for (i = 0; i < m['N'] / 2; i++)
				aux[9] += "9";
			m['E'] -= m['N'];
			m['I'] -= m['N'];
			m['N'] = 0;
		}
		if (m['H'] > 0) {
			for (i = 0; i < m['H']; i++)
				aux[3] += "3";
			m['T'] -= m['H'];
			m['R'] -= m['H'];
			m['E'] -= m['H'] * 2;
			m['H'] = 0;
		}

		cout << "Case #" << c << ": ";
		for (i = 0; i < 10; i++)
			output += aux[i];
		for (i = 0; i < output.size(); i++)
			cout << output[i];
		cout << endl;
		c++;
	}
	*/
	return 0;
}