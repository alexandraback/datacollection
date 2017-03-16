#include "stdafx.h"

int play(set<double> a, set<double> b) {
	int score = 0;
	for (auto i = a.begin(); i != a.end(); ++i) {
		auto j = b.upper_bound(*i);

		if (j != b.end()) {
			b.erase(j);
		} else {
			++score;
			b.erase(b.begin());
		}
	}
	return score;
}

void read(istream& input, int n, set<double>& v) {
	for (int j = 0; j < n; ++j) {
		double tmp;
		input >> tmp;
		v.insert(tmp);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t;

	for (int i = 1; i <= t; ++i) {
		int n;
		input >> n;

		set<double> naomi, ken;

		read(input, n, naomi);
		read(input, n, ken);

		int score1 = play(naomi, ken);
		int score2 = n - play(ken, naomi);

		output << "Case #" << i << ": " << score2 << " " << score1 << endl;
	}


	return 0;
}

