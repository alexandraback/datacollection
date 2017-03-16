#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
using namespace std;
#define re return
#define LL unsigned long long
#define EPS 0.00000000000001
#define MOD 1000000009
#define INF 1000000000000000000LL
#define K 101

typedef struct{
	LL positions[K];
	LL positionsCount;
}tresult;
void solve(LL k, LL c, tresult & result)
{
	LL sum = 1;
	for (int j = 0; j < c; ++j)sum *= k;

	result.positionsCount = 0;

	LL curSize = sum;
	LL position = 0;
	for (int i = 0; i < k; ++i)
	{
		if (curSize < k)
		{
			result.positions[result.positionsCount++] = position;
			position = 0;
			curSize = sum;
		}
		position += (curSize / k) * i;
		curSize /= k;
	}
	result.positions[result.positionsCount++] = position;
}

int main()
{
#ifdef _DINARISIO
	ifstream cin("D-small-attempt1.in");
	ofstream cout("A.out");
#endif

	int T;
	cin >> T;
	tresult result;
	for (int t = 0; t < T; ++t)
	{
		LL k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << t + 1 << ":";
		solve(k, c, result);
		if (result.positionsCount > s)
		{
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		for (int i = 0; i < result.positionsCount; ++i)
		{
			cout << " " << result.positions[i] + 1;
		}
		cout << endl;
	}
	re 0;
}