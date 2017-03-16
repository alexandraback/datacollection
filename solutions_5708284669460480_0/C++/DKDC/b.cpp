#include <iostream>

using namespace std;

double solve(int K, int L, int S);

int main(void)
{
	int T, n = 1;
	int K, L, S;
	
	cin >> T;
	while (n <= T) {
		cout << "Case #" << n++ << ": ";
		cin >> K >> L >> S;
		double answer = solve(K, L, S);
		printf("%.7f\n", answer);
	}
	return 0;
}

double solve(int K, int L, int S)
{
	char key[K];
	char str[L];
	for (int i = 0; i < K; i++) {
		cin >> key[i];
	}
	for (int i = 0; i < L; i++) {
		cin >> str[i];
	}
	double alpC[26] = {0};
	for (int i = 0; i < K; i++) {
		alpC[key[i] - 'A']++;
	}
	int maxB = 1;
	double expB = 1.0;
	for (int i = 0; i < L; i++) {
		if (alpC[str[i] - 'A'] == 0) {
			maxB = 0;
			break;
		}
	}
	if (maxB == 1) {
		char typedStr[S];
		for (int i = 0; i < S; i++) {
			typedStr[i] = 0;
		}
		for (int i = 0; i < L; i++) {
			typedStr[i] = str[i];
		}
		for (int i = 1; i < S; i++) {
			bool count = true;
			for (int j = 0; j < L; j++) {
				if (i + j == S) {
					count = false;
					break;
				} else if (typedStr[i + j] == 0) {
					typedStr[i + j] = str[j];
				} else if (typedStr[i + j] != str[j]) {
					count = false;
					break;
				}
			}
			maxB += count;
		}
	}
	for (int i = 0; i < L; i++) {
		expB *= (alpC[str[i] - 'A'] / K);
	}
	expB *= maxB;

	return maxB - expB;
}
