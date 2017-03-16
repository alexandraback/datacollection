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

int B;
long long M;

void input() {
	scanf("%d%lld", &B, &M);
}

void solve() {
	long long pow2[60];
	pow2[0] = 1;
	for(int i = 1;i <= B-2;i ++) pow2[i] = pow2[i-1]*2;
	if(pow2[B-2] < M) {
		printf(" IMPOSSIBLE\n");
		return ;
	}
	printf(" POSSIBLE\n");
	if(M == pow2[B-2]) {
		for(int i = 0;i < B;i ++) {
			for(int j = 0;j < B;j ++) {
				if(i < j) printf("1");
				else printf("0");
			}
			printf("\n");
		}
		return ;
	}
	int matrix[50][50];
	for(int i = 0;i < B;i ++) for(int j = 0;j < B;j ++) matrix[i][j] = 0;
	for(int i = 1;i < B;i ++) for(int j = i+1;j < B;j ++) matrix[i][j] = 1;
	int x = B-2;
	while(M > 0) {
		if(M%2 == 1) matrix[0][x] = 1;
		-- x;
		M /= 2;
	}
	for(int i = 0;i < B;i ++) {
				for(int j = 0;j < B;j ++) {
					printf("%d", matrix[i][j]);
				}
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
