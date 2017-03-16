#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1004;
const int maxm = 104;

int vis[maxn], num[maxm];
int num_len;

int is_palindromes (int n) {
	num_len = 0;
	while (n) {
		num[num_len ++] = n % 10;
		n /= 10;
	}
	/*
	reserve (num, num + num_len);
	*/
	for (int i = 0; i < num_len; i ++) {
		if (num[i] != num[num_len - i - 1]) {
			return 0;
		}
	}
	return 1;
}

void init () {
	memset (vis, 0, sizeof (vis));
	for (int i = 1; i * i < maxn; i ++) {
		if (is_palindromes (i) && is_palindromes (i * i)) {
			vis[i * i] = 1;
		}
	}
	vis[0] = 0;
	for (int i = 1; i < maxn; i ++) {
		vis[i] += vis[i - 1];
	}
}

int main(int argc, char *argv[]) {
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	init ();
	for (int t = 1; t <= cas; t ++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		printf ("Case #%d: %d\n", t, vis[b] - vis[a - 1]);
	}
	return 0;
}
