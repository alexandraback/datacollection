#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Kingdom Rush

int doit(vector <pair <int, int> > &ba)
{
	sort(ba.begin(), ba.end());
	vector <bool> level1comp(ba.size(), false);
	int ret = 0;
	int stars = 0;
	for (int i = 0; i < ba.size(); i++) {
		int j = (int)ba.size() - 1;
		while (stars < ba[i].first) {
			if (j < 0) {
				return -1;
			}
			if (!level1comp[j] && stars >= ba[j].second) {
				ret++;
				stars++;
				level1comp[j] = true;
				j = ba.size();
			}
			j--;
		}
		stars += (level1comp[i] ? 1 : 2);
		ret++;
		level1comp[i] = true;
	}
	return ret;
}

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int N;
		cin >> N;
		vector <pair <int, int> > ba(N);
		for (int i = 0; i < N; i++) {
			cin >> ba[i].second >> ba[i].first;
		}
		int ret = doit(ba);
		cout << "Case #" << caseno << ": ";
		if (ret < 0) {
			cout << "Too Bad" << endl;
		} else {
			cout << ret << endl;
		}
	}

	return 0;
}
