#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("out.txt");

int nums[10];

int main() {
	int tests;
	fin >> tests;
	for (int test = 0; test < tests; ++test) {
		memset(nums, 0, sizeof(nums));
		unordered_map<char, int> m;
		string s;
		fin >> s;
		for (int i = 0; i < s.length(); ++i) {
			++m[s[i]];
		}

		nums[0] = m['Z'];
		m['E'] -= m['Z'];
		m['R'] -= m['Z'];
		m['O'] -= m['Z'];
		m['Z'] = 0;
		nums[6] = m['X'];
		m['S'] -= m['X'];
		m['I'] -= m['X'];
		m['X'] -= 0;
		nums[8] = m['G'];
		m['E'] -= m['G'];
		m['I'] -= m['G'];
		m['H'] -= m['G'];
		m['T'] -= m['G'];
		m['G'] -= 0;
		nums[2] = m['W'];
		m['T'] -= m['W'];
		m['O'] -= m['W'];
		m['W'] = 0;
		nums[7] = m['S'];
		m['E'] -= 2 * m['S'];
		m['V'] -= m['S'];
		m['N'] -= m['S'];
		m['S'] = 0;
		nums[5] = m['V'];
		m['F'] -= m['V'];
		m['I'] -= m['V'];
		m['E'] -= m['V'];
		m['V'] = 0;
		nums[4] = m['F'];
		m['O'] -= m['F'];
		m['U'] -= m['F'];
		m['R'] -= m['F'];
		m['F'] = 0;
		nums[3] = m['R'];
		m['T'] -= m['R'];
		m['H'] -= m['R'];
		m['E'] -= 2 * m['R'];
		m['R'] = 0;
		nums[1] = m['O'];
		nums[9] = (m['N'] - m['O']) / 2;

		fout << "Case #" << test + 1 << ": ";
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < nums[i]; ++j) {
				fout << i;
			}
		}
		fout << endl;
	}

	return 0;
}
