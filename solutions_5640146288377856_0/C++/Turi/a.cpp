#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int D[32][32];
int E[32][32][32][32];


//Misses in a row, given that it's hit at positions i and j, i <= j
int e(int C, int W, int i, int j){
	assert(j - i + 1 <= W);
	assert(i <= j);

	if (E[C][W][i][j] != -1)
		return E[C][W][i][j];

	if (C < W)
		return -1000000000;

	if (j - i + 1 == W)
		return 0;

	int best = 1000000000;

	for (int k = max(0, j - W + 1); k < i; k++)
		best = min(best, max(1 + e(C - k - 1, W, i - k - 1, j - k - 1), e(C, W, k, j)));
	for (int k = min(C-1, i + W - 1); k > j; k--)
		best = min(best, max(1 + e(k, W, i, j), e(C, W, i, k)));


	//cerr << C << " " << W << " " << i << " " << j << ": " << best << endl;
	return E[C][W][i][j] = best;
}

//Misses in a row, given that it's somewhere in that row
int d(int C, int W){
	if (D[C][W] != -1)
		return D[C][W];

	if (C < W)
		return -1000000000;
	if (C == W)
		return 0;

	int best = 1000000000;
	for (int i = 0; i < W; i++)
		best = min(
			best,
			max( e(C, W, i, i), 1 + d(C - i - 1, W))
		);

	//cerr << C << " " << W << ": " << best << endl;
	return D[C][W] = best;
}

int res(int R, int C, int W){
	if (R == 1)
		return d(C, W);
	return -1; //TODO
}

int main(){
    int T;
    cin >> T;

    for (int i = 0; i < 32; i++)
		for (int j = 0; j < 32; j++){
				D[i][j] = -1;
				for (int k = 0; k < 32; k++)
					for (int l = 0; l < 32; l++)
						E[i][j][k][l] = -1;
		}

    for (int t = 0; t < T; t++){
        int R, C, W;
        cin >> R >> C >> W;

        cout << "Case #" << t+1 << ": " << W + res(R, C, W) << endl;
    }
    return 0;
}
