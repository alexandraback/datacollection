#include<stdio.h>
#include<math.h>

bool isPalindrome(__int64 n);
__int64 nextPalindrome(__int64 n);

int main() {
	FILE* ifp = fopen("input.txt", "r");
	FILE* ofp = fopen("output.txt", "w");

	int c;
	int n = 0, count = 0;
	__int64 i, a, b;
	fscanf(ifp, "%d", &c);
	while(c--) {
		n++;
		fscanf(ifp, "%I64d %I64d", &a, &b);
		count = 0;
		i = 1;
		while(1) {
			if (i*i >= a) break;
			i++;
		}
		while(i*i <= b) {
			if (isPalindrome(i) && isPalindrome(i*i))
				count++;
			i = nextPalindrome(i);
		}
		fprintf(ofp, "Case #%d: %d\n", n, count);
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

bool isPalindrome(__int64 n) {
	if (n < 0) return 0;
	int a[15];
	int i = 0;
	int j = 0;
	a[i++] = n%10;
	while(n >= 10) {
		n /= 10;
		a[i++] = n%10;
	}
	bool really = 1;
	for (j=0; j<i/2; j++) {
		if (a[j] != a[i-j-1]) {really=0; break;}
	}
	return really;
}

__int64 nextPalindrome(__int64 n) {
	if (n < 0) return 0;
	if (n < 9) return n+1;
	if (n <= 10) return 11;
	__int64 k, t;
	int a[15];
	int i = 0;
	int j = 0;
	t = n;
	a[i++] = t%10;
	while(t >= 10) {
		t /= 10;
		a[i++] = t%10;
	}
	a[i] = 0;
	for (j=0; j<i/2; j++)
		a[j] = a[i-j-1];
	k = a[i-1];
	for (j=i-1; j>0; j--) {
		k *= 10;
		k += a[j-1];
	}
	if (k>n) return k;
	a[i/2]++;
	for (j=i/2; j<i; j++) {
		a[j+1] += a[j]/10;
		a[j] %= 10;
		a[i-j-1] = a[j];
	}
	if (a[i] == 1) {
		i++; a[0]++;
	}
	k = a[i-1];
	for (j=i-1; j>0; j--) {
		k *= 10;
		k += a[j-1];
	}
	return k;
}