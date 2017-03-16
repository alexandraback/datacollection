#include <stdio.h>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

typedef pair <int, int> ii;
typedef pair <long long, long long> ll;


int alp[27];
char s[2005];
int c[11];

void sub(int p, char key, string s) {
	int add = alp[key - 'A'];
	c[p] = add;
	for (int i = 0; i < s.length(); i++) {
		alp[s[i] - 'A'] -= add;
	}
}

void solve() {
	for (int i = 0; i < 26; i++) alp[i] = 0;
	for (int i = 0; i < 11; i++) c[i] = 0;

	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; i++) alp[s[i] - 'A']++;

	sub(0, 'Z', "ZERO");
	sub(6, 'X', "SIX");
	sub(8, 'G', "EIGHT");
	sub(4, 'U', "FOUR");
	sub(5, 'F', "FIVE");
	sub(7, 'V', "SEVEN");
	sub(9, 'I', "NINE");
	sub(3, 'H', "THREE");
	sub(2, 'T', "TWO");
	sub(1, 'O', "ONE");

	for (int i = 0; i <= 9; i++)
		for (int j = 0; j < c[i]; j++)
			printf("%d", i);
	puts("");

}

int main() {
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int R = 1; R <= T; R++) {
		printf("Case #%d: ", R);
		solve();

	}

}