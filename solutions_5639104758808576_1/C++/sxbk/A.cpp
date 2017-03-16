#include <bits/stdc++.h>

using namespace std;

const int maxn = 10000;

int N;
int A[maxn];

bool test(int ans) {
	int cur = ans;
	for (int i = 0;i <= N;i ++) if (A[i]) {
		if (cur >= i) {
			cur += A[i];
		} else {
			return false ;
		}
	}
	return true ;
}

int main() {
	int T_T;
	scanf("%d", &T_T);
	for (int _ = 1;_ <= T_T;_ ++) {
		printf("Case #%d: ", _);
		scanf("%d", &N);
		getchar();
		for (int i = 0;i <= N;i++) {
			char c;
			scanf("%c", &c);
			A[i] = (int)(c - '0');
		}
		for (int i = 0;i <= N;i++) {
			if (test(i)) {
				printf("%d\n", i);
				break ;
			}
		}
	}
	return 0;
}
