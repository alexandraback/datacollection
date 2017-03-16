#include <stdio.h>

int hit[10], last;

int inline getProduct(int n) {
	if (n < 10) return 10;
	else if (n < 100) return 100;
	else if (n < 1000) return 1000;
	else if (n < 10000) return 10000;
	else if (n < 100000) return 100000;
	else if (n < 1000000) return 1000000;
	else if (n < 10000000) return 10000000;
}

int recycle(int n, int B) {
	int product = getProduct(n);
	int modder, tail, newN, i;
	int ans = 0;
	last = 0;
	for (modder = 10; modder < product; modder *= 10) {
		tail = n % modder;
		//if (getProduct(tail) != modder) continue;
		newN = tail * (product / modder) + n / modder;
		if (n < newN && newN <= B){
			for (i = 0; i < last; ++i) {
				if (newN == hit[i]) break;
			}
			if (i < last) continue;
			hit[last++] = newN;
			++ans;
			//printf("%d\t%d\n", n, newN);
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("E:\\test\\codejam\\C-small-attempt0.in", "r", stdin);
	freopen("E:\\test\\codejam\\test.out", "w", stdout);
#endif

	int caseno, i, T, count = 0, A, B;
	scanf("%d", &T);
	getchar();
	for (caseno = 1; caseno <= T; ++caseno) {
		scanf("%d%d", &A, &B);
		count = 0;
		for (i = A; i < B; ++i) {
			count += recycle(i, B);
		}
		printf("Case #%d: %d\n", caseno, count);
	}
	return 0;
}