/*
 * FB/win.cpp
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
const int MAXN = 105;
int graph[MAXN][MAXN];
int row[MAXN], col[MAXN];

void pretreat(int N, int M) {
	for(int i = 0; i < N; i++) {
		row[i] = 0;
		for(int j = 0; j < M; j++) {
			if(graph[i][j] > row[i]) {
				row[i] = graph[i][j];
			}
		}

//		row[i] = max_element(*graph[i], *graph[i] + M);
	}
	for(int j = 0; j < M; j++) {
		col[j] = 0;
		for(int i = 0; i < N; i++) {
			if(graph[i][j] > col[j]) {
				col[j] = graph[i][j];
			}
		}
	}
}

bool work() {
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	pretreat(N, M);
	bool ret = true;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(graph[i][j] < row[i] && graph[i][j] < col[j]) {
				ret = false;
				break;
			}
		}
		if(!ret) {
			break;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("data.in", "r", stdin);
	freopen("B-small-attempt0.in", "r", stdin);
	//	freopen("A-large.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: %s\n", t, work() ? "YES" : "NO");
	}
	return 0;
}
