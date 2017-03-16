#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maks;
int c;
int n;
string pattern;

void pref(vector<int> &P, string &S ) {
	unsigned int t = 0, i, n = S.size();
	P.resize(n+1, 0);
	for(i = 2; i < n; i++){
		while (t > 0 && S[t + 1] != S[i]) t = P[t];
		if( S[t+1] == S[i] ) t++;
		P[i] = t;
	}
}
 
int KMP(string &T, string &W ) {
	string S = "#" + W + "#" + T;
	vector<int> P;
	pref(P, S);
	unsigned int i, ws = W.size();
	int result = 0;
	for(i = ws + 2; i < S.size(); i++)	{
		if( P[i] == ws ) { ++result; }
	}
	return result;
}

void permutation_with_repetition(const string &input, string output, int r) {
	if (output.length() == r) {
		int kmp_result = KMP(output, pattern);
		c += kmp_result;
		maks = max(maks, kmp_result);
		++n;
	} else {
		for (int i = 0; i < input.length(); ++i){
			permutation_with_repetition(input, output + input[i], r);
		}
	}
}

void read_str(string &s, int N) {
	for (int i = 0; i < N; ++i) {
		char c = getchar();
		s += c;
	}
	getchar();
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int K, L, S;
		maks = 0; c = 0; n = 0;
		pattern = "";
		scanf("%d %d %d", &K, &L, &S);
		getchar();
		string input;
		read_str(input, K);
		read_str(pattern, L);
		permutation_with_repetition(input, "", S);
		float result = maks - ((float) c / (float) n);
		printf("Case #%d: %.6f\n", t, result);
	}
	return 0;
}