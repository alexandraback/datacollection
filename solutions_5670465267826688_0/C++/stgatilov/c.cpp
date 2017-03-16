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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 1<<20;
const int MULT = 20;

int matr[8][8];

#define ONE 0
#define I 1
#define J 2
#define K 3
#define NEG(x) ((x) ^ 4)

void Init() {
	for (int i = 0; i < 8; i++)
		matr[ONE][i] = matr[i][ONE] = i;
	matr[I][I] = NEG(ONE);
	matr[I][J] = K;
	matr[I][K] = NEG(J);
	matr[J][I] = NEG(K);
	matr[J][J] = NEG(ONE);
	matr[J][K] = I;
	matr[K][I] = J;
	matr[K][J] = NEG(I);
	matr[K][K] = NEG(ONE);
	for (int u = 0; u < 2; u++)
		for (int v = 0; v < 2; v++) {
			if (!u && !v) continue;
			int neg = (u == v ? 0 : 4);
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					matr[u*4+i][v*4+j] = neg ^ matr[i][j];
		}
}

int n;
int64 x;
char str[SIZE];
int arr[SIZE];

bool res[SIZE][4][8];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Init();

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d%I64d", &n, &x);
		scanf("%s", str);

		for (int i = 0; i < n; i++) {
			char c = str[i];
			arr[i] = -1;
			if (c == 'i') arr[i] = I;
			if (c == 'j') arr[i] = J;
			if (c == 'k') arr[i] = K;
		}

		int mlt = (x <= MULT ? int(x) : MULT + x % 4);
		int len = mlt * n;

		for (int i = n; i < len; i++)
			arr[i] = arr[i - n];
		arr[len] = ONE;

		memset(res, 0, (len+10) * sizeof(res[0]));
		res[0][0][ONE] = true;
		for (int i = 0; i <= len; i++)
			for (int k = 0; k < 3; k++)
				for (int v = 0; v < 8; v++) if (res[i][k][v]) {
					if (v == 1 + k)
						res[i][k+1][ONE] = true;
					res[i+1][k][matr[v][arr[i]]] = true;
				}

		bool ans = res[len][3][ONE];

		printf("Case #%d: %s\n", tt, ans ? "YES" : "NO");
		fflush(stdout);
	}
	return 0;
}
