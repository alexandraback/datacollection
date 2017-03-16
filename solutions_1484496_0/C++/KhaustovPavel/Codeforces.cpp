#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>

#pragma comment(linker, "/STACK:64000000") 

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pii64;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

#define xn _dsfhsdfsj
#define yn _dthsdfshj

#define toMod 1000000007

int mask;
int n;
int a[1 << 5];

inline int getSum(int mask)
{
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (mask & (1 << i))
			res += a[i];
	return res;
}

void print(int mask)
{
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i))
			printf("%d ", a[i]);
	}
	printf("\n");
}

inline void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

pii w[1 << 20];
int nt, tn;

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	tn = 0;
	scanf("%d", &nt);
	for (;nt--;)
	{
		init();

		++tn;
		printf("Case #%d:\n", tn);
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			w[mask] = pii(getSum(mask), mask);
		}
		sort(w, w + (1 << n));
		int ok = 0;
		for (int i = 1; i < (1 << n); ++i)
		{
			if (w[i].first != w[i - 1].first) continue;
			print(w[i - 1].second);
			print(w[i].second);
			ok = 1;
			break;
		}
		if (!ok) puts("Impossible");
	}

	return 0;
}