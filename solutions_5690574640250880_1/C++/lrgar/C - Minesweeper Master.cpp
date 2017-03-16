// ================================================================================================
//  C - Minesweeper Master.cpp
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
#include <functional>
#include <cassert>

using namespace std;

#if defined _OJ_PROJECT
_BEGIN_PROBLEM(_GCJ14_01C, "GCJ14 01C")
#endif // _OJ_PROJECT

#define infinite_loop for (;;)

int dp1[51][2501][50], dp2[51][2501][50], len1[51][2501], len2[51][2501];
bool valid1[51][2501], valid2[51][2501];

int main(
	) {
		valid1[1][0] = true;
		for (int i = 2; i <= 50; ++i) {
			valid1[i][0] = true;
			for (int j = 1; j <= 50 * i; ++j) {
				int bestLength = 0x7fffffff;

				function<void ()> bestCallback;
				for (int y = 2; y <= i; ++y)
					if (y <= j && valid1[y][j - y]) {
						bestCallback = [i, j, y] {
							dp1[i][j][0] = y;
							copy(dp1[y][j - y], dp1[y][j - y] + len1[y][j - y], dp1[i][j] + 1);
						};
						bestLength = 1 + len1[y][j - y];
					}

				if (bestLength <= 50) {
					len1[i][j] = bestLength;
					valid1[i][j] = true;
					bestCallback();
				}
			}
		}

		for (int i = 2; i <= 50; ++i)
			for (int j = 1; j <= 50 * i; ++j) {
				int bestLength = 0x7fffffff;

				function<void ()> bestCallback;
				for (int x = 2; x <= j; ++x)
					for (int y = 2; y <= i; ++y) {
						if (valid1[y - 1][j - x * y] && x + len1[y - 1][j - x * y] < bestLength) {
							bestCallback = [i, j, x, y] {
								for (int z = 0; z < x; ++z) dp2[i][j][z] = y;
								for (int z = 0; z < len1[y - 1][j - x * y]; ++z) dp2[i][j][z + x] = dp1[y - 1][j - x * y][z];
							};
							bestLength = x + len1[y - 1][j - x * y];
						}
					}

				if (bestLength <= 50) {
					len2[i][j] = bestLength;
					valid2[i][j] = true;
					bestCallback();
				}
			}

		int T, R, C, M;
		cin >> T;

		for (int _T = 1; _T <= T; ++_T) {
			cin >> R >> C >> M;

			cout << "Case #" << _T << ":" << endl;

			vector<string> output;
			if (R == 1) {
				output = vector<string>{"c" + string(C - M - 1, '.') + string(M, '*')};
			} else if (C == 1) {
				output.push_back("c");
				for (int i = 0; i < R - M - 1; ++i) output.push_back(".");
				for (int i = 0; i < M; ++i) output.push_back("*");
			} else if (R * C - M == 1) {
				output = vector<string>(R, string(C, '*'));
				output[0][0] = 'c';
			} else if (!valid2[min(R, C)][R * C - M] || len2[min(R, C)][R * C - M] > max(R, C)) {
				cout << "Impossible" << endl;
				continue;
			} else if (R <= C) {
				output = vector<string>(R, string(C, '*'));
				for (int j = 0; j < len2[R][R * C - M]; ++j)
					for (int i = 0; i < dp2[R][R * C - M][j]; ++i)
						output[i][j] = '.';
				output[0][0] = 'c';
			} else if (C < R) {
				output = vector<string>(R, string(C, '*'));
				for (int i = 0; i < len2[C][R * C - M]; ++i)
					for (int j = 0; j < dp2[C][R * C - M][i]; ++j)
						output[i][j] = '.';
				output[0][0] = 'c';
			}

			for (auto s : output) cout << s << endl;
		}

		return 0;
	}

#if defined _OJ_PROJECT
_END_PROBLEM
#endif // _OJ_PROJECT

// ================================================================================================
//  End of file.
// ================================================================================================
