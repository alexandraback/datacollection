#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool consonant(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;
	return true;
}

string S;
long long N, L;

int main()
{
	int T;
	cin >> T;
	for (int Ti = 1; Ti <= T; Ti++)
	{
		// input
		cin >> S;
		cin >> N;
		L = S.length();
		//cout << "S = " << S << "; N = " << N << "; L = " << L << endl;

		// count
		long long answer = 0LL;
		long long laststart = -1LL;
		long long runlength = 0;
		for (long long i = 0; i < L; ++i) {
			// update runlength
			if (consonant(S[i]))
				runlength++;
			else
				runlength = 0;

			// update laststart
			if (runlength >= N) {
				long long increment = i - N + 1;
				laststart = increment;
			}

			// update answer
			if (laststart != -1)
				answer += laststart + 1;
		}

		// output
		cout << "Case #" << Ti << ": " << answer << endl;
		//printf("Case #%d: ", Ti);
	}
	return 0;
}
