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

bool ishws(LL n) {
	char str[100];
	sprintf(str, "%lld", n);
	int len = strlen(str);
	int t = len / 2, i;
	for (i = 0; i < t; i++) {
		if (str[i] != str[len - i - 1]) {
			break;
		}
	}
	return i == t;
}

void test1() {
	for (int i = 1; i <= 1000; i++) {
		int s = sqrt(i);
		if (s * s != i) {
			continue;
		}
		if (ishws(i) && ishws(s)) {
			printf("%d\n", i);
		}
	}
}

void test2() {
	for (int i = 1; i <= 10000000; i++) {
		LL s = (LL) i * i;
		if (ishws(i) && ishws(s)) {
			printf("%lld, ", s);
		}
	}
//	for(LL i = 1; i <= N; i++) {
//		int s = sqrt(i);
//		if((LL)s * s != i) {
//			continue;
//		}
//		if(ishws(i) && ishws(s)) {
//			printf("%lld\n", i);
//		}
//	}
}

int medium(LL a) {
	const int N = 39;
	LL array[N] = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944,
			1002001, 1234321, 4008004, 100020001, 102030201, 104060401,
			121242121, 123454321, 125686521, 400080004, 404090404,
			10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL,
			40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL,
			1020304030201LL, 1022325232201LL, 1024348434201LL, 1210024200121LL,
			1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL,
			4000008000004LL, 4004009004004LL };
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (a >= array[i]) {
			ret++;
		} else {
			break;
		}
	}
	return ret;
}

int small(int a) {
	const int N = 5;
	int array[N] = { 1, 4, 9, 121, 484 };
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (a >= array[i]) {
			ret++;
		} else {
			break;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("data.in", "r", stdin);
//	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-large-1.in", "r", stdin);
//	freopen("data.in", "r", stdin);
#endif
	int T;
	LL a, b;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%lld%lld", &a, &b);
		printf("Case #%d: %d\n", t, medium(b) - medium(a - 1));
	}
	return 0;
}
