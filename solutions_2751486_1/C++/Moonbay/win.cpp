/*
 * C2/win.cpp
 * Created on: 2013-5-12
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
const int MAXL = 1000010;
typedef long long LL;
char st[MAXL];
int data[MAXL];
int len, n;
const char vowel[] = "aeiou";

bool judge(char a) {
	for (int i = 0; i < 5; i++) {
		if (a == vowel[i]) {
			return false;
		}
	}
	return true;
}

LL work() {
	len = strlen(st);
	if (n > len) {
		return 0;
	}
	int temp = -1;
	data[0] = judge(st[0]);
	int i = 1;
	while (i < len && data[i - 1] < n) {
		if (judge(st[i])) {
			data[i] = data[i - 1] + 1;
		}
		else {
			data[i] = 0;
		}
		i++;
	}
	if (data[i - 1] < n) {
		return 0;
	}
	temp = i - n;
	LL ret = temp + 1;
	for (; i < len; i++) {
		if (judge(st[i])) {
			data[i] = data[i - 1] + 1;
		} else {
			data[i] = 0;
		}
		if (data[i] >= n) {
			temp = i - n + 1;
		}
		ret += temp + 1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("data.in", "r", stdin);
//	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%s%d", st, &n);
		printf("Case #%d: %lld\n", t, work());
	}
	return 0;
}
