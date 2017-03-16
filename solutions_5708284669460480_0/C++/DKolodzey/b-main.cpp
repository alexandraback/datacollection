#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long double total_matches = 0;
long double total_variants = 0;
long double max_matches = 0;

int K, L, S;

long double count_matches(string word, string text) {
	long double ans = 0;
	size_t pos = 0;
	while (pos != string::npos) {
		pos = text.find(word, pos);
		if (pos != string::npos) {
			++pos;
			++ans;
		}
	}
	return ans;
}

void gen(string word, string keys, string text) {
	if (text.length() == S) {
		++total_variants;
		max_matches = max(count_matches(word, text), max_matches);
		total_matches += count_matches(word, text);
		return;
	}
	for (int i = 0; i < keys.length(); ++i) {
		gen(word, keys, text + keys[i]);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> K >> L >> S;
		string keys;
		cin >> keys;
		string word;
		cin >> word;

		total_matches = 0;
		total_variants = 0;
		max_matches = 0;
		gen(word, keys, "");
		cout.precision(9);
		cout << "Case #" << t << ": " << fixed
		<< max_matches -  (total_matches/total_variants) << endl;
	}
	return 0;
}
