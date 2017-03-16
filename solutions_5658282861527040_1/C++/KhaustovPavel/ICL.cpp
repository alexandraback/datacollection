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
int a, b, k;
int64 f[30][2][2][2];
vector <int> A;
vector <int> B;
vector <int> K;

inline vector<int> get_vector(int x)
{
	vector<int> res;
	res.clear();
	for (int i = 0; i < 30; ++i)
	{
		res.push_back(x & 1);
		x >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}

inline int solve_slow(int a, int b, int k)
{
	int res = 0;
	for (int i = 0; i < a; ++i)
		for (int j = 0; j < b; ++j)
		{
			if ((i & j) < k)
				++res;
		}
	return res;
}

int64 rec(int x, int f1, int f2, int f3)
{
	if (x == 30)
	{
		return 1LL;
	}

	if (f[x][f1][f2][f3] != -1) return f[x][f1][f2][f3];
	
	int64 res = 0;

	int L1 = A[x];
	int L2 = B[x];
	int L3 = K[x];
	if (f1) L1 = 1;
	if (f2) L2 = 1;
	if (f3) L3 = 1;

	for (int i1 = 0; i1 <= L1; ++i1)
		for (int i2 = 0; i2 <= L2; ++i2)
		{
			int i3 = (i1 & i2);
			if (i3 > L3) continue;
			int nf1 = f1;
			int nf2 = f2;
			int nf3 = f3;
			if (i1 < L1) nf1 = 1;
			if (i2 < L2) nf2 = 1;
			if (i3 < L3) nf3 = 1;
			res += rec(x + 1, nf1, nf2, nf3);
		}

	return f[x][f1][f2][f3] = res;
}

int64 solve_fast(int a, int b, int k)
{
	memset(f, -1, sizeof f);
	A = get_vector(a - 1);
	B = get_vector(b - 1);
	K = get_vector(k - 1);
	int64 res = rec(0, 0, 0, 0);
	return res;
}

int main()
{	
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		cin >> a >> b >> k;
		cout << "Case #" << tn << ": ";
		int64 res = solve_fast(a, b, k);
		cout << res << endl;
	}

    return 0;
}