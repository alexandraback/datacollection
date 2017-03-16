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

const int maxn = 200;

int tests;
int n, m;
int row[maxn], col[maxn];
int a[maxn][maxn];

bool check(){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != min(row[i], col[j]))
				return false;
	return true;
}

bool tryrow(int x, int y){
	for (int i = 0; i < n; i++)
		row[i] = 100;
	for (int j = 0; j < m; j++)
		col[j] = 100;
	for (int j = 0; j < m; j++){
		if (j == y)
			continue;
		col[j] = a[x][j];
	}
	row[x] = a[x][y];
	for (int i = 0; i < n; i++){
		if (x == i)
			continue;
		for (int j = 0; j < m; j++){
			if (a[i][j] == col[j])
				continue;
			row[i] = min(row[i], a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i][y] == row[i])
			continue;
		else
			col[y] = min(a[i][y], col[y]);
	return check();
}

bool trycol(int x, int y){
	for (int i = 0; i < n; i++)
		row[i] = 100;
	for (int j = 0; j < m; j++)
		col[j] = 100;
	for (int i = 0; i < n; i++){
		if (i == x)
			continue;
		row[i] = a[i][y];
	}
	col[y] = a[x][y];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j == y)
				continue;
			if (a[i][j] == row[i])
				continue;
			col[j] = min(col[j], a[i][j]);
		}
	}
	for (int i = 0; i < m; i++)
		if (a[x][i] == col[i])
			continue;
		else
			row[x] = min(a[x][i], row[x]);
	return check();
}


int main()
{
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++){
		scanf("%d %d", &n, &m);
		int x, y;
		x = 0; y = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				scanf("%d", &a[i][j]);
				if (a[i][j] > a[x][y]){
					x = i;
					y = j;
				}
			}
		bool possible = tryrow(x, y);
		if (!possible)
			possible = trycol(x, y);
		printf("Case #%d: ", test);
		if (possible){
			printf("YES");
			for (int i = 0; i < n; i++)
				eprintf("ROW[%d] = %d\n", i, row[i]);
			for (int j = 0; j < m; j++)
				eprintf("COL[%d] = %d\n", j, col[j]);
		}
		else
			printf("NO");
		printf("\n");
	}
    return 0;
}
