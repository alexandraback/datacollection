#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long lint;

int multi[5][5], n, pre[200005], suf[200005];


char s[10005];
lint x;

inline int sign(int x) {
	if(x > 0) return 1;
	return -1;
}


bool check(int times) {
	int first = -1;
	pre[0] = s[0];
	if(pre[0] == 2) {
		first = 0;
	}

	for(int i = 1; i < times* n; i++) {
		pre[i] = sign(pre[i - 1]) * multi[abs(pre[i - 1])][s[i % n]];
		if(pre[i] == 2 && first == -1) {
			first = i;
		}
	}

	if(first == -1) return false;

	suf[n * times] = 1;
	for(int i = times * n - 1; i >= 1; i--) {
		suf[i] = sign(suf[i + 1]) * multi[s[i % n]][abs(suf[i + 1])];
		if(suf[i] == 4 && pre[i - 1] == 4 && first < i - 1) {
			return true;
		}
	}
	
	return false;
}

int main() {
	multi[1][1] = 1, multi[1][2] = 2, multi[1][3] = 3, multi[1][4] = 4;
	multi[2][1] = 2, multi[2][2] = -1, multi[2][3] = 4, multi[2][4] = -3;
	multi[3][1] = 3, multi[3][2] = -4, multi[3][3] = -1, multi[3][4] = 2;
	multi[4][1] = 4, multi[4][2] = 3, multi[4][3] = -2,	multi[4][4] = -1;

	int t;
	cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		cin >> n >> x;
		cin >> s;
		pre[0] = suf[n + 1] = 1;
		for(int i = 0; i < n; i++) {
			if(s[i] == 'i') s[i] = 2;
			if(s[i] == 'j') s[i] = 3;
			if(s[i] == 'k') s[i] = 4;
		}

		bool ans = false;
		if(x < 12) {
			ans = check(x);
		}
		else {
			int now = 1;
			for(int i = 0; i < n; i++) {
				now = sign(now) * multi[abs(now)][s[i]];
			}
			int circle;
			if(now == 1) circle = 1;
			else if(now == -1) circle = 2;
			else circle = 4;

			for(int i = 1; i < 12; i++) {
				bool tmp = check(i);
				if(tmp && (x - i) % circle == 0) {
					ans = true;
					break;
				}
			}
		}

		printf("Case #%d: %s\n", cas, ans ? "YES" : "NO");
	}
	return 0;
}
