#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;

using namespace std;

bool numberFitsScore(ll n, char * score, int l) {
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

ll absll(ll a) {
	if (a<0)
		return -a;
	else
		return a;
}

bool best(ll s11, ll s12, ll s21, ll s22) {
	if (s11 < 0 or s12 < 0)
		return false;
	if (s21 < 0 or s22 < 0)
		return true;

	if (absll(s12-s11) > absll(s22-s21))
		return false;
	if (absll(s12-s11) < absll(s22-s21))
		return true;

	if (s11 > s21)
		return false;
	if (s11 < s21)
		return true;

	if (s12 < s22)
		return true;
	return false;
}

enum sign {LESS = 0, EQUAL = 1, GREATER = 2};

int main() {
	int iC=0, nC;
	scanf("%d", &nC);
	for (iC=1; iC<=nC; iC++) {
		char score1[20], score2[20];
		scanf("%s %s", score1, score2);

		int l=0;
		for (; score1[l] != '\0' or score2[l] != '\0'; l++);

		// These tables store the best possibilities for the i first digits where s1 < s2, s1 = s2, s1 > s2
		ll table1[3][20], table2[3][20];
		fill(table1[0], table1[0]+20, -1);
		fill(table1[1], table1[1]+20, -1);
		fill(table1[2], table1[2]+20, -1);
		fill(table2[0], table2[0]+20, -1);
		fill(table2[1], table2[1]+20, -1);
		fill(table2[2], table2[2]+20, -1);
		table1[EQUAL][0] = 0;
		table2[EQUAL][0] = 0;

		for (int i=1; i<=l; i++) {
			for (int d1 = 0; d1<10; d1++) {
				for (int d2 = 0; d2<10; d2++) {
					ll s1l = table1[LESS][i-1]*10 + d1, s2l = table2[LESS][i-1]*10+d2;
					if (table1[LESS][i-1] < 0 or table2[LESS][i-1] < 0)
						s1l = s2l = -1;

					ll s1e = table1[EQUAL][i-1]*10 + d1, s2e = table2[EQUAL][i-1]*10+d2;
					if (table1[EQUAL][i-1] < 0 or table2[EQUAL][i-1] < 0)
						s1e = s2e = -1;

					ll s1g = table1[GREATER][i-1]*10 + d1, s2g = table2[GREATER][i-1]*10+d2;
					if (table1[GREATER][i-1] < 0 or table2[GREATER][i-1] < 0)
						s1g = s2g = -1;

					if (s1l >= 0 and numberFitsScore(s1l, score1, i) and numberFitsScore(s2l, score2, i)) {
						if (best(s1l, s2l, table1[LESS][i], table2[LESS][i])) {
							// printf("a%I64d %I64d\n", s1l, s2l);
							table1[LESS][i] = s1l;
							table2[LESS][i] = s2l;
						}
					}

					if (s1g >= 0 and numberFitsScore(s1g, score1, i) and numberFitsScore(s2g, score2, i)) {
						if (best(s1g, s2g, table1[GREATER][i], table2[GREATER][i])) {
							// printf("b%I64d %I64d\n", s1g, s2g);
							table1[GREATER][i] = s1g;
							table2[GREATER][i] = s2g;
						}
					}

					if (s1e >= 0 and s1e < s2e and numberFitsScore(s1e, score1, i) and numberFitsScore(s2e, score2, i)) {
						if (best(s1e, s2e, table1[LESS][i], table2[LESS][i])) {
							// printf("c%I64d %I64d\n", s1e, s2e);
							table1[LESS][i] = s1e;
							table2[LESS][i] = s2e;
						}
					}

					if (s1e >= 0 and s1e == s2e and numberFitsScore(s1e, score1, i) and numberFitsScore(s2e, score2, i)) {
						if (best(s1e, s2e, table1[EQUAL][i], table2[EQUAL][i])) {
							// printf("d%I64d %I64d\n", s1e, s2e);
							table1[EQUAL][i] = s1e;
							table2[EQUAL][i] = s2e;
						}
					}

					if (s1e >= 0 and s1e > s2e and numberFitsScore(s1e, score1, i) and numberFitsScore(s2e, score2, i)) {
						if (best(s1e, s2e, table1[GREATER][i], table2[GREATER][i])) {
							// printf("e%I64d %I64d\n", s1e, s2e);
							table1[GREATER][i] = s1e;
							table2[GREATER][i] = s2e;
						}
					}
				}
			}
		}

		ll best1 = table1[LESS][l], best2 = table2[LESS][l];
		if (best(table1[EQUAL][l], table2[EQUAL][l], best1, best2)) {
			best1 = table1[EQUAL][l];
			best2 = table2[EQUAL][l];
		}
		if (best(table1[GREATER][l], table2[GREATER][l], best1, best2)) {
			best1 = table1[GREATER][l];
			best2 = table2[GREATER][l];
		}

		fillInNumber(score1, best1);
		fillInNumber(score2, best2);

		printf("Case #%d: %s %s\n", iC, score1, score2);
	}
	return 0;
}