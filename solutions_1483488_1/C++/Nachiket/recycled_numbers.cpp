#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

void solve_case(void)
{
	unsigned A, B;
	unsigned count = 0;
	cin >> A >> B;
	unsigned num_digits = 0;
	unsigned multiplier = 1;
	for(unsigned tempA = A; tempA != 0; tempA /= 10) {
		num_digits++;
		multiplier = multiplier * 10;
	}
	multiplier /= 10;
	for (unsigned i = A; i <= B; i++) {
		unsigned rotated_i = i;
		vector<pair<unsigned, unsigned> > pairs;
		for (unsigned j = 0; j < num_digits; j++) {
			int mod = rotated_i % 10;
			rotated_i = rotated_i / 10;
			if (mod == 0) {
				continue;
			} else {
				rotated_i = multiplier * mod + rotated_i;
			}
			if ((rotated_i > i) && (rotated_i <= B) 
					    && (find(pairs.begin(), pairs.end(), 
					             pair<unsigned, unsigned>(i, rotated_i)) == pairs.end())) {
				pairs.push_back(pair<unsigned, unsigned>(i, rotated_i));
				count++;
			}
		}
	}
	cout << count;
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
