#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

//kAc
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;
char a[10][10];
bool check1(int x, int y, char c)
{
	for (int i = 1; i <= 4; i++) if (a[i][y] != c && a[i][y] != 'T') return false;
	return true;
}
bool check2(int x, int y, char c)
{
	for (int i = 1; i <= 4; i++) if (a[x][i] != c && a[x][i] != 'T') return false;
	return true;
}
bool check3(int x, int y, char c)
{
	for (int i = 1; i <= 4; i++) if (a[i][i] != c && a[i][i] != 'T') return false;
	return true;
}
bool check4(int x, int y, char c)
{
	for (int i = 1; i <= 4; i++) if (a[i][5 - i] != c && a[i][5 - i] != 'T') return false;
	return true;
}
int main()
{
	freopen("A.in", "r", stdin); freopen("A.out", "w", stdout);
	int T;scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++){
		printf("Case #%d: ", ti);
		for (int i = 1; i <= 4; i++){
			scanf(" ");
			for (int j = 1; j <= 4; j++) a[i][j] = getchar();
		}
		bool winO = false, winX = false, empty = false;
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++){
				if (check1(i, j, 'O')) winO = true;
				if (check2(i, j, 'O')) winO = true;
				if (check3(i, j, 'O')) winO = true;
				if (check4(i, j, 'O')) winO = true;
				if (check1(i, j, 'X')) winX = true;
				if (check2(i, j, 'X')) winX = true;
				if (check3(i, j, 'X')) winX = true;
				if (check4(i, j, 'X')) winX = true;
				if (a[i][j] == '.') empty = true;
			}	
		if (winX && winO) puts("Draw");
		else if (winX) puts("X won");
		else if (winO) puts("O won");
		else if (empty) puts("Game has not completed");
		else puts("Draw");
   	} 

}
