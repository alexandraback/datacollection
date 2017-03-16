#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 501024;

LL L;
int A[maxn];

int tb[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

int sgn(int x) {
	if (x > 0) return 1;
	return -1;
}

int multi(int x, int y) {
	return sgn(x) * sgn(y) * tb[abs(x) - 1][abs(y) - 1];
}

bool chk(int n, int len) {
	for (int i = n;i < len * n;i++) {
		A[i] = A[i - n];
	}
	n *= len;
	int sum = 1;
	for (int i = 0;i < n;i++) {
		sum = multi(sum, A[i]);
	}
	if (sum != multi(multi(2, 3), 4)) {
		return false ;
	}
	sum = 1;
	int lf = -1;
	for (int i = 0;i < n;i++) {
		sum = multi(sum, A[i]);
		if (sum == 2) {
			lf = i;
			break ;
		}
	}
	sum = 1;
	int rt = -1;
	for (int i = n - 1;i >= 0;i--) {
		sum = multi(A[i], sum);
		if (sum == 4) {
			rt = i;
			break ;
		}
	}
	if (lf != -1 && rt != -1 && lf < rt) {
	//	cout << len << " " << lf << " " << rt << endl;
		return true ;
	}
	return false ;
}

int N;

int main() {
	int T_T;
	scanf("%d", &T_T);
	for (int _ = 1;_ <= T_T;_ ++) {
		printf("Case #%d: ", _);
		scanf("%d %lld", &N, &L);
		getchar();
		for (int i = 0;i < N;i++) {
			char c;
			scanf("%c", &c);
			A[i] = (int) (c - 'i') + 2;
		} /*
		for (int len = 1;len <= min(50LL, L);len ++) {
			if ((len * N) % 4 == (L * (LL)N) % 4LL) {
				if (chk(N, len)) {
					puts("YES");
					goto NEXT;
				}
			}
		}
		puts("NO");
NEXT:	; */
		if (chk(N, L)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
