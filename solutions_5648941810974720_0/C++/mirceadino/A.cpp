#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;
const int NMAX = 2000;
const char* DIGITS[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGTH", "NINE"};

int N;
char S[NMAX + 5];
char sol[NMAX + 5];
int L[30];
int LD[30][30];
int freq[20];

void precompute() {
	for (int i = 0; i < 10; i++) {
		int len = strlen(DIGITS[i]);
		for (int j = 0; j < len; j++)
			LD[i][DIGITS[i][j] - 'A']++;
	}
}

void scoate(int digit, int ch) {
	freq[digit] = L[ch - 'A'];
	for (char c = 'A'; c <= 'Z'; c++)
		L[c - 'A'] -= LD[digit][c - 'A'] * freq[digit];
}

char* solve() {
	scanf("%s", S);
	N = strlen(S);
	for (int i = 0; i < N; i++)
		L[S[i] - 'A']++;

	scoate(0, 'Z');
	scoate(6, 'X');
	scoate(8, 'G');
	scoate(2, 'W');
	scoate(4, 'U');
	scoate(3, 'H');
	scoate(1, 'O');
	scoate(5, 'F');
	scoate(7, 'S');
	scoate(9, 'I');

	memset(sol, 0, sizeof(sol));
	for (int i = 0, cnt = 0; i < 10; i++)
		for (int j = 1; j <= freq[i]; j++)
			sol[cnt++] = i + '0';

	return sol;
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int nrtests;

	scanf("%d", &nrtests);

	precompute();

	for (int testnr = 1; testnr <= nrtests; testnr++) {
		printf("Case #%d: ", testnr);
		printf("%s", solve());
		printf("\n");
	}

	return 0;
}