#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_STATE = 8 * 3 + 3;
const int SZ = 30;

struct Matrix
{
	int a[SZ][SZ];
	int n, m;
	Matrix()
	{
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	Matrix(int _n, int _m)
	{
		n = _n;
		m = _m;
		memset(a, 0, sizeof(a));
	}
	static Matrix ent(int _n)
	{
		Matrix res = Matrix(_n, _n);
		for (int i = 0; i < _n; i++)
			res.a[i][i] = 1;
		return res;
	}
	Matrix operator * (const Matrix &x) const
	{
		Matrix res = Matrix(n, x.m);
		for (int i = 0; i < n; i++)
			for (int s = 0; s < x.m; s++)
				for (int q = 0; q < m; q++)
				{
					res.a[i][s] = max(res.a[i][s], a[i][q] * x.a[q][s]);
				}
		return res;
	}
};

Matrix myPow(Matrix a, int k)
{
	if (k == 0)
		return Matrix::ent(a.n);
	if (k & 1)
		return a * myPow(a, k - 1);
	Matrix t = myPow(a, k / 2);
	return t * t;
}

const int trans[5][5] = 
{
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

int sgn(int a)
{
	if (a < 0)
		return -1;
	if (a == 0)
		return 0;
	return 1;
}

int operation(int a, int b)
{
	return trans[abs(a)][abs(b)] * sgn(a) * sgn(b);
}

int getSymbol(char c)
{
	if (c == 'i')
		return 2;
	if (c == 'j')
		return 3;
	if (c == 'k')
		return 4;
	throw;
}

struct State
{
	int value;
	int index;
	State () : value(), index() {}
	State (int _value, int _index)
	{
		value = _value;
		index = _index;
	}
	State addSymbol(int nv)
	{
		return State(operation(value, nv), index);
	}
	int getId()
	{
		return (value + 4) * 3 + (index - 2);
	}
	static State getState(int id)
	{
		int i = id % 3 + 2;
		int v = id / 3 - 4;
		return State(v, i);
	}
	bool tryCut(int nv, State &st)
	{
		if (value == index)
		{
			st = State(nv, index + 1);
			return true;
		}
		return false;
	}
};

string str;
Matrix T;
int dp[2][MAX_STATE];

void getEndState(State start)
{
	memset(dp[0], 0, sizeof(dp[0]));
	dp[0][start.getId()] = 1;
	for (int i = 0; i < (int)str.length(); i++)
	{
		int cur = (i & 1);
		int nxt = 1 - cur;
		memset(dp[nxt], 0, sizeof(dp[nxt]));
		for (int s = 0; s < MAX_STATE; s++)
		{
			if (!dp[cur][s])
				continue;
			State c = State::getState(s);
			State nc = c.addSymbol(getSymbol(str[i]));
			dp[nxt][nc.getId()] = 1;
			if (c.tryCut(getSymbol(str[i]), nc))
			{
				if (nc.index <= 4)
					dp[nxt][nc.getId()] = 1;
			}
		}
	}
	int startId = start.getId();
	for (int i = 0; i < MAX_STATE; i++)
		T.a[startId][i] = dp[(int)str.length() & 1][i];
}

void solve(int testId)
{
	T = Matrix(MAX_STATE, MAX_STATE);
	int len, rep;
	scanf("%d%d", &len, &rep);
	cin >> str;
	for (int i = -4; i <= 4; i++)
	{
		for (int index = 2; index <= 4; index++)
		{
			if (i == 0)
				continue;
			State start = State(i, index);
			getEndState(start);
		}
	}
	T = myPow(T, rep);
	if (T.a[State(1, 2).getId()][State(4, 4).getId()])
		printf("Case #%d: YES\n", testId);
	else
		printf("Case #%d: NO\n", testId);
}

int main()
{
	int testCnt;
	scanf("%d", &testCnt);
	for (int i = 1; i <= testCnt; i++)
		solve(i);
	return 0;
}
