#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <iostream>
#include <cmath>
#include <sstream>
#include <complex>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:128000000")

typedef long long int64;
typedef unsigned long long uint64;

#define y1 _dsfkjdsfksdj
#define y0 _sfsdkfdop

typedef unsigned uint;
typedef vector<int64> vi64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int64,int64> pii64;
typedef pair<int,pii> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef pair<int,string> pis;

int nt;
int n;
double a[1 << 10];
double b[1 << 10];

int main()
{	
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	scanf("%d", &nt);
	for (int tn = 1; tn <= nt; ++tn)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &a[i]);
		for (int i = 0; i < n; ++i)
			scanf("%lf", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		int res1 = 0, res2 = 0;
		int j = n - 1;
		for (int i = n - 1; i >= 0; --i)
		{
			while (j >= 0 && b[j] > a[i]) --j;
			if (j >= 0)
			{
				++res1;
				--j;
			}
		}
		j = 0;
		for (int i = 0; i < n; ++i)
		{
			while (j < n && b[j] < a[i]) ++j;
			if (j < n)
			{
				++res2;
				++j;
			}
		}
		res2 = n - res2;
		printf("Case #%d: %d %d\n", tn, res1, res2);
	}
	


    return 0;
}