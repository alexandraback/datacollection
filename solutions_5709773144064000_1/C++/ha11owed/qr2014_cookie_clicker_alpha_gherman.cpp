// -------------------------------------
// Gherman Alin
// Google code jam 2014
// Cookie Clicker Alpha
// https://code.google.com/codejam/contest/2974486/dashboard#s=p1
//
// IDE: VC++ 2010
// OS Windows 7
// -------------------------------------
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

template<typename T> void swap( T& a, T& b ) { T temp = a; a = b; b = temp; }

int cmpIntsAsc(const void * a, const void * b) { return ( *(int*)a - *(int*)b ); }
int cmpIntsDesc(const void * a, const void * b) { return ( *(int*)b - *(int*)a ); }

inline void qsortIntsAsc(int* values, size_t n) { qsort(values, n, sizeof(int), cmpIntsAsc); }
inline void qsortIntsDesc(int* values, size_t n) { qsort(values, n, sizeof(int), cmpIntsDesc); }

void solve();

int main(int argc, char** argv) {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	solve();

	return 0;
}

inline double timeWithoutFarm(double r, double x) {
	return x / r;
}

inline double timeWithFarm(double r, double c, double f, double x) {
	return (r*(x+c) + f*c) / (r * (r+f));
}

void solve() {
	int problemCount;
	double c, f, x;
	double r, t, tF, d;

	scanf("%d", &problemCount);
	for(int problemIdx = 1; problemIdx <= problemCount; problemIdx++) {
		scanf("%lf", &c);
		scanf("%lf", &f);
		scanf("%lf", &x);

		r = 2.0;
		d = 0;
		t = d + timeWithoutFarm(r, x);
		tF = d + timeWithFarm(r, c, f, x);
		if(t < tF) {
			printf("Case #%d: %lf\n", problemIdx, t);
		}
		else {
			// We should buy at least one farm.
			while(t > tF) {
				d += timeWithoutFarm(r, c);
				r += f;
				t = tF;
				tF = d + timeWithFarm(r, c, f, x);
			}
			printf("Case #%d: %lf\n", problemIdx, t);
		}
	}
}