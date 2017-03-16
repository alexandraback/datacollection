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
/*
 * 输入非负整数
 * 支持short、int、long、long long等类型(修改typec即可)。
 * 用法typec a = get_int();返回-1表示输入结束
 */
typedef int typec;
typec get_int() {
	typec res = 0, ch;
	while (!((ch = getchar()) >= '0' && ch <= '9')) {
		if (ch == EOF)
			return -1;
	}
	res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + (ch - '0');
	return res;
}
//输入整数(包括负整数，故不能通过返回值判断是否输入到EOF，本函数当输入到EOF时，返回-1)，用法int a = get_int2();
int get_int2() {
	int res = 0, ch, flag = 0;
	while (!((ch = getchar()) >= '0' && ch <= '9')) {
		if (ch == '-')
			flag = 1;
		if (ch == EOF)
			return -1;
	}
	res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + (ch - '0');
	if (flag == 1)
		res = -res;
	return res;
}
/**
 * 输入一个字符串到str中，与scanf("%s", str)类似，
 * 会忽略掉缓冲区中的空白字符。返回值为输入字符串
 * 的长度，返回-1表示输入结束。
 */
int get_str(char *str) {
	char c;
	while ((c = getchar()) <= ' ') {
		if(c == EOF) {
			return -1;
		}
	}
	int I = 0;
	while (c > ' ') {
		str[I++] = c; c = getchar();
	}
	str[I] = 0;
	return I;
}

int main() {
	int T = get_int();
	int r, c, w;
	for (int t = 1; t <= T; t++) {
		r = get_int();
		c = get_int();
		w = get_int();
		int ret = c / w * r + w - 1;
		if (c % w != 0) {
			ret++;
		}
		printf("Case #%d: %d\n", t, ret); 
	}
	return 0;
}


