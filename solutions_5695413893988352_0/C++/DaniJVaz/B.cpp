#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

bool numberFitsScore(ll n, char * score) {
	int l;
	for (l=0; score[l] != '\0'; l++);

	for (int i=l-1; i>=0; i--) {
		if (score[i] != '?' and score[i]-'0' != n%10)
			return false;
		n /= 10;
	}

	if (n==0)
		return true;
	else
		return false;
}

void fillInNumber(char * score, ll n) {
	int l;
	for (l=0; score[l] != '\0'; l++);

	for (int i=l-1; i>=0; i--) {
		score[i] = '0'+(n%10);
		n/=10;
	}
}

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char score1[20], score2[20];
		scanf("%s %s", score1, score2);

		ll minDiff=2000, minC=0, minJ=0;
		for (int i=0; i<1000; i++) {
			if (!numberFitsScore(i, score1))
				continue;
			// printf("%d %s\n", i, score1);

			for (int j=0; j<1000; j++) {
				if (!numberFitsScore(j, score2))
					continue;

				if (i-j >= 0) {
					if (i-j < minDiff or (i-j == minDiff and (i < minC or (i == minC and j < minJ)))) {
						minDiff = i-j;
						minC = i;
						minJ = j;
					}
				}
				else {
					if (j-i < minDiff or (j-i == minDiff and (i < minC or (i == minC and j < minJ)))) {
						minDiff = j-i;
						minC = i;
						minJ = j;
					}
				}
			}
		}

		fillInNumber(score1, minC);
		fillInNumber(score2, minJ);

		printf("Case #%d: %s %s\n", iC, score1, score2);
	}
	return 0;
}