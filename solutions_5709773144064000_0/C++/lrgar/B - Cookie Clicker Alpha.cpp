// ================================================================================================
//  B - Cookie Clicker Alpha.cpp
//  Written by Luis Garcia, 2014
// ================================================================================================

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <numeric>
#include <iostream>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ14_01B, "GCJ14 01B")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main(
	) {
		int T;
		double C, F, X;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			cin >> C >> F >> X;

			double s = 2., best = X / s, t = 0.;
			for (int i = 0; i < 100000; ++i)
				t += C / s, s += F, best = min(best, t + X / s);

			printf("Case #%d: %.7lf\n", _T, best);
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
