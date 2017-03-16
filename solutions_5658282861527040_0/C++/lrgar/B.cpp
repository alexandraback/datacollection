// ================================================================================================
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
_BEGIN_PROBLEM(_GCJ14_03B, "GCJ14 03B")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int main(
	) {
		int T, A, B, K;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			cin >> A >> B >> K;

			int answer = 0;
			for (int i = 0; i < A; ++i)
				for (int j = 0; j < B; ++j)
					if ((i & j) < K)
						++answer;

			cout << "Case #" << _T << ": " << answer << endl;
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
