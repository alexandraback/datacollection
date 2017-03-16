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

int A, B;

double p[100005];

void Load()
{
	scanf ("%d%d", &A, &B);

	for (int i = 0;i < A;i++)
		scanf ("%lf", &p[i]);
}

void Solve()
{
	long double ans = B + 2;

	long double curp = 1;
	for (int i = 0;i < A;i++) {
	 	curp *= p[i];
	 	ans = min(ans, curp * (A - i - 1 + B - i) + (1 - curp) * (A - i - 1 + B - i + B + 1));
	}
	ans = min(ans, curp * (B - A + 1) + (1 - curp) * (B - A + 1 + B + 1));
	printf ("%.07lf\n", (double)ans);
}

int main()
{
	freopen(Filename"a.in", "r", stdin);
	//freopen(Filename".out", "w", stdout);

	int t;
	cin >> t;

	for (int i = 0;i < t;i++) {

		printf("Case #%d: ", i + 1);
		Load();

		Solve();
	}

	return 0;
}
