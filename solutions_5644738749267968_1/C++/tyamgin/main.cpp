#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <sstream> 
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

int solveWar(vector<double> a, vector<double> b)
{
	reverse(a.begin(), a.end());
	set<double> B(b.begin(), b.end());
	int result = 0;
	for (auto v : a)
	{
		auto it = B.lower_bound(v);
		if (it == B.end())
			it = B.begin();
		result += v > *it;
		B.erase(it);
	}
	return result;
}

int solveWarKnown(vector<double> a, vector<double> b)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] < b[i])
			return 0;
	return a.size();
}

int solveDeceitfulWar(vector<double> a, vector<double> b)
{
	int result = 0;
	for (int i = 0; i <= a.size(); i++)
		result = max(result, solveWarKnown(vector<double>(a.begin() + i, a.end()), vector<double>(b.begin(), b.end() - i)));
	return result;
}

int main()
{
	int tests, n, i, j;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		scanf("%d", &n);
		vector<double> a(n), b(n);
		for (i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		for (i = 0; i < n; i++)
			scanf("%lf", &b[i]);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		printf("Case #%d: %d %d\n", test, solveDeceitfulWar(a, b), solveWar(a, b));
	}
}