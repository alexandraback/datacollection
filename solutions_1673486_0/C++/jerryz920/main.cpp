
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <functional>
#include <math.h>

using namespace::std;

template <class T>
static inline T check_max(T& dst, T src) { if (dst < src) dst = src; return dst; }

template <class T>
static inline T check_min(T& dst, T src) { if (dst > src) dst = src; return dst; }
double p[1000000];
double solve()
{
	 int A, B;
	scanf("%d%d", &A, &B);
	for (int i =0 ;i < A; i++) {
	  scanf("%lf", &p[i]);
	}

	double p1 = 1;
	for (int i = 0; i < A; i++) {
	  p1 *= p[i];
	}

	int redo_count = B+1;
	double e1 = p1 * ( redo_count - A) + (1-p1) * (2*redo_count - A);

	double p2 = 1;
	double e2 = B+2;
	for (int i =1 ;i <= A; i++) {
		p2 *= p[i - 1];
		check_min(e2, p2 * (redo_count - A + 2*(A-i)) + (1-p2) *(2*redo_count - A + 2*(A-i)));
	}
	check_min(e1, e2);
	check_min(e1, (double) (B + 2));
	return e1;

}


int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		printf("%.6f", solve());
		printf("\n");
	}
	return 0;
}