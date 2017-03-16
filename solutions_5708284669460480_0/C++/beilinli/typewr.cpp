#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long

int getOcc (string s, string word) {
	int S = s.size();
	int L = word.size();
	//cout << s << '\n';
	int c = 0;
	for (int i = 0; i + L <= S; i++) {
		bool all = true;
		for (int j = 0; j < L; j++) {
			if (s[i + j] != word[j]) {
				all = false;
				break;
			}
		}
		if (all) c++;
	}
	return c;
}

int main(void) {
	freopen("B-small-attempt1.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, K, L, S;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> K >> L >> S;
		string keys, word;
		cin >> keys >> word;

		int total = 1, maxOcc = 0, sum = 0;
		for (int i = 0; i < S; i++) total *= K;
		for (int mask = 0; mask < total; mask++) {
			string s(S, ' ');
			int m = mask;
			for (int i = 0; i < S; i++) {
				//cout << m % K << ' ';
				s[i] = keys[m % K];
				m /= K;
			} //cout << '\n';

			int occ = getOcc(s, word);
			sum += occ;
			maxOcc = max(maxOcc, occ);
		}

		printf("Case #%d: %.9f\n", t, maxOcc - (double) sum / total);
	}
	
	return 0;
}
