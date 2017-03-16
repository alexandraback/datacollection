#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

int L;
LL X;
char str[2000000];

int op0[5][5] = 
{
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};

int op[8][8];

int pow[8][4] = 
{
	{0, 0, 0, 0},
	{0, 1, 4, 5}, 
	{0, 2, 4, 6},
	{0, 3, 4, 7},
	{0, 4, 0, 4},
	{0, 5, 4, 1},
	{0, 6, 3, 2},
	{0, 7, 4, 3}
};

int abs(int n)
{
	return n > 0 ? n : -n;
}

int cal(int a, int b)
{
	int ret = op0[abs(a)][abs(b)];
	if (a * b > 0)
		return ret;
	return -ret;
}

bool l1[8], l2[8][8], l3[8][8][8];
bool t1[8], t2[8][8], t3[8][8][8];

void copy1()
{
	int i;
	for (i = 0; i < 8; ++i)
		l1[i] = t1[i];
}

void copy2()
{
	int i, j;
	for (i = 0; i < 8; ++i)
		for (j = 0; j < 8; ++j)
			l2[i][j] = t2[i][j];
}

void copy3()
{
	int i, j, k;
	for (i = 0; i < 8; ++i)
		for (j = 0; j < 8; ++j)
			for (k = 0; k < 8; ++k)
				l3[i][j][k] = t3[i][j][k];
}

int alp(char c)
{
	if (c == 'i')
		return 1;
	if (c == 'j')
		return 2;
	return 3;
}

int id(int n)
{
	if (n > 0)
		return n - 1;
	return 3 - n;
}

int nm(int n)
{
	if (n < 4)
		return n + 1;
	return 3 - n;
}

void gen()
{
	int a, b;
	for (a = 0; a < 8; ++a)
		for (b = 0; b < 8; ++b)
			op[a][b] = id(cal(nm(a), nm(b)));
}

void read()
{
	cin >> L >> X >> str;
	int i, j, k, m;
	memset(l1, 0, sizeof(l1));
	memset(l2, 0, sizeof(l2));
	memset(l3, 0, sizeof(l3));
	l1[0] = true;
	for (m = 0; m < L; ++m)
	{
		int dt = alp(str[m]);
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		memset(t3, 0, sizeof(t3));
		for (i = 0; i < 8; ++i)
			if (l1[i])
				t2[i][dt] = true;
		for (i = 0; i < 8; ++i)
			for (j = 0; j < 8; ++j)
				if (l2[i][j])
					t3[i][j][dt] = true;
		//// new
		for (i = 0; i < 8; ++i)
			if (l1[i])
				t1[op[i][dt]] = true;
		copy1();
		for (i = 0; i < 8; ++i)
			for (j = 0; j < 8; ++j)
				if (l2[i][j])
					t2[i][op[j][dt]] = true;
		copy2();
		for (i = 0; i < 8; ++i)
			for (j = 0; j < 8; ++j)
				for (k = 0; k < 8; ++k)
					if (l3[i][j][k])
						t3[i][j][op[k][dt]] = true;
		copy3();
	}
}

bool subtest1(int dt, int f1, int b1, int f2, int b2, int m1, int m2, int m3)
{
	return 	op[pow[dt][m1]][f1] == 1 &&
		op[op[b1][pow[dt][m2]]][f2] == 2 &&
		op[b2][pow[dt][m3]] == 3;
}

bool test1()
{
	int dt;
	for (int i = 0; i < 8; ++i)
		if (l1[i])
			dt = i;
	LL rest = X - 2;
	int f1, b1, f2, b2, m1, m2, m3;
	for (m1 = 0; m1 < 4; ++m1)
	for (m2 = 0; m2 < 4; ++m2)
	for (m3 = 0; m3 < 4; ++m3)
		if ((m1+m2+m3) <= rest && (m1+m2+m3)%4 == rest%4)
		for (f1 = 0; f1 < 8; ++f1)
		for (b1 = 0; b1 < 8; ++b1)
			if (l2[f1][b1])
			for (f2 = 0; f2 < 8; ++f2)
			for (b2 = 0; b2 < 8; ++b2)
				if (l2[f2][b2])
				if (subtest1(dt,f1,b1,f2,b2,m1,m2,m3))
					return true;
	return false;
}

bool subtest2(int dt, int f, int b, int m1, int m2)
{
	return op[pow[dt][m1]][f] == 1 && op[b][pow[dt][m2]] == 3;
}

bool test2()
{
	int dt;
	for (int i = 0; i < 8; ++i)
		if (l1[i])
			dt = i;
	LL rest = X - 1;
	int f, b, m1, m2;
	for (m1 = 0; m1 < 4; ++m1)
	for (m2 = 0; m2 < 4; ++m2)
		if ((m1+m2) <= rest && (m1+m2)%4 == rest%4)
		for (f = 0; f < 8; ++f)
		for (b = 0; b < 8; ++b)
			if (l3[f][2][b])
			if (subtest2(dt,f,b,m1,m2))
				return true;
	return false;
}

int main()
{
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	
	int T;
	cin >> T;
	gen();
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		read();
		if (test1() || test2())
			printf("Case #%d: YES\n", case_num);
		else
			printf("Case #%d: NO\n", case_num);
	}
	
	return 0;
}

