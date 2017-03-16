#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <stdint.h>
#include <bitset>
#include <cmath>

#define INPUTFILE "B-small-attempt1.in"
#define OUTPUTFILE "BB-small-attempt1.out"


using namespace std;

void solve_one() {
	uint64_t B, M;
	cin >> B >> M;
	uint64_t k = 1;
	uint64_t select = 1;

	k = 1 << (B -2);

	if (M > k) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	cout << "POSSIBLE" << endl;
	--M;
	for (int i = B-2; i >= 0; --i) {
		if (M & (1ull << i)) {
			cout << '1';
		} else cout << '0';
	}
	cout << '1';
	cout << endl;

	for (int i = 1;i < B; i++) {
		for (int j = 0; j < B; j++) {
			if (i>=j) {
				cout << '0';
				continue;
			}

			cout << '1';
		}
		cout << endl;
	}
}


int main()
{
	int T, cases = 0;
	string dummy;

	freopen(INPUTFILE,"r",stdin);
	freopen(OUTPUTFILE,"w",stdout);

	cin >> T;

	getline(cin, dummy);

	while (T--) {

		cout << "case #" << ++cases << ": ";

		solve_one();

		//cout << endl;
	}

	return 0;
}

