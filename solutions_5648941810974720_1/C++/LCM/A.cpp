#include<bits/stdc++.h>

int t, c[26], n[10];
char s[2005];

void solve(int x) {
	scanf("%s", s);
	for (int i = 0; i < 26; i++) c[i] = 0;
	for (int i = 0; i < 10; i++) n[i] = 0;
	for (int i = 0; s[i]; i++) c[s[i] - 'A']++;
	n[0] = c['Z' - 'A'];
	n[2] = c['W' - 'A'];
	n[4] = c['U' - 'A'];
	n[6] = c['X' - 'A'];
	n[8] = c['G' - 'A'];
	c['E' - 'A'] -= n[0] + n[8];
	c['R' - 'A'] -= n[0] + n[4];
	c['O' - 'A'] -= n[0] + n[2] + n[4];
	c['T' - 'A'] -= n[2] + n[8];
	c['F' - 'A'] -= n[4];
	c['S' - 'A'] -= n[6];
	c['I' - 'A'] -= n[6] + n[8];
	c['H' - 'A'] -= n[8];
	n[1] = c['O' - 'A'];
	n[3] = c['T' - 'A'];
	n[5] = c['F' - 'A'];
	n[7] = c['S' - 'A'];
	n[9] = c['I' - 'A'] - n[5];
	printf("Case #%d: ", x);
	for (int i = 0; i < 10; i++) for (int j = 0; j < n[i]; j++) printf("%d", i);
	printf("\n");
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 0; i < t; i++) solve(i + 1);
	scanf("\n");
	return 0;
}

/*
ZERO : Z
TWO : W
FOUR : U
SIX : X
EIGHT : G

ONE : O
THREE : T
FIVE : F
SEVEN : S

NINE : N
*/
