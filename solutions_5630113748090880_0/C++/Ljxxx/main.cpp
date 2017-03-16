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

int num[100][50];
int matrix[50][50];
int candidate[50][2];
int n, found;

void input() {
	scanf("%d", &n);
	for(int i = 0;i < 2*n-1;i ++) {
		for(int j = 0;j < n;j ++) scanf("%d", num[i]+j);
	}
}

void search(int k) {
	if(k == n) {
		found = 1;
		return ;
	}

	int id1 = candidate[k][0], id2 = candidate[k][1];
	int ok = 1;
	for(int i = 0;i < k;i ++) {
		if(matrix[k][i] != -1&&matrix[k][i] != num[id1][i]) ok = 0;
		if(id2 != -1&&matrix[i][k] != -1&&matrix[i][k] != num[id2][i]) ok = 0;
	}

	if(ok) {
		int tmp[50][50];
		for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) tmp[i][j] = matrix[i][j];

		for(int i = 0;i < n;i ++) {
			matrix[k][i] = num[id1][i];
			if(id2 != -1) matrix[i][k] = num[id2][i];
		}

		search(k+1);

		if(found) return ;
		for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) matrix[i][j] = tmp[i][j];
	}

	ok = 1;
		for(int i = 0;i < k;i ++) {
			if(id2 != -1&&matrix[k][i] != -1&&matrix[k][i] != num[id2][i]) ok = 0;
			if(matrix[i][k] != -1&&matrix[i][k] != num[id1][i]) ok = 0;
		}

		if(ok) {
			int tmp[50][50];
			for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) tmp[i][j] = matrix[i][j];

			for(int i = 0;i < n;i ++) {
				if(id2 != -1) matrix[k][i] = num[id2][i];
				matrix[i][k] = num[id1][i];
			}

			search(k+1);

			if(found) return ;
			for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) matrix[i][j] = tmp[i][j];
		}
}

void solve() {
	char used[100];
	memset(used, 0, sizeof(char)*100);

	int missed_id = -1;
	for(int i = 0;i < n;i ++) {
		int min_val = 100000000;
		for(int j = 0;j < 2*n-1;j ++) if(!used[j]&&num[j][i] < min_val) min_val = num[j][i];
		int cnt = 0;
		candidate[i][0] = candidate[i][1] = -1;
		for(int j = 0;j < 2*n-1;j ++) if(!used[j]&&num[j][i] == min_val) {
			used[j] = 1;
			candidate[i][cnt ++] = j;
		}
		if(cnt == 1) missed_id = i;
	}

	found = 0;
	for(int i = 0;i < n;i ++) for(int j = 0;j < n;j ++) matrix[i][j] = -1;
	search(0);

	int res[2][50];
	for(int i = 0;i < n;i ++) {
		res[0][i] = matrix[missed_id][i];
		res[1][i] = matrix[i][missed_id];
	}

	int same = 1;
	for(int i = 0;i < n;i ++) if(res[0][i] != num[candidate[missed_id][0]][i]) same = 0;
	if(same) {
		for(int i = 0;i < n;i ++) printf(" %d", res[1][i]);
		printf("\n");
	}
	else {
		for(int i = 0;i < n;i ++) printf(" %d", res[0][i]);
		printf("\n");
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
