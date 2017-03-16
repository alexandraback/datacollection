#include <cstdio>
#include <cstring>
#include <utility>

using std::scanf;
using std::printf;
using std::memset;

static bool impossible(int t, int R, int C, int M) {
	printf("Case #%d:\nImpossible\n", t);
	return true;
}

/*

c*******
********
********
********

*/
static bool special_case_F1(int t, int R, int C, int M) {
	int F = R * C - M;
	if(F != 1)
		return false;
	printf("Case #%d:\n", t);
	putchar('c');
	for(int j = 1; j < C; ++j)
		putchar('*');
	putchar('\n');
	for(int i = 1; i < R; ++i) {
		for(int j = 0; j < C; ++j)
			putchar('*');
		putchar('\n');
	}
	return true;
}

/*

c.******

*/
static bool special_case_R1(int t, int R, int C, int M) {
	if(R != 1)
		return false;
	int F = R * C - M;
	printf("Case #%d:\n", t);
	putchar('c');
	for(int j = 1; j < F; ++j)
		putchar('.');
	for(int j = 0; j < M; ++j)
		putchar('*');
	putchar('\n');
	return true;
}

/*

c
.
*
*

*/
static bool special_case_C1(int t, int R, int C, int M) {
	if(C != 1)
		return false;
	int F = R * C - M;
	printf("Case #%d:\n", t);
	putchar('c');
	putchar('\n');
	for(int i = 1; i < F; ++i) {
		putchar('.');
		putchar('\n');
	}
	for(int i = 0; i < M; ++i) {
		putchar('*');
		putchar('\n');
	}
	return true;
}

/*

c.******
..******

*/
static bool special_case_R2(int t, int R, int C, int M) {
	if(R != 2)
		return false;
	int F = R * C - M;
	if(F < 4 || F % 2)
		return impossible(t, R, C, M);
	printf("Case #%d:\n", t);
	putchar('c');
	for(int j = 1; j < F / 2 + F % 2; ++j)
		putchar('.');
	for(int j = 0; j < M / 2; ++j)
		putchar('*');
	putchar('\n');
	for(int j = 0; j < F / 2; ++j)
		putchar('.');
	for(int j = 0; j < M / 2 + M % 2; ++j)
		putchar('*');
	putchar('\n');
	return true;
}

/*

c.
..
**
**

*/
static bool special_case_C2(int t, int R, int C, int M) {
	if(C != 2)
		return false;
	int F = R * C - M;
	if(F < 4 || F % 2)
		return impossible(t, R, C, M);
	printf("Case #%d:\n", t);
	putchar('c');
	putchar('.');
	putchar('\n');
	for(int i = 1; i < F / 2; ++i) {
		putchar('.');
		putchar('.');
		putchar('\n');
	}
	for(int i = 0; i < M / 2; ++i) {
		putchar('*');
		putchar('*');
		putchar('\n');
	}
	return true;
}

/*

c.******
..******
********
********

*/
static bool general_case(int t, int R, int C, int M) {
	int F = R * C - M;
	if(F < 4)
		return impossible(t, R, C, M);
	char *f = new char[R * C + 1];
	memset(f, '.', R * C);
	f[0] = 'c';
	f[R * C] = '\0';
	int r = R;
	int c = C;
	while(M >= r || M >= c) {
		while(r >= c && M >= c) {
			for(int j = 0; j < c; ++j)
				f[C * (r - 1) + j] = '*';
			M -= c;
			--r;
		}
		while(c >= r && M >= r) {
			for(int i = 0; i < r; ++i)
				f[C * i + c - 1] = '*';
			M -= r;
			--c;
		}
	}
	if(M == 0) {
		// great
	} else if(M < r - 1 && c > 2) {
		for(int i = r - M; i < r; ++i)
			f[C * i + c - 1] = '*';
	} else if(M < c - 1 && r > 2) {
		for(int j = c - M; j < c; ++j)
			f[C * (r - 1) + j] = '*';
	} else if(M == r - 1 && c > 3) {
		for(int i = r - M + 1; i < r; ++i)
			f[C * i + c - 1] = '*';
		f[C * (r - 1) + c - 2] = '*';
	} else if(M == c - 1 && r > 3) {
		for(int j = c - M + 1; j < c; ++j)
			f[C * (r - 1) + j] = '*';
		f[C * (r - 2) + c - 1] = '*';
	} else {
		delete [] f;
		return false;
	}
	printf("Case #%d:\n", t);
	for(int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j)
			putchar(f[i * C + j]);
		putchar('\n');
	}
	delete [] f;
	return true;
}

static void testcase(int t) {
	int R, C, M;
	scanf("%i%i%i", &R, &C, &M);
	special_case_F1(t, R, C, M)
		|| special_case_R1(t, R, C, M)
		|| special_case_C1(t, R, C, M)
		|| special_case_R2(t, R, C, M)
		|| special_case_C2(t, R, C, M)
		|| general_case(t, R, C, M)
		|| impossible(t, R, C, M);
}

int main() {
	int T;
	scanf("%i", &T);
	for(int t = 1; t <= T; ++t)
		testcase(t);
}
