#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


int N;

int carlen[100];
char cars[100][104];

int start_ch[100];
int end_ch[100];

bool used[26];
int midLetter[26];

int endStartLetter[26];
int prev_ch[26];
int next_ch[26];

bool checkEachCar(int car)
{
	for (int i = 0; i < 26; i++) {
		used[i] = false;
	}

	int now = -1;
	int len = carlen[car];
	for (int i = 0; i < len; i++) {
		int c = cars[car][i] - 'a';
		if (c == now) {
			continue;
		}
		if (used[c]) {
			return false;
		}
		used[c] = true;
		now = c;
	}
	return true;
}

bool checkMidLetter()
{
	for (int i = 0; i < 26; i++) {
		midLetter[i] = -1;
	}

	for (int i = 0; i < N; i++) {
		int len_1 = carlen[i] - 1;
		for (int j = 1; j < len_1; j++) {
			int c = cars[i][j] - 'a';
			if (c == start_ch[i] || c == end_ch[i]) {
				continue;
			}
			if (midLetter[c] != i && midLetter[c] != -1) {
				return false;
			}
			midLetter[c] = i;
		}
	}

	for (int i = 0; i < N; i++) {
		if (midLetter[start_ch[i]] != -1) {
			return false;
		}
		if (midLetter[end_ch[i]] != -1) {
			return false;
		}
	}
	return true;
}

bool linkLetters()
{
	for (int i = 0; i < 26; i++) {
		endStartLetter[i] = 0;
		prev_ch[i] = -1;
		next_ch[i] = -1;
	}

	for (int i = 0; i < N; i++) {
		int s = start_ch[i];
		int e = end_ch[i];
		if (s == e) {
			endStartLetter[s]++;
		} else {
			if (next_ch[s] != -1) {
				return false;
			}
			if (prev_ch[e] != -1) {
				return false;
			}
			next_ch[s] = e;
			prev_ch[e] = s;
		}
	}

	return true;
}

#define MMM 1000000007L

void getCnt()
{
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (prev_ch[i] == -1) {
			if (next_ch[i] != -1) {
				cnt++;
			} else if (endStartLetter[i] > 0) {
				cnt++;
			}
		}
	}
	long long val = 1L;
	for (int i = cnt; i > 1; i--) {
		val = val * (long long)i;
		val = val % MMM;
	}

	for (int i = 0; i < 26; i++) {
		int dd = endStartLetter[i];
		for (int j = dd; j > 1; j--) {
			val = val * (long long)j;
			val = val % MMM;
		}
	}

	printf("%lld\n", val);
}

void solve()
{
	for (int i = 0; i < N; i++) {
		if (!checkEachCar(i)) {
			printf("0\n");
			return;
		}
	}

	if (!checkMidLetter()) {
		printf("0\n");
		return;
	}

	if (!linkLetters()) {
		printf("0\n");
		return;
	}

	getCnt();
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s", &cars[j]);
			carlen[j] = strlen(cars[j]);
			start_ch[j] = cars[j][0] - 'a';
			end_ch[j] = cars[j][carlen[j]-1] - 'a';
		}

		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
