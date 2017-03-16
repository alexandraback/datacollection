#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

#define ABS(a) (((a) > 0)? (a): -(a))
#define MIN(a, b) (((a) < (b))? (a): (b))
#define MAX(a, b) (((a) < (b))? (b): (a))
#define MFOR(i, a, n) for (int i = (a); i < (n); i++)
#define FOR(i, a, n) for (int i = (a); i <= (n); i++)
#define DFOR(i, a, n) for (int i = (a); i >= (n); i--)
#define SORT(a, first_element, last_element) sort(&(a)[(first_element)], &(a)[(last_element) + 1])
#define SQR(a) (a) * (a)
#define PI 3.14159265358979323846264
#define MEMS(a, b) memset((a), (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'
#define LL long long
#define UN unsigned
#define Or ||
#define And &&
/////////////////////////////////////////////

char ans[22][22][22];
string S[2] = {"GABRIEL", "RICHARD"};

void solution()
{

	MEMS(ans, 0);
	ans[4][2][2] = 1;
	ans[4][2][4] = 1;
	ans[4][2][6] = 1;
	ans[4][2][8] = 1;
	ans[4][2][10] = 1;
	ans[4][2][12] = 1;
	ans[4][2][14] = 1;
	ans[4][2][16] = 1;
	ans[4][2][18] = 1;
	ans[4][2][20] = 1;

	ans[5][3][5] = 1;
	ans[5][3][10] = 1;
	ans[5][3][15] = 1;
	ans[5][3][20] = 1;

	ans[6][3][4] = 1;
	ans[6][3][6] = 1;
	ans[6][3][8] = 1;
	ans[6][3][10] = 1;
	ans[6][3][12] = 1;
	ans[6][3][14] = 1;
	ans[6][3][16] = 1;
	ans[6][3][18] = 1;
	ans[6][3][20] = 1;

	int T;
	cin >> T;

	FOR(t, 1, T)
	{
		int x, r, c;
		cin >> x >> r >> c;

		if (r > c)
			swap(r, c);

		if ((r * c) % x)
			ans[x][r][c] = 1;

		if (x >= 7)
			ans[x][r][c] = 1;
		
		int mx = (x + 1) / 2;

		if (mx > r)
			ans[x][r][c] = 1;

		printf("Case #%d: ", t);
		cout << S[ans[x][r][c]] << endl;
	}
}

/*-------------------*/

int main()
{
#ifdef Files
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
/*Test*/
//freopen("input.txt", "w", stdout);

double OcZ2X = clock();
#else
//freopen("unionday.in", "r", stdin);
//freopen("unionday.out", "w", stdout);
#endif

solution();

#ifdef Time
double P2HxQ = clock();
printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}