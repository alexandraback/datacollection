/*
 * FA/win.cpp
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
char graph[4][4];

bool iswin(char c) {
	int n;
	for(int i = 0; i < 4; i++) {
		n = 0;
		for(int j = 0; j < 4; j++) {
			if(graph[i][j] == c || graph[i][j] == 'T') {
				n++;
			}
		}
		if(n == 4) {
			return true;
		}
	}
	for(int j = 0; j < 4; j++) {
		n = 0;
		for(int i = 0; i < 4; i++) {
			if(graph[i][j] == c || graph[i][j] == 'T') {
				n++;
			}
		}
		if(n == 4) {
			return true;
		}
	}
	n = 0;
	for(int i = 0; i < 4; i++) {
		if(graph[i][i] == c || graph[i][i] == 'T') {
			n++;
		}
	}
	if(n == 4) {
		return true;
	}
	n = 0;
	for(int i = 0; i < 4; i++) {
		if(graph[i][3 - i] == c || graph[i][3 - i] == 'T') {
			n++;
		}
	}
	return n == 4;
}

const char* work() {
	getchar();
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			graph[i][j] = getchar();
		}
		getchar();
	}
	if(iswin('X')) {
		return "X won";
	}
	if(iswin('O')) {
		return "O won";
	}
	int num = count(*graph, *graph + 16, '.');
	if(num == 0) {
		return "Draw";
	}
	return "Game has not completed";
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("data.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: %s\n", t, work());
	}
	return 0;
}
