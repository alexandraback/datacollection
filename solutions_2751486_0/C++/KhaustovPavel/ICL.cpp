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

#pragma comment(linker, "/STACK:64000000")

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
typedef pair<pii,int> piii;
typedef pair<pii,pii> piiii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;

int nt;
int n;
string s;
int l;
int a[1 << 20];
int b[1 << 20];

inline int getsum(int l, int r)
{
	int res = a[r];
	if (l) res -= a[l - 1];
	return res;
}

inline int vowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

inline void init()
{
	cin >> s >> n;
	l = (int)s.length();
	for (int i = 0; i < l; ++i)
	{
		a[i] = 0;
		if (i) a[i] = a[i - 1];
		if (!vowel(s[i])) ++a[i];
	}
}

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		init();
		//int64 res = (int64)l * (int64)(l + 1) / 2LL;
		int64 res = 0;
		memset(b, 0, sizeof b);
		for (int i = 0; i + n <= l; ++i)
		{
			if (getsum(i, i + n - 1) != n) continue;
			b[i + n - 1] = 1;
		}
		int j = 0;
		for (int i = 0; i < l; ++i)
		{
			while (j < l && (j - i < n - 1 || !b[j])) ++j;
			res += (int64)(l - j);
		}
		cout << "Case #" << tn << ": " << res << endl;
	}

    return 0;
}