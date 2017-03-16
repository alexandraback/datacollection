#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define len(x) (int((x).size()))
#ifdef LOCALD
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#ifdef __linux__
#define I64d "%lld"
#else
#define I64d "%I64d"
#endif

typedef long long int int64;
typedef long double ext;

const int inf = 1000000000;


using namespace std;

int tests;

const int n = 4;

char f[n][n];
int a[2 * n + 2], b[2 * n + 2];
int empty;

int main()
{
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
	scanf("%d\n", &tests);
	for (int test = 1; test <= tests; test++){
		empty = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%c", &f[i][j]);
				if (f[i][j] == '.')
					empty++;
			}
			scanf("\n");
		}

		for (int i = 0; i < 2 * n + 2; i++)
			a[i] = b[i] = 0;

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (f[i][j] == 'X'){
					a[i]++;
					a[n + j]++;
					if (i == j)
						a[2 * n]++;
					if (i + j == n - 1)
						a[2 * n + 1]++;
				}
				if (f[i][j] == 'O'){
					b[i]++;
					b[n + j]++;
					if (i == j)
						b[2 * n]++;
					if (i + j == n - 1)
						b[2 * n + 1]++;
				}
				if (f[i][j] == 'T'){
					a[i]++;
					a[n + j]++;
					b[i]++;
					b[n + j]++;
					if (i == j){
						a[2 * n]++;
						b[2 * n]++;
					}
					if (i + j == n - 1){
						a[2 * n + 1]++;
						b[2 * n + 1]++;
					}
				}
			}
		}
		bool wa, wb;
		wa = wb = false;
		for (int i = 0; i < 2 * n + 2; i++){
			if (a[i] == 4)
				wa = true;
			if (b[i] == 4)
				wb = true;
		}
		printf("Case #%d: ", test);
		if (wa)
			printf("X won");
		else if (wb)
			printf("O won");
		else if (empty == 0)
			printf("Draw");
		else
			printf("Game has not completed");
		printf("\n");
		scanf("\n");
	}
    return 0;
}
