#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void addwords(vector<string> &store, string keys, int k, string prefix, int s) {
	if (s == 0) {
		store.push_back(prefix);
	} else {
		for (int i = 0; i < k; i++) {
			addwords(store, keys, k, prefix + keys[i], s - 1);
		}
	}
}

int count_matches(string haystack, string needle) {
	int c = 0;

	for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
		bool match = true;
		for (int j = 0; j < needle.length(); j++) {
			match &= (haystack[i + j] == needle[j]);
		}

		if (match) c++;
	}

	return c;
}

int main() {
	int ncases;

	cin >> ncases;

	std::cout.precision(10);

	for (int c = 1; c <= ncases; c++) {
		double result;

		int k, l, s;

		cin >> k >> l >> s;

		vector<string> store;

		string keys, target;

		cin >> keys;
		cin >> target;

		addwords(store, keys, k, "", s);

		int total_matches = 0;
		int best_matches = 0;

		for (int i = 0; i < store.size(); i++) {
			int m = count_matches(store[i], target);

			total_matches += m;
			best_matches = max(best_matches, m);
		}

		cerr << total_matches << ", " << store.size() << ", " << best_matches << endl;

		result = (double)best_matches - ((double)total_matches / store.size());

		cout << "Case #" << c << ": " << result << endl;
	}

	return 0;
}
