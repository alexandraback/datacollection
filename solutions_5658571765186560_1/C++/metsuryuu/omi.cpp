/*	Arkadiusz Wróbel - metsuryuu
 *
 *	Konkurs: Google Code Jam 2015
 *	Zadanie: Ominous Omino
 */
#include <cstdio>
#include <iostream>

#include <algorithm>
#include <cmath>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

#define REP(I, N) for(int I = 0; I < (N); ++I)
#define FOR(I, M, N) for(int I = (M); I <= (N); ++I)
#define FORD(I, M, N) for(int I = (M); I >= (N); --I)
//#define FOREACH(IT, CON) for(__typeof((CON).begin()) IT = (CON).begin(); IT != (CON).end(); ++IT)

#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define SIZE(CON) ((int)(CON).size())
#define ALL(CON) (CON).begin(), (CON).end()

const int INF = 1000000000;
const LL INFLL = 1000000000000000000LL;

//######################################################################

const vector<vector<vector<vector<bool>>>> allOminos {
	{
		// zerowe omina
	},
	{
		{
			{1}
		}
	},
	{
		{
			{1, 1}
		}
	},
	{
		{
			{1, 1, 1}
		},
		{
			{1, 0},
			{1, 1}
		}
	},
	// Tetramina
	{
		{
			{1, 1, 1, 1}
		},
		{
			{1, 1},
			{1, 1}
		},
		{
			{1, 1, 1},
			{1, 0, 0}
		},
		
		{
			{1, 1, 1},
			{0, 1, 0}
		},
		
		{
			{0, 1, 1},
			{1, 1, 0}
		}
	},
	// Pentomina
	{
		{
			{0, 1, 1},
			{1, 1, 0},
			{0, 1, 0}
		},
		{
			{1, 1, 1, 1, 1}
		},
		{
			{1, 1, 1, 1},
			{1, 0, 0, 0}
		},
		{
			{0, 1, 1, 1},
			{1, 1, 0, 0}
		},
		{
			{1, 1, 1},
			{1, 1, 0}
		},
		{
			{1, 1, 1},
			{0, 1, 0},
			{0, 1, 0}
		},
		//--------------
		{
			{1, 1, 1},
			{1, 0, 1}
		},
		{
			{1, 0, 0},
			{1, 0, 0},
			{1, 1, 1}
		},
		{
			{1, 0, 0},
			{1, 1, 0},
			{0, 1, 1}
		},
		{
			{0, 1, 0},
			{1, 1, 1},
			{0, 1, 0}
		},
		{
			{1, 1, 1, 1},
			{0, 1, 0, 0}
		},
		{  // Z
			{1, 1, 0},
			{0, 1, 0},
			{0, 1, 1}
		}
	},
	// Hexomina
	{
		{
			{1, 1, 1, 1, 1, 1}
		},
		{
			{1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0}
		},
		{
			{1, 1, 1, 1, 1},
			{0, 1, 0, 0, 0}
		},
		{
			{1, 1, 1, 1, 1},
			{0, 0, 1, 0, 0}
		},
		{
			{0, 1, 1, 1, 1},
			{1, 1, 0, 0, 0}
		},
		{
			{1, 1, 1, 1},
			{1, 1, 0, 0}
		},
		{
			{1, 1, 1, 1},
			{1, 0, 1, 0}
		},
		//-------------------
		{
			{1, 1, 1, 1},
			{1, 0, 0, 1}
		},
		{
			{1, 1, 1, 1},
			{0, 1, 1, 0}
		},
		{
			{1, 1, 1, 1},
			{1, 0, 0, 0},
			{1, 0, 0, 0}
		},
		{
			{1, 1, 1, 1},
			{0, 1, 0, 0},
			{0, 1, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 1, 1},
			{1, 0, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 1, 0, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 1, 0}
		},
		//-------------------
		{
			{1, 0, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 0, 1}
		},
		{
			{0, 1, 0, 0},
			{1, 1, 1, 1},
			{0, 0, 1, 0}
		},
		{
			{0, 1, 0, 0},
			{1, 1, 1, 1},
			{0, 1, 0, 0}
		},
		{
			{0, 1, 1, 1},
			{1, 1, 0, 0},
			{0, 1, 0, 0}
		},
		{
			{0, 1, 1, 1},
			{1, 1, 0, 1}
		},
		{
			{1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1}
		},
		{
			{1, 1, 1, 0},
			{0, 1, 1, 1}
		},
		//-------------------
		{
			{1, 1, 1},
			{1, 1, 1}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 1, 1},
			{0, 1, 0, 0}
		},
		{
			{1, 1, 0},
			{1, 1, 1},
			{1, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 1, 1},
			{0, 0, 1, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 1}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 1}
		},
		{
			{1, 1, 0},
			{1, 0, 0},
			{1, 1, 1}
		},
		//-------------------
		{
			{1, 1, 0},
			{0, 1, 0},
			{1, 1, 1}
		},
		{
			{1, 1, 0},
			{0, 1, 1},
			{1, 1, 0}
		},
		{
			{1, 0, 0, 0},
			{1, 1, 1, 0},
			{0, 0, 1, 1}
		},
		{
			{1, 0, 0},
			{1, 1, 0},
			{1, 1, 1}
		},
		{
			{0, 1, 0},
			{1, 1, 1},
			{1, 1, 0}
		},
		{
			{0, 0, 1},
			{1, 1, 1},
			{1, 1, 0}
		},
		{
			{0, 0, 1, 1},
			{0, 1, 1, 0},
			{1, 1, 0, 0}
		}
	}
};

const int wekt[][2] {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

vector<vector<bool>> mirror(const vector<vector<bool>> &omi) {
	int n = SIZE(omi);
	int m = SIZE(omi[0]);
	
	vector<vector<bool>> wyn;
	wyn.resize(m);
	REP(i, m) wyn[i].resize(n, 0);
	
	REP(i, n) {
		REP(j, m) {
			wyn[j][i] = omi[i][j];
		}
	}
	return wyn;
}

int X, R, C;

int t[32][32];
int counter;

void dfs(const int y, const int x) {
	t[y][x] = 2;
	++counter;
	REP(i, 4) {
		int ny = y + wekt[i][0];
		int nx = x + wekt[i][1];
		if (t[ny][nx] == 0) {
			t[ny][nx] = 2;
			dfs(ny, nx);
		}
	}
}

bool checkT() {  // Czy zablokowane tak ustawionym ominem?
	
	//printf("-------\n");
	//FOR(i, 0, R+1) {
		//FOR(j, 0, C+1) {
			//printf("%d ", t[i][j]);
		//}
		//printf("\n");
	//}
	
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			if (t[i][j] == 0) {
				counter = 0;
				dfs(i, j);
				if (counter % X != 0)
					return true;
			}
		}
	}
	return false;
}

bool check(vector<vector<bool>> ominos) {  // Czy da się zablokować takim ominem?
	int n = SIZE(ominos);
	int m = SIZE(ominos[0]);
	
//	printf("############## %d %d %d %d\n", n, m, R, C);
	
	FOR(i, n, R) {
		FOR(j, m, C) {
			FOR(y, 1, R) FOR(x, 1, C) t[y][x] = 0;
			REP(ii, n) {
				REP(jj, m) {
					t[i-n+1+ii][j-m+1+jj] = ominos[ii][jj];
				}
			}
			if (!checkT()) {
				return false;
			}
		}
	}
	
	ominos = mirror(ominos);
	swap(n, m);
	
	FOR(i, n, R) {
		FOR(j, m, C) {
			FOR(y, 1, R) FOR(x, 1, C) t[y][x] = 0;
			REP(ii, n) {
				REP(jj, m) {
					t[i-n+1+ii][j-m+1+jj] = ominos[ii][jj];
				}
			}
			if (!checkT()) {
				return false;
			}
		}
	}
	
	return true;
}

bool make() {  // Czy da się zablokować?
	if (X >= 7) {
		return true;
	}
	//if (X > 4) {
		//fprintf(stderr, "FATAL: X > 4\n");
		//exit(1);
	//}
	vector<vector<vector<bool>>> ominos = allOminos[X];
	
	for (auto &omi : ominos) {
		if (check(omi)) {
			return true;
		}
	}
	
	return false;
}

void verifyAllOminos() {
	FOR(x, 0, 6) {
		for (auto &omi : allOminos[x]) {
			int count = 0;
			for (auto &vv : omi) {
				for (int v : vv) {
					count += v;
				}
			}
			if (count != x) {
				fprintf(stderr, "FATAL: allOminos incorrect! (x = %d)\n", x);
				exit(1);
			}
		}
	}
}

int main()
{
	//auto mm = mirror(allOminos[4][0]);
	//for (auto &vv : mm) {
		//for (int v : vv) {
			//printf("%d ", v);
		//}
		//printf("\n");
	//}
	verifyAllOminos();
	int T;
	scanf("%d", &T);
	FOR(testCounter, 1, T){
		//wej
		scanf("%d%d%d", &X, &R, &C);
		FOR(i, 0, R+1) {
			t[i][0] = t[i][C+1] = 9;
		}
		FOR(i, 0, C+1) {
			t[0][i] = t[R+1][i] = 9;
		}
		//wyj
		printf("Case #%d: %s\n", testCounter, make() ? "RICHARD" : "GABRIEL");
	}
	return 0;
}
