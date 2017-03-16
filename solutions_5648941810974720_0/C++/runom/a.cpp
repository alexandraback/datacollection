#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void erase(map<char, int>& m, string s, int n)
{
	for(char c : s) {
		m[c] -= n;
	}
}

int main()
{
	int T; 
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";

		string s;
		cin >> s;

		map<char, int> m;
		for(char c : s) {
			m[c]++;
		}

		int n[10];
		n[0] = m['Z'];
		erase(m, "ZERO", n[0]);

	 	n[2] = m['W'];
		erase(m, "TWO", n[2]);

		n[4] = m['U'];
		erase(m, "FOUR", n[4]);

		n[1] = m['O'];
		erase(m, "ONE", n[1]);

		n[3] = m['R'];
		erase(m, "THREE", n[3]);

		n[6] = m['X'];
		erase(m, "SIX", n[6]);

		n[7] = m['S'];
		erase(m, "SEVEN", n[7]);

		n[5] = m['F'];
		erase(m, "FIVE", n[5]);

		n[8] = m['G'];
		erase(m, "EIGHT", n[8]);

		n[9] = m['I'];
		erase(m, "NINE", n[9]);

		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < n[i]; ++j) {
				cout << i;
			}
		}
		cout << endl;
	}
}
