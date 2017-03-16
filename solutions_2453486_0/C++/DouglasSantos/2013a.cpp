#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

char v[4][4];

bool verificaLinha(int ind, char c) {
	REP(j, 4) {
		if (v[ind][j] != c && v[ind][j] != 'T') return false;
	}
	return true;
}

bool verificaColuna(int ind, char c) {
	REP(j, 4) {
		if (v[j][ind] != c && v[j][ind] != 'T') return false;
	}
	return true;
}

bool verificaDiagonal1(char c) {
	REP(i, 4) {
		if (v[i][i] != c && v[i][i] != 'T') return false;
	}
	return true;
}

bool verificaDiagonal2(char c) {
	REP(i, 4) {
		if (v[i][3-i] != c && v[i][3-i] != 'T') return false;
	}
	return true;
}

int main()
{	
	int t;
	scanf("%d", &t);
	REP(k, t) {
		REP(i, 4) {
			REP(j, 4) {
				scanf(" %c", &v[i][j]);
				//printf("%c", v[i][j]);
			}
			//printf("\n");
		}
		printf("Case #%d: ", k+1); 
		int res = -1;
		REP(i, 4) {
			if (verificaLinha(i, 'X')) {
				res = 0;
				break;
			} 
			if (verificaLinha(i, 'O')) {
				res = 1;
				break;
			}
			if (verificaColuna(i, 'X')) {
				res = 0;
				break;
			}
			if (verificaColuna(i, 'O')) {
				res = 1;
				break;
			}
		}
		if (verificaDiagonal1('X') || verificaDiagonal2('X')) {
			res = 0;
		}
		if (verificaDiagonal1('O') || verificaDiagonal2('O')) {
			res = 1;
		}
		if (res == 0) {
			printf("X won\n");
			continue;
		}
		if (res == 1) {
			printf("O won\n");
			continue;
		}
		bool erro = false;
		REP(i, 4) 
			REP(j, 4) 
				if (v[i][j] == '.') {
					erro = true;
					break;
				}
		if (erro) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	return 0;
}