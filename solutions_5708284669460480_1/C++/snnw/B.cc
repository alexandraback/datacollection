#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int find_max_overlap(const string& str, const string& word) {
	int overlap = 0;

	const char *first = word.c_str();
	const char *last = str.c_str() + str.length();

	for (int i = 1; i < word.length(); i++) {
		if (strncmp(first, last - i, i) == 0) {
			overlap = i;
		}
	}

	return overlap;
}

int max_bananas(const vector<int> &keys, const string& str, int S) {
	for (auto &c : str) {
		if (keys[c - 'A'] == 0)
			return 0;
	}

	string res;

	int repeats = 0;

	while (res.length() <= S) {
		int overlap = find_max_overlap(res, str);

		res.append(str.substr(overlap, string::npos));
		if (res.length() <= S) repeats++;
	}

	return repeats;
}

double expected_bananas(const vector<int> &keys, const string &str, int S,
                        int K) {
    double P = 1.0;

	for (auto &c : str) {
		P *= keys[c - 'A'] / (double)K;
	}

	double E = P * (S - str.length() + 1);

	return E;
}

int main() {
	int T;

	cin >> T;
	for (int test = 1; test <= T; test++) {
		int K, L, S;

		cin >> K >> L >> S;

		string keys, word;
		cin >> keys >> word;

		vector<int> key_counts(26);

		for (char &c : keys) {
			key_counts[c - 'A']++;
		}

		printf("Case #%d: %f\n", test, max_bananas(key_counts, word, S) - expected_bananas(key_counts, word, S, K));
	}
}