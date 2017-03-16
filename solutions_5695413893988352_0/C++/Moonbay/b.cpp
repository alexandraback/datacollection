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
char stra[30], strb[30];
int ansa, ansb, mindiff;

bool issuit(const char* strnum, int n) {
	int len = strlen(strnum);
	char str1[30], str2[30];
	strcpy(str1, strnum);
	reverse(str1, str1 + len);
	sprintf(str2, "%04d", n);
	reverse(str2, str2 + strlen(str2));
	for (int i = 0; i < len; i++) {
		if (str1[i] == str2[i]) {
			continue;
		}
		if (str1[i] == '?') {
			continue;
		}
		return false;
	}
	return true;
}

void work(const int MAX) {
	mindiff = 100000;
	for (int a = 0; a < MAX; a++) {
		if (!issuit(stra, a)) {
			continue;
		}
		for (int b = 0; b < MAX; b++) {
			if (!issuit(strb, b)) {
				continue;
			}
			if (abs(a - b) < mindiff) {
				mindiff = abs(a - b);
				ansa = a;
				ansb = b;
			} else if(abs(a - b) == mindiff) {
				if (a < ansa) {
					ansa = a;
					ansb = b;
				} else if (a == ansa) {
					if (b < ansb) {
						ansb = b;
					}
				}
			}
		}
	}
}

void display(int n, int len) {
	char str[50];
	sprintf(str, "%04d", n);
	reverse(str, str + strlen(str));
	str[len] = 0;
	reverse(str, str + strlen(str));
	printf("%s", str);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %s %s", stra, strb);
		int len = strlen(stra);
		work(pow(10, len));
		printf("Case #%d: ", t);
		display(ansa, len);
		putchar(' ');
		display(ansb, len);
		putchar('\n');
	}
	return 0;
}


