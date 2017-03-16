#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(i=a; i<=b; i++)
#define fj(a, b) for(j=a; j<=b; j++)
#define fo(a, b) for(o=a; o<=b; o++)
#define fdi(a, b) for(i=a; i>=b; i--)
#define fdj(a, b) for(j=a; j>=b; j--)
#define fdo(a, b) for(o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int testq;
int test;

int n = 4;
char matr[10][10];

void Read() {
	int j;
	fj(1, 4) {
		scanf("%s", matr[j] + 1);
	}
}

int dx[] = {1,1,0,-1};
int dy[] = {0,1,1,1};

bool Check(int x, int y, int d, char t) {
	int i;
	fi(1, 4) {
		if (matr[y][x] != t && matr[y][x] != 'T') return false;
		x += dx[d];
		y += dy[d];
	}
	return true;
}

bool Check(char t) {
	int i, j;
	fi(1, 4) {
		if (Check(i, 1, 2, t)) return true;
	}
	fj(1, 4) {
		if (Check(1, j, 0, t)) return true;
	}
	return Check(1, 1, 1, t) || Check(4, 1, 3, t);
}

void Solve() {
	int i, j;
	int w1, w2;
	int f;
	w1 = 0;
	w2 = 0;
	if (Check('X')) w1 = 1;
	if (Check('O')) w2 = 1;

	f = 0;
	fj(1, 4) {
		fi(1, 4) {
			if (matr[j][i] == '.') f = 1;
		}
	}

	if (!w1 && !w2 && !f) {
		printf("Draw\n");
	} else if (!w1 && !w2) {
		printf("Game has not completed\n");
	} else if (w1) {
		printf("X won\n");
	} else {
		printf("O won\n");
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &testq);
	for (test = 1; test <= testq; test++) {
		Read();
		printf("Case #%d: ", test);
		Solve();
		fflush(stdout);
	}
	return 0;
}