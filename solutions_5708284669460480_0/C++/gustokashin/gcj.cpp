#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

string makestr(string s, int num, int len) {
	string ans = "";
	int sys = s.size();
	for (int i = 0; i < len; i++) {
		ans = s[num % sys] + ans;
		num /= sys;
	}
	return ans;
}

int main() {
	int t;
	int k, l, s;
	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> k >> l >> s;
		int maxinst = 0;
		string kbd, word;
		cin >> kbd;
		cin >> word;
		vector <int> tab(s + 1, 0);
		int inst = 0;
		int vars = pow(kbd.size(), s);
		for (int j = 0; j < vars; j++) {
			inst = 0;
			string sn = makestr(kbd, j, s);
			for (int k = 0; k <= s - word.size(); k++) {
				if (sn.substr(k, word.size()) == word)
					inst++;
			}
			tab[inst]++;
			maxinst = max(maxinst, inst);
		}
		double bananas = maxinst * vars;
		for (int j = 0; j < tab.size(); j++)
			bananas -= j * tab[j];
		cout << "Case #" << cs << ": " << fixed << setprecision(10) << bananas / vars << endl;
	}
	return 0;
}