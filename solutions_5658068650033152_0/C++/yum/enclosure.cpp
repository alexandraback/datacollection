#include <cstring>
#include <iostream>
using namespace std;

int bs,N,M,K;

bool getbit(int n, int m) {
	return bs & (1<<(n*M+m));
}

int dm[] = {0,0,-1,1}, dn[] = {-1,1,0,0};

bool fpvis[1<<20] = {0,};

bool findpath(int n, int m) {
	if (n < 0 || n >= N || m < 0 || m >= M) return false;

	int ckey = n*M+m;
	if (fpvis[ckey] == 1) return false;
	fpvis[ckey] = true;

	bool res = false;
	if (getbit(n, m)) res = false;
	else if (n == 0 || n == N-1 || m == 0 || m == M-1) res = true;
	else {
		for (int i = 0; i < 4; i++) {
			if (findpath(n+dn[i], m+dm[i])) res = true;
		}
	}
	fpvis[ckey] = false;
	return res;
}

bool enclosed() {
	int numenclosed = 0;
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			bool gb = getbit(n, m);
			if (gb || !findpath(n, m)) {
				numenclosed++;
				continue;
			}
		}
	}
	return numenclosed >= K;
}

int main() {
	int testcases;
	cin >> testcases;
	for (int tc = 1; tc <= testcases; tc++) {
		cin >> N >> M >> K;
		int max = (1<<(N*M)), minstones = 2000000000;
		for (bs = 0; bs < max; bs++) {
			if (enclosed()) minstones = min(minstones, __builtin_popcount(bs));
		}
		cout << "Case #" << tc << ": " << minstones << endl;
	}
}
