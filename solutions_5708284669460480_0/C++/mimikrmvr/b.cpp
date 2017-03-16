#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int findSuf(string l) {
	int ll = l.size();
	int i = ll - 1;
	while (i > 0 && l.substr(ll - i, i) != l.substr(0, i)) {
		i--;
	}
	return i;
}

int main() {
	ifstream in;
	in.open("B-small-attempt1 (1).in");
	//in.open("input.txt");
	ofstream out;
	out.open("outputB1.txt");
	int t;
	in >> t;
	for (int ti = 1; ti <= t; ti++) {
		int k, l, s;
		in >> k >> l >> s;
		string keyboard;
		in >> keyboard;
		string target;
		in >> target;
		vector<int> p(28, 0);
		for (int i = 0; i < k; i++) {
			p[(int) (keyboard[i] - 'A')]++;
		}
		double chance_l = 1.0;
		for (int i = 0; i < l; i++) {
			double cur_p = p[(int) (target[i] - 'A')] * 1.0 / k;
			chance_l *= cur_p;
		}
		double win = chance_l * (s - l + 1);
		bool can = true;
		for (int i = 0; i < l; i++) {
			if (p[(int) (target[i] - 'A')] == 0) {
				can = false;
			}
		}
		if (!can) {
			out << "Case #" << ti << ": " << fixed << setprecision(9) << 0.0 << endl;
		} else {
			int largestSuf = findSuf(target);
			double all;
			if (largestSuf == l) {
				all = (s - l + 1) * 1.0;
			} else {
				all = (s - l) / (l - largestSuf) + 1;
			}
			out << "Case #" << ti << ": " << fixed << setprecision(9)
					<< all * 1.0 - win << endl;
		}

	}
	out.close();
	return 0;
}
