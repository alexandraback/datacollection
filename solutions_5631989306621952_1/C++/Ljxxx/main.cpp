/*
 * main.cpp
 *
 *  Created on: 9 Apr 2016
 *      Author: ljchang
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

char buf[1024];
char opt[1024][1024];

void input() {
	scanf("%s", buf);
}

void mycopy(char *str, int len) {
	char tmp = buf[len];
	buf[len] = '\0';
	strcpy(str, buf);
	buf[len] = tmp;
}

void solve() {
	int n = strlen(buf);
	mycopy(opt[0], 1);
	for(int i = 1;i < n;i ++) {
		char max_ch = 0;
		opt[i][0] = '\0';
		char str[1024];
		for(int j = 0;j <= i;j ++) if(buf[j] > max_ch) max_ch = buf[j];
		for(int j = 0;j <= i;j ++) if(buf[j] == max_ch) {
			str[0] = buf[j];
			strcpy(str+1, opt[j-1]);
			strcpy(str+j+1, buf+j+1);
			if(strcmp(str, opt[i]) > 0) strcpy(opt[i], str);
		}
	}
	printf(" %s\n", opt[n-1]);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int cas = 0; cas < t;cas ++) {
		input();
		printf("Case #%d:", cas+1);
		solve();
	}
	return 0;
}
