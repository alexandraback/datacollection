#pragma comment (linker, "/STACK:64000000")
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <bitset>
#include <sstream>
#include <set>
#include <map>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

#define maxn 100100

int a, b;
double p[maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testCount = 0; testCount < testNum; testCount++)
	{
		cin >> a >> b;
		for (int i = 0; i < a; i++)
			cin >> p[i];

		double best = b + 2;

		double d = 1;
		for (int i = 0; i < a; i++)
		{
			d *= p[i];
			best = min(best, d * (a - i + b - i - 1) + (1 - d) * (a - i + b - i + b));
		}
		printf("Case #%d: %lf\n", testCount + 1, best);
	}
	return 0;
}