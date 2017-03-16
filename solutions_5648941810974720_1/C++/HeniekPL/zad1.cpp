#include <cstdio>
#include <cstdlib>

using namespace std;

const int S_MAX = 2000;

char S[S_MAX];
int USED[S_MAX];
int W[10];

int R[255];
// !U!W!Z O => ONE
// ? F => FIVE
// ?  S => SEVEN
// ? H => THREE
// ? => NINE
// Z => ZERO
// W => TWO
// U => FOUR
// X => SIX
// G => EIGHT
void ZERO() {
	W[0]++;
	R['Z']++;
	R['E']++;
	R['R']++;
	R['O']++;
}
void ONE() {
	W[1]++;
	R['O']++;
	R['N']++;
	R['E']++;
}
void TWO() {
	W[2]++;
	R['W']++;
	R['W']++;
	R['O']++;
}
void THREE() {
	W[3]++;
	R['T']++;
	R['H']++;
	R['R']++;
	R['E']++;
	R['E']++;
}
void FOUR() {
	W[4]++;
	R['F']++;
	R['O']++;
	R['U']++;
	R['R']++;
}
void FIVE() {
	W[5]++;
	R['F']++;
	R['I']++;
	R['V']++;
	R['E']++;
}
void SIX() {
	W[6]++;
	R['S']++;
	R['I']++;
	R['X']++;
}
void SEVEN() {
	W[7]++;
	R['S']++;
	R['E']++;
	R['V']++;
	R['E']++;
	R['N']++;
}
void EIGHT() {
	W[8]++;
	R['E']++;
	R['I']++;
	R['G']++;
	R['H']++;
	R['T']++;
}
void NINE() {
	W[9]++;
	R['N']++;
	R['I']++;
	R['N']++;
	R['E']++;
}
void mark_used(int n) {
	for (int i = 0; i < n; ++i) {
		if (!USED[i] && R[S[i]] > 0) {
			USED[i] = 1;
			R[S[i]]--;
		}
	}
}
int main() {
	int T;
	scanf("%d", &T); getchar();
	for (int t = 1; t <= T; ++t) {
		char c;
		int n = 0;
		for (int i = 0; i < 10; ++i) {
			W[i] = 0;
		}
		for (int i = 0; i < 255; ++i) R[i] = 0;
		while ((c = getchar()) != '\n') {
			USED[n] = 0;
			S[n++] = c;
			if (c == 'Z') {
				ZERO();
			} else if (c == 'W') {
				TWO();
			} else if (c == 'U') {
				FOUR();
			} else if (c == 'X') {
				SIX();
			} else if (c == 'G') {
				EIGHT();
			}
		}
		mark_used(n);
		for (int i = 0; i < n; ++i) {
			if (!USED[i] && S[i] == 'O') ONE();
			else if (!USED[i] && S[i] == 'H') THREE();
			else if (!USED[i] && S[i] == 'F') FIVE();
			else if (!USED[i] && S[i] == 'S') SEVEN();
		}
		mark_used(n);
		for (int i = 0; i < n; ++i) {
			if (!USED[i] && S[i] == 'I') NINE();
		}
		mark_used(n);
		printf("Case #%d: ", t);
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < W[i]; ++j) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}