#include <iostream>
#include <math.h>
#include <fstream>
#include <stdio.h>

using namespace std;

int T, K, L, S;

ifstream fin ("B-small-attempt2.in");
ofstream fout ("B-small-attempt2.out");

int freq[26];
char target[100];

int main() {
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		fin >> K >> L >> S;
		fill_n(freq, 26, 0);
		for (int i = 0; i < K; ++i) {
			char c;
			fin >> c;
			freq[c - 'A']++;
		}
		for (int i = 0; i < L; ++i)
			fin >> target[i];

/*		for (int i = 0; i < 26; ++i)
			printf("freq[%d]: %d, ", i, freq[i]);
		printf("\n");*/

		bool possible = true;
		for (int l = 0; l < L; ++l)
			if (freq[target[l] - 'A'] == 0)
				possible = false;

		int maxnum = 0;
		if (possible && S >= L) {
			int pos = 1;
			bool isSuffix = false;
			while (pos < L && !isSuffix) {
				isSuffix = true;
				for (int i = pos; i < L; ++i) {
					if (target[i] != target[i - pos])
						isSuffix = false;
				}
				if (!isSuffix)
					pos++;
			}
//			printf("pos: %d\n", pos);
			maxnum = 1 + (S - L) / pos;
		}

		double expected = 0.0;
		if (S >= L) {
			int numerator = 1;
			int denominator = 1;
			for (int i = 0; i < L; ++i)
				numerator *= freq[target[i] - 'A'];
			for (int i = 0; i < L; ++i)
				denominator *= K;
			double prob = 1.0;
//			printf("prob: %f\n", prob);
			expected = (double)(numerator * (S - L + 1)) / denominator;
		}
//		printf("Case %d: maxnum %d, expected %f, possible: %d\n", t, maxnum, expected, possible);

		printf("Case #%d: %f\n", t, maxnum - expected);
	}
	return 0;
}
