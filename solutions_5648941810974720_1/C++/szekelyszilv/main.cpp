#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solve(const string& s)
{
	int chars[256];
	for(int i = 0; i < 256; i++) {
		chars[i] = 0;
	}
	for(char c : s) {
		++chars[c];
	}

	string sol = "";

	//printf("%c %d\n", 'Z', chars['Z']);
	sol += string(chars['Z'], '0');
	chars['E'] -= chars['Z'];
	chars['R'] -= chars['Z'];
	chars['O'] -= chars['Z'];
	chars['Z'] -= chars['Z'];

	//printf("%c %d\n", 'W', chars['W']);
	sol += string(chars['W'], '2');
	chars['T'] -= chars['W'];
	chars['O'] -= chars['W'];
	chars['W'] -= chars['W'];

	//printf("%c %d\n", 'U', chars['U']);
	sol += string(chars['U'], '4');
	chars['F'] -= chars['U'];
	chars['O'] -= chars['U'];
	chars['R'] -= chars['U'];
	chars['U'] -= chars['U'];

	//printf("%c %d\n", 'X', chars['X']);
	sol += string(chars['X'], '6');
	chars['S'] -= chars['X'];
	chars['I'] -= chars['X'];
	chars['X'] -= chars['X'];

	//printf("%c %d\n", 'G', chars['G']);
	sol += string(chars['G'], '8');
	chars['E'] -= chars['G'];
	chars['I'] -= chars['G'];
	chars['T'] -= chars['G'];
	chars['H'] -= chars['G'];
	chars['G'] -= chars['G'];

	//printf("%c %d\n", 'T', chars['T']);
	sol += string(chars['T'], '3');
	chars['H'] -= chars['T'];
	chars['R'] -= chars['T'];
	chars['E'] -= chars['T'];
	chars['E'] -= chars['T'];
	chars['T'] -= chars['T'];

	//printf("%c %d\n", 'S', chars['S']);
	sol += string(chars['S'], '7');
	chars['E'] -= chars['S'];
	chars['V'] -= chars['S'];
	chars['E'] -= chars['S'];
	chars['N'] -= chars['S'];
	chars['S'] -= chars['S'];

	//printf("%c %d\n", 'O', chars['O']);
	sol += string(chars['O'], '1');
	chars['N'] -= chars['O'];
	chars['E'] -= chars['O'];
	chars['O'] -= chars['O'];

	//printf("%c %d\n", 'F', chars['F']);
	sol += string(chars['F'], '5');
	chars['I'] -= chars['F'];
	chars['V'] -= chars['F'];
	chars['E'] -= chars['F'];
	chars['F'] -= chars['F'];

	//printf("%c %d\n", 'E', chars['E']);
	sol += string(chars['E'], '9');
	chars['N'] -= chars['E'];
	chars['I'] -= chars['E'];
	chars['N'] -= chars['E'];
	chars['E'] -= chars['E'];

	sort(sol.begin(), sol.end());

	return sol;
}

int main()
{
	int c;
	cin >> c;
	for (int i = 1; i <= c; i++) {
		int n;
		string s;
		cin >> s;
		cout << "Case #" << i << ": " << solve(s) << endl;
	}
}
