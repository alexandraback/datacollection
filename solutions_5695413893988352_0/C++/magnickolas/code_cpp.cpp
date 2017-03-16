#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, N) for (decltype(N) i = 0; i < N; i++)
#define dep(i, N) for (decltype(N) i = N - 1; i >= 0; i--)
#define FOR(i, A, B) for (decltype(B) i = A; i <= B; i++)
#define FORD(i, A, B) for (decltype(A) i = A; i >= B; i--)
#define len(A) (int)A.size()
#define all(A) A.begin(), A.end()

typedef long long int64;
typedef unsigned long long uint64;
typedef long double ld;


using namespace std;

template<typename T>
T sqr(const T &a)
{
	return a * a;
}

vector<int> C, J;
string c, j;
void genc(int pos = 0, int cur = 0)
{
	if (pos == len(c))
	{
		C.push_back(cur);
		return;
	}
	if (c[pos] != '?')
		genc(pos + 1, cur * 10 + (c[pos] - '0'));
	else
	{
		rep(nxt, 10)
			genc(pos + 1, cur * 10 + nxt);
	}
}
void genj(int pos = 0, int cur = 0)
{
	if (pos == len(j))
	{
		J.push_back(cur);
		return;
	}
	if (j[pos] != '?')
		genj(pos + 1, cur * 10 + (j[pos] - '0'));
	else
	{
		rep(nxt, 10)
			genj(pos + 1, cur * 10 + nxt);
	}
}
int cnt(int x)
{
	if (x == 0)
		return 1;
	int res = 0;
	while (x > 0)
	{
		res++;
		x /= 10;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	rep(t, T)
	{
		cin >> c >> j;
		C.clear(), J.clear();
		genc(), genj();
		int rx = 0, ry = 1000;
		for (auto &x : C)
		{
			for (auto &y : J)
			{
				if (abs(x - y) < abs(rx - ry) || abs(x - y) == abs(rx - ry) && y < ry)
					rx = x, ry = y;
			}
		}
		cout << "Case #" << t + 1 << ": ";
		rep(i, len(c) - cnt(rx))
			cout << '0';
		cout << rx << ' ';
		rep(i, len(c) - cnt(ry))
			cout << '0';
		cout << ry << endl;
	}
	return 0;
}