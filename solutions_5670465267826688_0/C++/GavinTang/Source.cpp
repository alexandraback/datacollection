#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int T;
int L, X;
char s[10005];
int a[10005];
int c[10005];
int d[10005];

int m[5][5] = { 0, 0, 0, 0, 0,
				0, 1, 2, 3, 4,
				0, 2, -1, 4, -3,
				0, 3, -4, -1, 2,
				0, 4, 3, -2, -1 };

void trans(int length)
{
	for (int i = 0; i < length; i++)
	{
		if (s[i] == 'i')
			a[i] = 2;
		else if (s[i] == 'j')
			a[i] = 3;
		else a[i] = 4;
	}
}

int sig(int a)
{
	if (a > 0)
		return 1;
	else return -1;
}

int mul(int a, int b)
{
	return	sig(a) * sig(b) * m[abs(a)][abs(b)];
}

void init(int L)
{
	trans(L);
	int res = 1;
	for (int i = 0; i < L; i++)
	{
		res = mul(res, a[i]);
		c[i] = res;
	}
	res = 1;
	for (int i = L - 1; i >= 0; i--)
	{
		res = mul(a[i], res);
		d[i] = res;
	}
}

int get_result(int L, int X)
{
	init(L);
	int mm = c[L-1];
	int index_i = 1E8, index_k = 1E8;
	if (mm == 1)
		return 0;
	else if (mm == -1 && X % 2 != 1)
		return 0;
	else if (mm != -1 && X % 4 != 2)
		return 0;
	for (int i = 0; i < L; i++)
	{
		if (c[i] == 2)
			index_i = min(i + 1, index_i);
		if (mul(mm, c[i]) == 2)
			index_i = min(i + L + 1, index_i);
		if (mul(mm, mul(mm, c[i])) == 2)
			index_i = min(i + 2 * L + 1, index_i);
		if (mul(mm, mul(mm, mul(mm, c[i]))) == 2)
			index_i = min(i + 3 * L + 1, index_i);
	}
	for (int i = L - 1; i >= 0; i--)
	{
		if (d[i] == 4)
			index_k = min(L - i, index_k);
		if (mul(d[i], mm) == 4)
			index_k = min(2 * L - i, index_k);
		if (mul(mul(d[i], mm), mm) == 4)
			index_k = min(3 * L - i, index_k);
		if (mul(mul(mul(d[i], mm), mm), mm) == 4)
			index_k = min(4 * L - i, index_k);
	}
	if (index_i + index_k <= L * X)
		return 1;
	return 0;
}

int main()
{
	ifstream ifile;
	ofstream ofile;
	ifile.open("C-small-attempt1.in");
	ofile.open("output.txt");

	ifile >> T;
	int casenum = 0;
	while (casenum < T)
	{
		casenum++;
		ifile >> L >> X;
		ifile >> s;
		if (get_result(L, X))
			ofile << "Case #" << casenum << ": YES" << endl;
		else ofile << "Case #" << casenum << ": NO" << endl;
	}
}