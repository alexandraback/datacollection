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
int n, m, k;
int a[1 << 6][1 << 6]; 

inline void print()
{
	a[n - 1][m - 1] = 2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == 2)
			{
				printf("c");
				continue;
			}
			if (a[i][j] == 1)
			{
				printf("*");
				continue;
			}
			printf(".");
		}
		printf("\n");
	}
}

int main()
{	
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		printf("Case #%d:\n", tn);
		memset(a, 0, sizeof a);
		cin >> n >> m >> k;
		if (!k)
		{
			print();
			continue;
		}
		if (k == n * m - 1)
		{
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					a[i][j] = 1;
			a[n - 1][m - 1] = 0;
			print();
			continue;
		}
		if (n == 1)
		{
			if (k > m - 2)
			{
				printf("Impossible\n");
				continue;
			}
			for (int i = 0; i < k; ++i)
				a[0][i] = 1;
			print();
			continue;
		}
		if (m == 1)
		{
			if (k > n - 2)
			{
				printf("Impossible\n");
				continue;
			}
			for (int i = 0; i < k; ++i)
				a[i][0] = 1;
			print();
			continue;
		}
		if (k > n * m - 4)
		{
			printf("Impossible\n");
			continue;
		}
		if (k <= (n - 2) * (m - 2))
		{
			for (int i = 0; i < n - 2; ++i)
				for (int j = 0; j < m - 2; ++j)
				{
					if (!k) break;
					--k;
					a[i][j] = 1;
				}
			print();
			continue;
		}
		int left = n * m - k;
		if (left & 1)
		{
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					a[i][j] = 1;
			int fnd = 0;
			for (int A = 2; A <= n; ++A)
				for (int B = 2; B <= m; ++B)
				{
					if (fnd) break;
					int ok = 0;
					if (A * B == left)
					{
						fnd = 1;
						for (int i = n - A; i < n; ++i)
							for (int j = m - B; j < m; ++j)
								a[i][j] = 0;
						break;
					}
					if (A * B < left && !((left - A * B) & 1))
					{
						if ((n - A) * 2 + (m - B) * 2 >= left - A * B)
						{
							fnd = 1;
							int t = (left - A * B) >> 1;
							for (int j = m - B - 1; j >= 0; --j)
							{
								if (!t) break;
								a[n - 2][j] = a[n - 1][j] = 0;
								--t;
							}
							for (int i = n - A - 1; i >= 0; --i)
							{
								if (!t) break;
								a[i][m - 2] = a[i][m - 1] = 0;
								--t;
							}
							for (int i = n - A; i < n; ++i)
								for (int j = m - B; j < m; ++j)
									a[i][j] = 0;
						}
					}
				}
			if (!fnd)
				printf("Impossible\n");
			else
				print();
			continue;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = 1;
		left >>= 1;
		for (int j = m - 1; j >= 0; --j)
		{
			if (!left) break;
			a[n - 2][j] = a[n - 1][j] = 0;
			--left;
		}
		for (int i = n - 3; i >= 0; --i)
		{
			if (!left) break;
			a[i][m - 2] = a[i][m - 1] = 0;
			--left;
		}
		print();
	}
	
    return 0;
}