#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define CY 810

struct re {
	int d, fro, to, s;
}ar[CY];

int H[CY], tmp[CY];
int N, idx;

bool cmp(re u, re v) {
	return u.d < v.d;
}
void input(int n) {
	int di, ni, wi, ei, si, ddi, pi, ssi;
	idx = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &ddi, &pi, &ssi);
		for (int j = 0; j < ni; ++j) {
			ar[idx].d = di + j * ddi;
			ar[idx].fro = (wi + j * pi) * 2 + 400;
			ar[idx].to = (ei + j * pi) * 2 + 400;
			ar[idx].s = si + j * ssi;
			idx++;
		}
	}
	sort(ar, ar + idx, cmp);
}

void solve(int n) {
	memset(H, 0, sizeof(H));
	int pre = ar[0].d;
	int sum = 0;
	memcpy(tmp, H, sizeof(H));
	for (int i = 0; i < idx; ++i) {
		if (pre != ar[i].d) {
			memcpy(H, tmp, sizeof(H));
		}
		int fro = ar[i].fro;
		int to = ar[i].to;
		bool flag = false;
		for (int j = fro; j <= to; ++j) {
			tmp[j] = max(tmp[j], ar[i].s);
			if (H[j] < ar[i].s){
				flag = true;
			}
		}
		if (flag) sum++;
		pre = ar[i].d;
	}
	printf("%d\n", sum);
}

int main(void) {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int Cas = 1; Cas <= cas; ++Cas) {
		scanf("%d", &N);
		input(N);
		printf("Case #%d: ", Cas);
		solve(N);
	}
	return 0;
}
