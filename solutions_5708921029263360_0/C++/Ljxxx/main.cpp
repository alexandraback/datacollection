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

int J, P, S, K;
int X[27][3], Y[27], cnt1[3][3], cnt2[3][3], cnt3[3][3], res, n, opt[27];

void input() {
	scanf("%d%d%d%d", &J, &P, &S, &K);
}

void search(int id, int sol) {
	if(id >= n) {
		if(sol > res) {
			res = sol;
			for(int i = 0;i < n;i ++) opt[i] = Y[i];
		}
		return ;
	}

	if(sol + n - id <= res) return ;

	if(cnt1[X[id][0]][X[id][1]] < K&&cnt2[X[id][0]][X[id][2]] < K&&cnt3[X[id][1]][X[id][2]] < K) {
		++ cnt1[X[id][0]][X[id][1]];
		++ cnt2[X[id][0]][X[id][2]];
		++ cnt3[X[id][1]][X[id][2]];
		Y[id] = 1;

		search(id+1, sol+1);

		Y[id] = 0;
		-- cnt1[X[id][0]][X[id][1]];
		-- cnt2[X[id][0]][X[id][2]];
		-- cnt3[X[id][1]][X[id][2]];
	}

	search(id+1, sol);
}

void solve() {
	n = 0;
	for(int i = 0;i < J;i ++) for(int j = 0;j < P;j ++) for(int k = 0;k < S;k ++) {
		X[n][0] = i;
		X[n][1] = j;
		X[n][2] = k;
		++ n;
	}

	for(int i = 0;i < 3;i ++) for(int j = 0;j < 3;j ++) cnt1[i][j] = cnt2[i][j] = cnt3[i][j] = 0;

	res = -1;
	search(0, 0);
	printf(" %d\n", res);
	for(int i = 0;i < n;i ++) if(opt[i]) {
		printf("%d %d %d\n", X[i][0]+1, X[i][1]+1, X[i][2]+1);
	}
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
