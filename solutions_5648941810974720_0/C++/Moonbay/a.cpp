/*
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
int data[26];
int ans[10];

int inline myindex(const char c) {
	return (int)(c - 'E');
}

void input() {
	memset(data, 0, sizeof(data));
	char str[2010];
	scanf(" %s", &str);
	for (int i = 0; str[i] != '\0'; i++) {
		data[myindex(str[i])]++;
	}
}

void inline deletechar(const char *str, int len, int n) {
	for (int i = 0; i < len; i++) {
		data[myindex(str[i])] -= n;
	}
}

void work() {
	//G->8
	ans[8] = data[myindex('G')];
	if (ans[8] > 0) {
		deletechar("EIGHT", 5, ans[8]);
	}
	//U->4
	ans[4] = data[myindex('U')];
	if (ans[4] > 0) {
		deletechar("FOUR", 4, ans[4]);
	}
	//W->2
	ans[2] = data[myindex('W')];
	if (ans[2] > 0) {
		deletechar("TWO", 3, ans[2]);
	}
	//X->6
	ans[6] = data[myindex('X')];
	if (ans[6] > 0) {
		deletechar("SIX", 3, ans[6]);
	}
	//Z->0
	ans[0] = data[myindex('Z')];
	if (ans[0] > 0) {
		deletechar("ZERO", 4, ans[0]);
	}

	//第二步
	//F->5
	ans[5] = data[myindex('F')];
	if (ans[5] > 0) {
		deletechar("FIVE", 4, ans[5]);
	}
	//H->3
	ans[3] = data[myindex('H')];
	if (ans[3] > 0) {
		deletechar("THREE", 5, ans[3]);
	}
	//S->7
	ans[7] = data[myindex('S')];
	if (ans[7] > 0) {
		deletechar("SEVEN", 5, ans[7]);
	}
	//O->1
	ans[1] = data[myindex('O')];
	if (ans[1] > 0) {
		deletechar("ONE", 3, ans[1]);
	}

	//第三步
	//N->9
	ans[9] = data[myindex('N')] / 2;
	if (ans[9] > 0) {
		deletechar("NINE", 4, ans[9]);
	}
}

void myprint() {
	for (int i = 0; i < 10; i++) {
		while (ans[i] > 0) {
			printf("%d", i);
			ans[i]--;
		}
	}
	putchar('\n');
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		input();
		printf("Case #%d: ", t);
		work();
		myprint();
	}
	return 0;
}


