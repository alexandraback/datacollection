#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <bitset>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1000 * 1000 * 1000;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int) v.size()
#define MP make_pair
#define PB push_back

#define TASK ""

char table[1 << 3][1 << 3];

int main() {
	#ifdef EDDY
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else 
	//	freopen(TASK ".in", "r", stdin);
	//	freopen(TASK ".out", "w", stdout);
	#endif

	int T;

	scanf("%d", &T);

	int tc = 0;

	while (T--) {
		printf("Case #%d: ", ++tc);
		
		REP(i, 4) {
			scanf("%s", table[i]);
		}

		bool miss, check;

		/////////////////////////

		miss = false;
		REP(i, 4) {
			bool check = true;
			REP(j, 4)
				if (table[i][j] != 'X' && table[i][j] != 'T') {
					check = false;
					break;
				}
			if (check) {
				puts("X won");
				miss = true;
				break;
			}
		}
		if (miss) {
			continue;
		}
		REP(j, 4) {
			bool check = true;
			REP(i, 4)
				if (table[i][j] != 'X' && table[i][j] != 'T') {
					check = false;
					break;
				}
			if (check) {
				puts("X won");
				miss = true;
				break;
			}
		}
		if (miss) {
			continue;
		}
		check = true;
		REP(i, 4)
			if (table[i][i] != 'X' && table[i][i] != 'T') {
				check = false;
				break;
			}
		if (check) {
			puts("X won");
			miss = true;
		}
		if (miss) {
			continue;
		}
		check = true;
		REP(i, 4)
			if (table[i][3 - i] != 'X' && table[i][3 - i] != 'T') {
				check = false;
				break;
			}
		if (check) {
			puts("X won");
			miss = true;
		}
		if (miss) {
			continue;
		}

		/////////////////////////

		miss = false;
		REP(i, 4) {
			bool check = true;
			REP(j, 4)
				if (table[i][j] != 'O' && table[i][j] != 'T') {
					check = false;
					break;
				}
			if (check) {
				puts("O won");
				miss = true;
				break;
			}
		}
		if (miss) {
			continue;
		}
		REP(j, 4) {
			bool check = true;
			REP(i, 4)
				if (table[i][j] != 'O' && table[i][j] != 'T') {
					check = false;
					break;
				}
			if (check) {
				puts("O won");
				miss = true;
				break;
			}
		}
		if (miss) {
			continue;
		}
		check = true;
		REP(i, 4)
			if (table[i][i] != 'O' && table[i][i] != 'T') {
				check = false;
				break;
			}
		if (check) {
			puts("O won");
			miss = true;
		}
		if (miss) {
			continue;
		}
		check = true;
		REP(i, 4)
			if (table[i][3 - i] != 'O' && table[i][3 - i] != 'T') {
				check = false;
				break;
			}
		if (check) {
			puts("O won");
			miss = true;
		}
		if (miss) {
			continue;
		}

		/////////////////////////

		check = false;
		REP(i, 4)
			REP(j, 4)
				if (table[i][j] == '.') {
					check = true;
				}
		if (check) {
			puts("Game has not completed");
			miss = true;
		}
		if (miss) {
			continue;
		}


		puts("Draw");
	}

	return 0;
}