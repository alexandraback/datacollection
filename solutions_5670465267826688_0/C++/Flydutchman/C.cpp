#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

long long getLL() {
	long long ret = 0;
	char c;
	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') break ;
	}
	while (1) {
		ret = ret * 10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') break ;
	}
	return ret;
}

int getInt() {
	int ret = 0;
	char c;
	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') break ;
	}
	while (1) {
		ret = ret * 10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') break ;
	}
	return ret;
}

int go(int x, int y) {
	if (x < 0) return -go(-x, y);
	if (y < 0) return -go(x, -y);
	if (x == 1) return y;
	if (y == 1) return x;
	if (x == y) return -1;
	if (x > y) return -go(y, x);
	if (x == 2 && y == 3) return 4;
	if (x == 2 && y == 4) return -3;
	if (x == 3 && y == 4) return 2;
}

int check(char c) {
	if (c == '1') return 1;
	if (c == 'i') return 2;
	if (c == 'j') return 3;
	if (c == 'k') return 4;
}

int pw_all[5];
int A[MaxN], l[MaxN], r[MaxN];
char buf[MaxN];
int B[MaxN];
int n, k;
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int T; cin >> T;
	for (int TK = 1; TK <= T; ++TK) {
		scanf("%d%d", &n, &k);
		printf("Case #%d: ", TK);
		scanf("%s", buf);
		for (int i = 1; i <= n; ++i) A[i] = check(buf[i - 1]);

		//BRUTE
		for (int i = 0; i < k; ++i) for (int j = 1; j <= n; ++j) B[i * n + j] = A[j];
		int len = n * k;
		l[0] = 1;
		bool ans = false ;
		for (int i = 1; i <= len; ++i) l[i] = go(l[i - 1], A[(i - 1) % n + 1]);
		for (int i = 1; i <= len; ++i) if (l[i] == 2) {
			for (int j = i + 2; j <= len; ++j) if (go(l[j - 1], l[len]) == -4 && go(l[i], l[j - 1]) == -3) ans = true;
		}
		if (ans) puts("YES"); else puts("NO");
/*
		l[0] = r[3 * n + 1] = 1;
		bool ans = false ;
		for (int i = 1; i <= 3 * n; ++i) l[i] = go(l[i - 1], A[(i - 1) % n + 1]);
		for (int i = 3 * n; i > 0; --i) r[i] = go(A[(i - 1) % n + 1], r[i + 1]);
		pw_all[0] = 1; for (int i = 1; i < 4; ++i) pw_all[i] = go(pw_all[i - 1], l[n]);
		for (int i = 1; i <= 3 * n; ++i) if (l[i] == 2) {
			for (int j = 1; j <= 3 * n; ++j) if (r[j] == 4) {
				int x = ((i - 1) / n) + (3 * n - j) / n;
				int lc = (i - 1) % n + 1, rc = (j - 1) % n + 1;
				if (lc + 1 < rc && go(l[lc], l[rc - 1]) == -3 && k >= (x + 1) && (k - x - 1) % 4 == 0) ans = true;
				if (k >= (x + 2) && go(go(r[2 * n + lc + 1], pw_all[(k - x - 2) % 4]), l[rc - 1]) == 3) ans = true;
			}
		}
		if (ans) puts("YES"); else puts("NO");
*/
	}
	return 0;
}


