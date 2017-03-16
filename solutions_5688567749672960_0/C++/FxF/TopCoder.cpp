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

int ans[1000050];

int rev(int x)
{
	if (x % 10 == 0)
		return 10000000;
	int y = x;
	int r = 1;
	while (x)
	{
		x /= 10;
		r *= 10;
	}
	while (y)
	{
		r /= 10;
		x += r * (y % 10);
		y /= 10;
	}
	if (ans[x] == 0)
		return 10000000;
	else
		return ans[x];
}

void solution()
{
	int T;
	cin >> T;
	ans[1] = 1;
	
	FOR(i, 2, 1000000)
	{
		ans[i] = MIN(ans[i - 1], rev(i)) + 1;
	}

	int t = 0;
	while (T--)
	{
		LL n;
		cin >> n;
		t++;
		printf("Case #%d: ", t);
		cout << ans[n] << endl;
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