#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template <class T> T sqr(T x) { return x*x; }

const int INF = 1000*1000*1000;
const long long INF64 = sqr(static_cast<long long>(INF));
const double PI = acos(-1.0);

const int N = 110;
const int M = 110;

int n, m;
int h[N][M];
bool possible;

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int testCaseCount;
	cin >> testCaseCount;
	for(int testCaseNumber = 1; testCaseNumber <= testCaseCount; ++testCaseNumber)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &h[i][j]);
		possible = true;
		for (int i = 0; possible && i < n; ++i)
			for (int j = 0; possible && j < m; ++j)
			{
				bool horizontal = true;
				bool vertical = true;
				for (int k = 0; horizontal && k < m; ++k)
					horizontal = h[i][k] <= h[i][j];
				for (int k = 0; vertical && k < n; ++k)
					vertical = h[k][j] <= h[i][j];
				possible = horizontal || vertical;
			}
		cout << "Case #" << testCaseNumber << ": ";
		if (possible)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}