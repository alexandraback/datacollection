/*
 * FC/win.cpp
 * Created on: 2013-4-13
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
typedef long long LL;

bool ishws(int n) {
	char str[100];
	sprintf(str, "%d", n);
	int len = strlen(str);
	int t = len / 2, i;
	for(i = 0; i < t; i++) {
		if(str[i] != str[len - i - 1]) {
			break;
		}
	}
	return i == t;
}

void test1() {
	for(int i = 1; i <= 1000; i++) {
		int s = sqrt(i);
		if(s * s != i) {
			continue;
		}
		if(ishws(i) && ishws(s)) {
			printf("%d\n", i);
		}
	}
}

int small(int a) {
	const int N = 5;
	int array[N] = {1, 4, 9, 121, 484};
	int ret = 0;
	for(int i = 0; i < N; i++) {
		if(a >= array[i]) {
			ret++;
		}else {
			break;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("data.in", "r", stdin);
	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("data.in", "r", stdin);
#endif
	int T, a, b;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", t, small(b) - small(a - 1));
	}
	return 0;
}
