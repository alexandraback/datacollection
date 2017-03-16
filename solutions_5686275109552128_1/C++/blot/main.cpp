#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;

int solve(const vector<int>& plates) {
	
	auto it = max_element(std::begin(plates), std::end(plates));
	int res = *it;

	for (int i = res - 1; i >= 1; --i) {
		int newt = i;
		
		for (const int& p : plates) {
			newt += (p + i - 1) / i - 1;
			if (newt > res)
				break;
		}

		res = min(res, newt);
	}

	return res;
}

int main(int argc, char** argv)
{
	ifstream input("./B-large.in");
	ofstream output("./out.txt");

	int T;
	input >> T;

	for (int i = 1; i <= T; ++i) {
		int d;
		vector<int> v;
		input >> d;
		v.resize(d);
		for (int j = 0; j < d; ++j)
			input >> v[j];

		output << "Case #" << i << ": " << solve(v) << endl;
	}

	return 0;
}
