#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <ctime>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cassert>
#include <climits>
#include <fstream>

using namespace std;

#define Filename ""
#define sqr(a) (a)*(a)

typedef long long lng;
typedef long double ldb;

const double EPS = 1e-8;

int N, S, p, d[105][105], t[105];

void Load()
{
	cin >> N >> S >> p;

	for (int i = 0;i < N;i++)
		cin >> t[i];
}

int get (int a, bool sur) {
	int res = 0;
 	for (int i = 10;i >= 0;i--) {
 	 	for (int j = i;j >= max (0, i - 2);j--) {
 	 	 	for (int k = j;k >= max (0, i - 2);k--) {
 	 	 	 	if (i + j + k != a) continue;

 	 	 	 	if (sur && i - k != 2) continue;
 	 	 	 	if (!sur && i - k == 2) continue;

 	 	 	 	res = max (res, i);
 	 	 	}
 	 	}
 	}
 	return res;
}

void Solve()
{
	memset (d, 0, sizeof (d));

	for (int i = 0;i < N;i++) {
	 	for (int j = 0;j <= S;j++) {
	 	 	int s1 = get (t[i], 0);
	 	 	int s2 = get (t[i], 1);
	 	 	//cerr << i << " " << s1 << " " << s2 << endl;

	 	 	d[i + 1][j] = max (d[i + 1][j], d[i][j] + (s1 >= p));
	 	 	d[i + 1][j + 1] = max (d[i + 1][j + 1], d[i][j] + (s2 >= p));
	 	}
	}
	printf ("%d\n", d[N][S]);
}

int main()
{
	//freopen(Filename".in", "r", stdin);
	//freopen(Filename".out", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {

		printf ("Case #%d: ", i + 1);
		Load();

		Solve();
	}

	return 0;
}
