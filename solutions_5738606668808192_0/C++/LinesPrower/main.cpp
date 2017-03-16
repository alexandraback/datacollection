#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
#define ALL(x) x.begin(), x.end()
#define LL long long
#define MP make_pair
#define PB push_back
#define CLR(a,b) memset(a, b, sizeof(a))
template<class T> inline T Sqr(const T &x) { return x*x; }
template<class T> inline T Abs(const T &x) { return x >= 0 ? x : -x; }
#define fo(i, n) for (int i = 0; i < (n); i++)
#define foz(i, a) for (int i = 0; i < (a).size(); i++)

void init()
{

}

typedef unsigned int uint;
typedef long long numt;

const int max_check = 200;

int n, cnt;
int proofs[11];

int check(numt x)
{
	for (int i = 2; i <= max_check; i++)
		if (x % i == 0)
			return i;
	return -1;
}

void solvecase()
{
	scanf("%d%d", &n, &cnt);
	printf("\n");
	int N = 1 << (n - 2);
	int found = 0;
	for (int i = 0; i < N; i++)
	{
		uint cur = 1 + (i << 1) + (1 << (n - 1));
		bool ok = true;
		for (int base = 2; base <= 10; base++)
		{
			numt x = 0, w = 1;
			for (int j = 0; j < n; j++)
			{
				if (cur & (1 << j)) x += w;
				w *= base;
			}
			int proof = check(x);
			if (proof == -1)
			{
				ok = false;
				break;
			}
			proofs[base] = proof;
		}
		if (ok)
		{
			for (int j = n-1; j >= 0; j--) printf("%d", cur & (1<<j) ? 1 : 0);
			for (int base = 2; base <= 10; base++) printf(" %d", proofs[base]);
			printf("\n");
			fflush(stdout);
			found++;
			if (found >= cnt) break;
		}
	}
}

void solve() {
	init();
	int n_tests;
	scanf("%d", &n_tests);
	for (int i = 1; i <= n_tests; i++)
	{
		printf("Case #%d: ", i);
		solvecase();
		printf("\n");
	}
}

#define problem_letter "C"
#define fname "test"
//#define fname problem_letter "-small-attempt0"
//#define fname problem_letter "-small-attempt1"
//#define fname problem_letter "-small-attempt2"
//#define fname problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}
