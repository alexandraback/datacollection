/*
   Google Code Jam
   Author: FLD 
   Date: 2014/04/12

   Save small input as stdin_small.txt
   Compile with: g++ -o small -DSMALL source.cpp
   Run with ./small
   Check output in stdout_small.txt

   Save large input as large.txt
   Compile with: g++ -o large -DLARGE source.cpp
   Run with ./large
   Check output in stdout_small.txt
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;


#define FOR(loop,first,end) for(int loop=(int)(first);loop<(int)(end);loop++)
#define REP(loop,times) FOR(loop,0,times)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


#define MINE '*'
#define CLICK 'c'
#define EMPTY '.'

char grid[50][50];


void print_grid(int r, int c) {
	REP(i, r) {
		REP(j, c) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}
void print_dirg(int r, int c) {
	REP(i, c) {
		REP(j, r) {
			cout << grid[j][i];
		}
		cout << endl;
	}
}

bool min_solve(int r, int c, int e) {
	int lastr, lastc;
	if ((c > 1) && (e < 4)) {
		return false;
	}
	if (c == 2) {
		if ((e%2) == 1) { 
			return false;
		}
	} 
	int rem = e;
	REP(i, r){
		lastr=i;
		REP(j,c) {
			lastc=j;
			rem--;
			grid[i][j] = EMPTY;
			if (rem == 0) {
				break;
			}
		}
		if (rem == 0) {
			break;
		}
	}
	if (c > 1) {
		if ((lastr == 1) && (lastc <c-1)) { return false; }
		if (grid[lastr][1] == MINE) {
			if (lastr == 2) { return false; }
			grid[lastr][1] = EMPTY;
			grid[lastr-1][c-1] = MINE;
		}
	}
	return true;
}


void solve(int r, int c, int e, bool rot, int tc) {
	int sq = (int)sqrt(e);
	if (e > sq*sq) { sq++; }
	int nc = MIN(c, sq);
	if ((e<1) || (!min_solve(r, nc, e))) {
		printf("Case #%d:\nImpossible\n", tc);
		return;
	}

	grid[0][0] = CLICK;
	printf("Case #%d:\n", tc);
	if (rot) {
		print_dirg(r, c);
	} else {
		print_grid(r, c);
	}
}

int main(int argc, char const *argv[])
{
	int T, R, C, M;

	// adjust stding and stdout
	#ifdef DEFAULT
	freopen("stdin.txt","rt",stdin);
	#endif
	#ifdef SMALL
	freopen("stdin_small.txt","rt",stdin);
	freopen("stdout_small.txt","wt",stdout);
	#endif
	#ifdef LARGE
	freopen("stdin_large.txt","rt",stdin);
	freopen("stdout_large.txt","wt",stdout);
	#endif

	cin >> T;
	REP(t,T) {
		cin >> R >> C >> M;
		memset(grid, MINE, 50*50*sizeof(char));
		if (C <= R) {
			solve(R, C, R*C-M, false, t+1);
		} else {
			solve(C, R, R*C-M, true, t+1);
		}
	}
	
	return 0;
}