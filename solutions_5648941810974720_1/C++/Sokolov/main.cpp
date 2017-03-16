#pragma comment(linker, "/STACK:500000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define y0 y0ChloeGraceMoretz
#define y1 y1ChloeGraceMoretz
#define ll long long
int nextInt() { int n; scanf("%d", &n); return n; }
ll nextLong() { ll n; scanf("%lld", &n); return n; }
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

char s[2009];
int cnt[26];
int ans[10];

int main() {
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < 26; ++i) {
			cnt[i] = 0;
		}
		for (int i = 0; i <= 9; ++i) {
			ans[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			++cnt[s[i] - 'A'];
		}
		while (cnt['Z' - 'A'] > 0) { // "ZERO"
			++ans[0];
			--cnt['Z' - 'A'];
			--cnt['E' - 'A'];
			--cnt['R' - 'A'];
			--cnt['O' - 'A'];
		}
		while (cnt['W' - 'A'] > 0) { // "TWO"
			++ans[2];
			--cnt['T' - 'A'];
			--cnt['W' - 'A'];
			--cnt['O' - 'A'];
		}
		while (cnt['X' - 'A'] > 0) { // "SIX"
			++ans[6];
			--cnt['S' - 'A'];
			--cnt['I' - 'A'];
			--cnt['X' - 'A'];
		}
		while (cnt['U' - 'A'] > 0) { // "FOUR"
			++ans[4];
			--cnt['F' - 'A'];
			--cnt['O' - 'A'];
			--cnt['U' - 'A'];
			--cnt['R' - 'A'];
		}
		while (cnt['U' - 'A'] > 0) { // "FOUR"
			++ans[4];
			--cnt['F' - 'A'];
			--cnt['O' - 'A'];
			--cnt['U' - 'A'];
			--cnt['R' - 'A'];
		}
		while (cnt['F' - 'A'] > 0) { // "FIVE"
			++ans[5];
			--cnt['F' - 'A'];
			--cnt['I' - 'A'];
			--cnt['V' - 'A'];
			--cnt['E' - 'A'];
		}
		while (cnt['O' - 'A'] > 0) { // "ONE"
			++ans[1];
			--cnt['O' - 'A'];
			--cnt['N' - 'A'];
			--cnt['E' - 'A'];
		}
		while (cnt['S' - 'A'] > 0) { // "SEVEN"
			++ans[7];
			--cnt['S' - 'A'];
			--cnt['E' - 'A'];
			--cnt['V' - 'A'];
			--cnt['E' - 'A'];
			--cnt['N' - 'A'];
		}
		while (cnt['G' - 'A'] > 0) { // "EIGHT"
			++ans[8];
			--cnt['E' - 'A'];
			--cnt['I' - 'A'];
			--cnt['G' - 'A'];
			--cnt['H' - 'A'];
			--cnt['T' - 'A'];
		}
		while (cnt['T' - 'A'] > 0) { // "THREE"
			++ans[3];
			--cnt['T' - 'A'];
			--cnt['H' - 'A'];
			--cnt['R' - 'A'];
			--cnt['E' - 'A'];
			--cnt['E' - 'A'];
		}
		while (cnt['N' - 'A'] > 0) { // "NINE"
			++ans[9];
			--cnt['N' - 'A'];
			--cnt['I' - 'A'];
			--cnt['N' - 'A'];
			--cnt['E' - 'A'];
		}
		printf("Case #%d: ", tt);
		for (int i = 0; i <= 9; ++i) {
			while (ans[i] > 0) {
				printf("%d", i);
				--ans[i];
			}
		}
		printf("\n");
	}
	return 0;
}