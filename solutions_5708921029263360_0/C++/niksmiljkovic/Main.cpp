#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MAXS = 10;
const int MAXK = 10;

int read() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int j, p, s, k;

int cnt;
int gen[MAXS*MAXS*MAXS][3];
bool taken[MAXS*MAXS*MAXS];

int solCnt;
bool sol[MAXS*MAXS*MAXS];

int cntJP[MAXS][MAXS];
int cntJS[MAXS][MAXS];
int cntPS[MAXS][MAXS];

void reset() {
	j = p = s = k = 0;
	memset(gen, 0, sizeof(gen));
	memset(cntJP, 0, sizeof(cntJP));
	memset(cntJS, 0, sizeof(cntJS));
	memset(cntPS, 0, sizeof(cntPS));

	memset(taken, 0, sizeof(taken));

	solCnt = 0;
	memset(sol, 0, sizeof(sol));
}

void readInput() {
	j = read();
	p = read();
	s = read();
	k = read();
}

void check(int n, int takenCnt) {
	if (takenCnt > solCnt) {
		solCnt = takenCnt;
		for (int i = 0; i < n; i++) sol[i] = taken[i];
	}
}

void list(int i, int n, int takenCnt) {
	if (i == n) {
		check(n, takenCnt);
	}
	else {
		taken[i] = false;
		list(i + 1, n, takenCnt);

		if (cntJP[gen[i][0]][gen[i][1]] < k 
			&& cntJS[gen[i][0]][gen[i][2]] < k 
			&& cntPS[gen[i][1]][gen[i][2]] < k) {
			
			
			taken[i] = true;

			cntJP[gen[i][0]][gen[i][1]]++;
			cntJS[gen[i][0]][gen[i][2]]++;
			cntPS[gen[i][1]][gen[i][2]]++;
			list(i + 1, n, takenCnt + 1);
			cntJP[gen[i][0]][gen[i][1]]--;
			cntJS[gen[i][0]][gen[i][2]]--;
			cntPS[gen[i][1]][gen[i][2]]--;
		}
	}
}

int solve() {
	cnt = 0;

	FOR(ij, 0, j) {
		FOR(ip, 0, p) {
			FOR(is, 0, s) {
				gen[cnt][0] = ij;
				gen[cnt][1] = ip;
				gen[cnt][2] = is;
				cnt++;
			}
		}
	}

	list(0, cnt, 0);

	cout << solCnt << endl;
	for (int i = 0; i < cnt; i++) {
		if (sol[i]) {
			cout << gen[i][0] + 1 << " " << gen[i][1] + 1 << " " << gen[i][2] + 1 << endl;
		}
	}

	return 0;
}

void printTestCaseHeader(int testIndex) {
	cout << "Case #" << testIndex << ": ";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int __T;
	scanf("%d", &__T);

	for (int i = 1; i <= __T; i++)
	{
		reset();
		readInput();
		printTestCaseHeader(i);
		solve();
		//cout << endl;
	}

	return 0;
}
