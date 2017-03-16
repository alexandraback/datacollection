// I'm the Topcoder
//C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
//C++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

//*************************OUTPUT*************************
#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

//**************************CONSTANT***********************
#define INF 0x3f3f3f3f
#define eps 1e-8
#define PI acos(-1.)
#define PI2 asin (1.);
typedef long long LL;
//typedef __int64 LL;   //codeforces
typedef unsigned int ui;
typedef unsigned long long ui64;
#define MP make_pair
typedef vector<int> VI;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair

//***************************SENTENCE************************
#define CL(a,b) memset (a, b, sizeof (a))
#define sqr(a,b) sqrt ((double)(a)*(a) + (double)(b)*(b))
#define sqr3(a,b,c) sqrt((double)(a)*(a) + (double)(b)*(b) + (double)(c)*(c))

//****************************FUNCTION************************
template <typename T> double DIS(T va, T vb) { return sqr(va.x - vb.x, va.y - vb.y); }
template <class T> inline T INTEGER_LEN(T v) { int len = 1; while (v /= 10) ++len; return len; }
template <typename T> inline T square(T va, T vb) { return va * va + vb * vb; }

// aply for the memory of the stack
//#pragma comment (linker, "/STACK:1024000000,1024000000")
//end

#define CY 105

int ar[CY], rec[CY];
int A, N;

int main(void) {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for (int T = 1; T <= cas; ++T) {
		scanf("%d%d", &A, &N);
		for (int i = 1; i <= N; ++i) {
			scanf("%d", &ar[i]);
		}
		sort(ar + 1, ar + 1 + N);
		if (A == 1) {
			printf("Case #%d: %d\n", T, N);
			continue;
		}
		int sum = 0, res = 0;
		for (int i = 1; i <= N; ++i) {
			int t = 0;
			if (A <= ar[i]) {
				res++;
				A += A - 1;
				sum++;
				i--;
			} else {
				A += ar[i];
				rec[i] = res;
			}
		}
		int mn = N;
		for (int i = 1; i <= N; ++i) {
			mn = min(mn, rec[i] + N - i);
		}
		printf("Case #%d: %d\n", T, mn);
	}
	return 0;
}
