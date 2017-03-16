#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

typedef uint8_t byte;
typedef int16_t i16;
typedef uint16_t ui16;
typedef int32_t i32;
typedef uint32_t ui32;
typedef int64_t i64;
typedef uint64_t ui64;

#define MOD 1000000007
#define ADD_MOD(a, b) (((a) + (b)) % MOD)
#define MUL_MOD(a, b) i32((i64(a) * i64(b)) % MOD)
#define SUB_MOD(a, b) ((a) >= (b) ? (a) - (b) : (a) + MOD - (b))

void read_word(vector<char> &word, size_t len) {
	string str;
	cin >> str;

	for (size_t i = 0; i < len; ++i) {
		word[i] = str[i];
	}
}

size_t prefix_len(vector<char> &word) {
	size_t n = word.size();
	for (size_t i = 1; i < n; ++i) {
		bool valid = true;
		for (size_t j = 0; j < n - i; ++j) {
			if (word[j] != word[j + i]) {
				valid = false;
				break;
			}
		}

		if (valid) {
			return n - i;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);

	size_t testCount;
	cin >> testCount;

	cout.precision(8);

	for (size_t testIndex = 0; testIndex < testCount; ++testIndex) {
		size_t alphabetLen, wordLen, resLen;
		cin >> alphabetLen >> wordLen >> resLen;

		vector<char> alphabet(alphabetLen);
		vector<char> word(wordLen);

		read_word(alphabet, alphabetLen);
		read_word(word, wordLen);

		map<char, size_t> alphabetMap;
		for (size_t i = 0; i < alphabetLen; ++i) {
			alphabetMap[alphabet[i]]++;
		}

		bool wordValid = true;
		for (size_t i = 0; i < wordLen; ++i) {
			char ch = word[i];
			if (alphabetMap[ch] == 0) {
				wordValid = false;
				break;
			}
		}

		if (!wordValid) {
			cout << "Case #" << testIndex + 1 << ": " << 0 << endl;
			continue;
		}

		size_t addin = wordLen - prefix_len(word);
		size_t maxScore = 1 + (resLen - wordLen) / addin;

		vector<string> wordSuffix;
		string suffix = "";
		for (size_t i = 0; i < wordLen; ++i) {
			suffix += word[wordLen - i - 1];
			wordSuffix.push_back(suffix);
		}

		map<string, double> dpMin1;
		map<string, double> dpMin2;
		double minScore = 0;

		for (size_t i = 0; i < resLen; ++i) {
			for (size_t j = 0; j < wordLen; ++j) {
				char ch = word[wordLen - j - 1];

				size_t chCount = alphabetMap[ch];
				double chP = (double)chCount / alphabetLen;

				if (j == 0) {
					dpMin2[wordSuffix[0]] = chP;
				} else {
					dpMin2[wordSuffix[j]] = chP * dpMin1[wordSuffix[j - 1]];
				}
			}

			swap(dpMin1, dpMin2);
			minScore += dpMin1[wordSuffix.back()];
		}

		cout << "Case #" << testIndex + 1 << ": " << (double)maxScore - minScore << endl;
	}

	return 0;
}
