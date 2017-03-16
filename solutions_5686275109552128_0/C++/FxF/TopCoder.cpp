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

int ans;
int a[1050];
int D;

bool check(int moves, int maxpancakes)
{
	int now = 0;
	FOR(i, 1, D)
		now += (a[i] - 1) / maxpancakes;
	return (now <= moves);
}

void solution()
{
	int T;
	cin >> T;
	FOR(t, 1, T)
	{
		scanf("%d", &D);
		int ans = 0;
		FOR(i, 1, D)
		{
			scanf("%d", &a[i]);
			ans = MAX(ans, a[i]);
		}
		FOR(moves, 0, ans - 1)
		{
			FOR(maxpancakes, 1, ans - moves - 1)
			{
				if (check(moves, maxpancakes))
					ans = moves + maxpancakes;
			}
		}

		printf("Case #%d: %d\n", t, ans);
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