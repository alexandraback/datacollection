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
int X, Y;
int RX, RY;
int n;
char ans[1 << 17];

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		cin >> X >> Y;
		RX = RY = 0;
		if (X < 0)
		{
			RX = 1;
			X = -X;
		}
		if (Y < 0)
		{
			RY = 1;
			Y = -Y;
		}
		n = 1;
		for (;;)
		{
			int V = n * (n + 1) / 2;
			if (V >= X + Y && !((V - X - Y) & 1)) break;
			++n;
		}
		memset(ans, 0, sizeof ans);
		int V = X;
		for (int i = n; i; --i)
		{
			if (V < i) continue;
			V -= i;
			ans[i] = 'N';
		}
		V = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (ans[i]) continue;
			V += i;
		}
		for (int i = n; i; --i)
		{
			if (ans[i]) continue;
			if (V - 2 * i >= Y)
			{
				V -= 2 * i;
				ans[i] = 'W';
			} else ans[i] = 'E';
		}
		cout << "Case #" << tn << ": ";
		for (int i = 1; i <= n; ++i)
		{
			if (RX)
			{
				if (ans[i] == 'N')
					ans[i] = 'S';
				else
				{
					if (ans[i] == 'S')
						ans[i] = 'N';
				}
			}
			if (RY)
			{
				if (ans[i] == 'E')
					ans[i] = 'W';
				else
				{
					if (ans[i] == 'W')
						ans[i] = 'E';
				}
			}
			cout << ans[i];
		}
		cout << endl;
		int TX = 0, TY = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (ans[i] == 'N') TX += i;
			if (ans[i] == 'S') TX -= i;
			if (ans[i] == 'E') TY += i;
			if (ans[i] == 'W') TY -= i;
		}
		if (abs(TX) != abs(X) || abs(TY) != abs(Y))
		{
			cerr << tn << " " << TX << " " << X << " ----- " << TY << " " << Y << endl;
		}
	}

    return 0;
}