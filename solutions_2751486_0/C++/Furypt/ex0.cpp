#include <iostream>
using namespace std;

int getNumConsonants(const std::string& string) {
	unsigned long total(0);
	for (unsigned long i(0); i < string.size(); ++i) {
		switch (string[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			break;

		default:
			++total;
		}
	}

	return total;
}

unsigned long process(const string& string, const int& num_consonant) {
	int lastAddedI(-1);
	unsigned long total(0);
	unsigned long size(string.size() - num_consonant + 1);
	for (unsigned long i(0); i < size; ++i) {
		if (getNumConsonants(string.substr(i, num_consonant)) == num_consonant) {
			// multiply [lastAddedI + 1, i] * [i + num_consonant, string.size()]
			total += (i - (lastAddedI + 1) + 1) * (string.size() - (i + num_consonant) + 1);
			lastAddedI = i;
		}
	}

	return total;
}


int main() {
	int num_test;
	cin >> num_test;

	for (int testIndex(0); testIndex < num_test; testIndex++) {
		string word;
		cin >> word;
		int num_consonant;
		cin >> num_consonant;

		cout << "Case #" << testIndex + 1 << ": " << process(word, num_consonant) << endl;
	}

	return 0;
}
