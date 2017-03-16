#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> vp;
long long A, B, X, Xrev, p10, Pali, tmp;
int digits[100], ndigits, digits2[100], ndigits2, i, j;

int NumPali(long long X) {
	int i;
	for (i = 0; i < vp.size(); i++)
		if (vp[i] > X)
			break;
	return i;
}

void GeneratePalindrome(long long P) {
	long long PP = P * P;
	//fprintf(stderr, "pali=%lld\n", P);

	// Check if P is a palindrome.
	ndigits2 = 0;
	tmp = PP;
	while (tmp > 0) {
		ndigits2++;
		digits2[ndigits2] = tmp % 10;
		tmp /= 10;
	}

	for (j = 1; j <= ndigits2; j++)
		if (digits2[j] != digits2[ndigits2 - j + 1])
			break;

	if (j > ndigits2) {
		// OK
		fprintf(stderr, "FSQ: %lld (%lld)\n", PP, P);
		vp.push_back(PP);
	}
}

int main() {
	int tstart = clock();

	for (X = 1; X <= 9; X++)
		GeneratePalindrome(X);

	for (X = 1; X <= 9999; X++) {
		// X is the first part of the palindrome.
		Xrev = X;
		ndigits = 0;
		while (Xrev > 0) {
			ndigits++;
			digits[ndigits] = Xrev % 10;
			Xrev /= 10;
		}

		Xrev = 0;
		p10 = 1;
		for (i = 1; i <= ndigits; i++) {
			Xrev = Xrev * 10 + digits[i];
			p10 *= 10;
		}
		
		// Case 1: Even palindrome.
		Pali = X * p10 + Xrev;
		//printf("%lld %lld\n", X, Pali);
		GeneratePalindrome(Pali);
		
		// Case 2: Odd palndromes.
		for (i = 0; i < 10; i++) {
			Pali = (X * 10 + i) * p10 + Xrev;
			//printf("%lld %lld\n", X, Pali);
			GeneratePalindrome(Pali);
		}
	}

	fprintf(stderr, "vp.size()=%u\n", vp.size());
	fprintf(stderr, "Duration=%.3lf sec\n", (double) (clock() - tstart) / CLOCKS_PER_SEC);

	sort(vp.begin(), vp.end());
	
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C1.out", "w", stdout);

	int T, te;
	scanf("%d", &T);
	
	for (te = 1; te <= T; te++) {
		scanf("%lld %lld", &A, &B);
		fprintf(stderr, "te=%d A=%lld B=%lld\n", te, A, B);
		printf("Case #%d: %d\n", te, NumPali(B) - NumPali(A - 1));
	}
	
	return 0;
}
