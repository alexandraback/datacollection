#include <iostream>
#include <stdio.h>

using namespace std;

const char *digit[10] ={
	"ZERO", // Z
	"ONE", // -> O
	"TWO", // W
	"THREE", // -> R
	"FOUR", // U
	"FIVE", // -> F
	"SIX", // X
	"SEVEN",
	"EIGHT", // G
	"NINE",
};

int a[10];
char s[11111];
int n;
char letter[1111];

void check(int d)
{
	for (int i=0; i<strlen(digit[d]); ++i) {
		letter[digit[d][i]]--;
	}
	a[d]++;
}

void solve(int no)
{
	for (int i=0; i<10; ++i) {
		a[i] = 0;
	}
	for (int i='A'; i<='Z'; ++i) {
		letter[i] = 0;
	}
	scanf(" %s", s);
	n = strlen(s);
	for (int i=0; i<n; ++i) {
		letter[s[i]]++;
	}
	// Z
	while (letter['Z'])
		check(0);
	while (letter['W'])
		check(2);
	while (letter['U'])
		check(4);
	while (letter['X'])
		check(6);
	while (letter['G'])
		check(8);
	while (letter['O'])
		check(1);
	while (letter['R'])
		check(3);
	while (letter['F'])
		check(5);
	while (letter['V'])
		check(7);
	while (letter['I'])
		check(9);
	printf("Case #%d: ", no);
	for (int i=0; i<10; ++i) {
		while (a[i]) {
			putchar('0' + i);
			a[i]--;
		}
	}
	putchar('\n');
}

int main()
{
	int T;
	cin >> T;
	for (int i=0; i<T; ++i)
		solve(i+1);
	return 0;
}
