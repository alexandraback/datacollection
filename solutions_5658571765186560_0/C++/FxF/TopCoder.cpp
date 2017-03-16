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

char ans[4][4][4];
string S[2] = {"GABRIEL", "RICHARD"};

void solution()
{
	int T;
	cin >> T;
	MEMS(ans, 0);

	ans[3][1][3] = 1;
	ans[3][2][3] = 0;
	ans[3][3][3] = 0;
	ans[3][3][4] = 0;

	ans[4][1][4] = 1;
	ans[4][2][2] = 1;
	ans[4][2][4] = 1;
	ans[4][3][4] = 0;


	FOR(t, 1, T)
	{
		int x, r, c;
		cin >> x >> r >> c;

		if (r > c)
			swap(r, c);

		if ((r * c) % x)
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