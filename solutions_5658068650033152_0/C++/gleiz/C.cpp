#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct node {
	int x;
	int y;
}node, *NODE;

int cntBit(int mask) {
	int res = 0;
	while (mask) {
		if (mask & 1) {
			res++;
		}
		mask = (mask >> 1);
	}

	return res;
}

inline int getBit(int M, int x, int y) {
	return 1 << (x * M + y);
}


node dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void printvisit(int visit, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int currBit = getBit(M, i, j);
			if (visit & currBit) {
				cerr << "x ";
			} else {
				cerr << "o ";
			}
		}
		cerr << endl;
	}
}

int getCover(int N, int M, int mask) {
	int visit = 0;
	node Q[1024] = {0};
	int head = 0, tail = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!(i == 0 || j == 0 || i == N - 1 || j == M - 1)) {
				continue;
			}
			
			int currBit = getBit(M, i, j);
			if ((!(visit & currBit)) &&
				((mask & currBit) == 0)) {
				Q[tail].x = i;
				Q[tail].y = j;
				tail++;

				visit = visit | currBit;
			}
		}
	}
	/*
	if (mask == 555) {
		printvisit(mask, N, M);

		cerr << endl;
		printvisit(visit, N, M);
		cerr << endl;
	}
	*/
	
	while (head < tail) {
		int currBit = getBit(M, Q[head].x, Q[head].y);
		if ((mask & currBit) == 0) {
			for (int i = 0; i < 4; i++) {
				int nx = Q[head].x + dir[i].x;
				int ny = Q[head].y + dir[i].y;

				if (nx >= 0 && nx < N && ny >= 0 && ny < M){
					int nextBit = getBit(M, nx, ny);
					if ((visit & nextBit) == 0 && (mask & nextBit) == 0) {
						Q[tail].x = nx;
						Q[tail].y = ny;
						tail++;
						visit = visit | nextBit;
					}
				}
			}
		}

		head++;
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int currBit = getBit(M, i, j);
			if ((visit & currBit) == 0 || (mask & currBit) == 1) {
				res++;
			}
		}
	}
	/*
	if (mask == 555) {
		printvisit(visit, N, M);
		}*/

	return res;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small.out", "w+", stdout);
	
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N = 0, M = 0, K = 0;
		cin >> N >> M >> K;

		int B = N * M;
		int bound = (1 << B);

		int res = K;
		int bestMask = 0;
		for (int mask = 0; mask < bound; mask++) {
			int cover = getCover(N, M, mask);
			if (cover >= K) {
				if (cntBit(mask) < res) {
					res = cntBit(mask);
					bestMask = mask;
				}
			}
		}

		cout << "Case #" << cas << ": " << res << endl;
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int currBit = getBit(M, i, j);
				if (bestMask & currBit) {
					cerr << "x ";
				} else {
					cerr << "o ";
				}
			}

			cerr << endl;
		}

		cerr << bestMask << endl;
		*/
	}
    return 0;
}
