// ================================================================================================
//  D - Deceitful War.cpp
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
_BEGIN_PROBLEM(_GCJ14_01D, "GCJ14 01D")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main(
	) {
		static const double EPS = 1.e-6;

		int T, N;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			cin >> N;

			int bestInWar = 0, bestInDeceitfulWar = 0;
			
			double naomiBlocks[1000], kenBlocks[1000];
			for (int i = 0; i < N; ++i) cin >> naomiBlocks[i];
			for (int i = 0; i < N; ++i) cin >> kenBlocks[i];

			sort(naomiBlocks, naomiBlocks + N);
			sort(kenBlocks, kenBlocks + N);

			for (int i = 0; i < N; ++i) {
				int deceitfulWarPoints = 0;
				for (int j = 0; j < N - i; ++j)
					if (naomiBlocks[i + j] > kenBlocks[j])
						++deceitfulWarPoints;
				bestInDeceitfulWar = max(bestInDeceitfulWar, deceitfulWarPoints);
			}

			{
				set<double> kenBlocksSet(kenBlocks, kenBlocks + N);
				reverse(naomiBlocks, naomiBlocks + N);

				int warPoints = 0;
				for (int i = 0; i < N; ++i) {
					auto kenChosen = kenBlocksSet.upper_bound(naomiBlocks[i]);
					if (kenChosen == kenBlocksSet.end())
						++warPoints;
					else
						kenBlocksSet.erase(kenChosen);
				}

				bestInWar = max(bestInWar, warPoints);
			}

			cout << "Case #" << _T << ": " << bestInDeceitfulWar << " " << bestInWar << endl;
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
