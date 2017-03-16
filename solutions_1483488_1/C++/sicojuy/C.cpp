#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int A, B;
struct node {
	int contain[6];
	int n;
}nn[2000001];

bool check(char *s, int l, int k, int r, bool flag) {
	int i, j;
	for(i = l, j = k; i < k && j < r; ++i, ++j) {
		if(s[j] > s[i])
			return flag;
		if(s[j] < s[i])
			return !flag;
	}
	if(i == k && j == r)
		return false;
	if(i == k)
		return check(s, k, j, r, flag);
	if(j == r)
		return check(s, l, i, k, !flag);
}

int cal(int k) {
	char numstr[10];
	sprintf(numstr, "%d", k);
	int i, j;
	int len = strlen(numstr);
	int count = 0;
	int n;
	for(i = 1; i < len; ++i) {
		if(check(numstr, 0, i, len, true) == true) {
			n = 0;
			for(j = i; j < len; ++j) {
				n = n * 10 + numstr[j] - '0';
			}
			for(j = 0; j < i; ++j) {
				n = n * 10 + numstr[j] - '0';
			}
			if(n <= B) {
		//		printf("%d ", n);
				for(j = 0; j < nn[k].n; ++j)
					if(nn[k].contain[j] == n)
						break;
				if(j == nn[k].n) {
					++nn[k].n;
					nn[k].contain[j] = n;
					++count;
				}
			}
		}
	}
	return count;
}

int main() {
	freopen("Input.txt", "rt", stdin);
	freopen("Output.txt", "wt", stdout);

	int t;
	int i, j;
	int res;
	scanf("%d", &t);
	for(i = 1; i <= t; ++i) {
		scanf("%d%d", &A, &B);
		res = 0;
		for(j = A; j < B; ++j)
			nn[j].n = 0;
		for(j = A; j < B; ++j) {
	//		printf("%d ", j);
			res += cal(j);
	//		printf("\n");
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}