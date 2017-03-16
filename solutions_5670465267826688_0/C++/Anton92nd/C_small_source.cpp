#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

enum Number {one, i, j, k, mOne, mi, mj, mk};

const Number pro[8][8] = {
		{one, i, j, k, mOne, mi, mj, mk},
		{i, mOne, k, mj, mi, one, mk, j},
		{j, mk, mOne, i, mj, k, one, mi},
		{k, j, mi, mOne, mk, mj, i, one},
		{mOne, mi, mj, mk, one, i, j, k},
		{mi, one, mk, j, i, mOne, k, mj},
		{mj, k, one, mi, j, mk, mOne, i},
		{mk, mj, i, one, k, j, mi, mOne},
};

const int maxLen = 10010;

Number sparse[20][maxLen * 20];

bool check(int l, int r)
{
	Number res = one;
	int len = 20;
	int pos = l;
	while (pos < r)
	{
		while ((r - pos) < (1 << len))
			len--;
		res = pro[res][sparse[len][pos]];
		pos += 1 << len;
	}
	return res == j;
}

Number charToNum(char c)
{
	switch (c)
	{
	case 'i':
		return i;
	case 'j':
		return j;
	case 'k':
		return k;
	default:
		return one;
	}
}

void calcSparseTable(const string& sx)
{
	for (int i1 = 0; i1 < sx.length(); i1++)
	{
		sparse[0][i1] = charToNum(sx[i1]);
	}
	for (int len = 0; (1 << (len + 1)) <= sx.length(); len++)
	{
		for (int pos = 0; pos + (1 << (len + 1)) <= sx.length(); pos++)
		{
			sparse[len + 1][pos] = pro[sparse[len][pos]][sparse[len][pos + (1 << len)]];
		}
	}
}

vector<int> lPos, rPos;

bool solve(const string &s, int len)
{
	lPos.clear();
	rPos.clear();
	Number p = one;
	for (int i1 = 0; i1 < min((int)s.length(), len * 4); i1++)
	{
		Number cur = charToNum(s[i1]);
		p = pro[p][cur];
		if (p == i)
		{
			lPos.push_back(i1);
		}
	}
	p = one;
	for (int i1 = s.length() - 1; i1 >= max(0, (int)s.length() - len * 4); i1--)
	{
		Number cur = charToNum(s[i1]);
		p = pro[cur][p];
		if (p == k)
		{
			rPos.push_back(i1);
		}
	}
	for (int i1 = 0; i1 < lPos.size(); i1++)
	{
		int curL = lPos[i1] + 1;
		for (int j1 = 0; j1 < rPos.size() && rPos[j1] - 1 >= curL; j1++)
		{
			int curR = rPos[j1];
			if (check(curL, curR))
			{
				return true;
			}
		}
	}
	return false;
}

long long x;
char s1[maxLen];
string s, sx;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		memset(s1, 0, sizeof(s1));
		int m;
		scanf("%d%d\n%s\n", &m, &x, s1);
		s = s1;
		if (12 + (x % 4) < x)
		{
			x = 12 + (x % 4);
		}
		sx.clear();
		for (int i1 = 0; i1 < x; i1++)
		{
			sx.append(s);
		}
		calcSparseTable(sx);
		printf("Case #%d: %s\n", q + 1, solve(sx, s.length()) ? "YES" : "NO");
	}
	return 0;
}
