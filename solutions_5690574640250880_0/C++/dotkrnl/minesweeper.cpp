#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int mx[] = {-1, 0, 1, 1, 1, 0, -1, -1}, my[] = {-1, -1, -1, 0, 1, 1, 1, 0};

typedef vector<vector<char> > rect;

const rect nil;

inline int getMin(int x, int y)
{
	return x < y ? x : y;
}

inline int getMax(int x, int y)
{
	return x > y ? x : y;
}

void init(rect &a, int r, int c)
{
	a.resize(r);
	for(int i = 0; i < r; ++i)
	{
		a[i].resize(c);
		fill(a[i].begin(), a[i].end(), '*');
	}
}

void init(rect &a, int r, int c, char ch)
{
	a.resize(r);
	for(int i = 0; i < r; ++i)
	{
		a[i].resize(c);
		fill(a[i].begin(), a[i].end(), ch);
	}
}

rect transpose(const rect &a, int r, int c)
{
	rect ret;
	init(ret, c, r);
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			ret[j][i] = a[i][j];
	return ret;
}

void sweep(rect &a, int r, int c)
{/*
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
		{
			if(a[i][j] == '.')
			{
				a[i][j] = '0';
				for(int k = 0; k < 8; ++k)
				{
					int tx = i + mx[k], ty = j + my[k];
					if(0 <= tx && tx < r && 0 <= ty && ty < c && a[tx][ty] == '*')
						++a[i][j];
				}
			}
		}*/
}

rect work(int r, int c, int m)
{
	int last = r * c - m;

	if(last <= 0)
		return nil;
	if(last == 1)
	{
		rect ret;
		init(ret, r, c);
		ret[0][0] = 'c';
		return ret;
	}
	if(r == 1 || c == 1)
	{
		if(r == 1)
		{
			rect ret;
			init(ret, r, c);
			ret[0][0] = 'c';
			for(int i = 1; i < last; ++i)
				ret[0][i] = '.';
			for(int i = last; i < c; ++i)
				ret[0][i] = '*';
			return ret;
		}
		if(c == 1)
		{
			rect ret;
			init(ret, r, c);
			ret[0][0] = 'c';
			for(int i = 1; i < last; ++i)
				ret[i][0] = '.';
			for(int i = last; i < c; ++i)
				ret[i][0] = '*';
			return ret;
		}
	}
	if(r == 2 || c == 2)
	{
		if(last < 4 || last & 1)
			return nil;
		rect ret;
		int _r, _c;
		if(r == 2)
		{
			_r = r;
			_c = c;
		}
		else
		{
			_r = c;
			_c = r;
		}
		init(ret, _r, _c);
		for(int i = 0; i < last; ++i)
			ret[i % 2][i / 2] = '.';
		sweep(ret, _r, _c);
		ret[0][0] = 'c';
		if(r == _r)
			return ret;
		else
			return transpose(ret, _r, _c);
	}

	for(int i = 2; i <= last / 2; ++i)
		if(last % i == 0 && i <= getMin(r, c) && last / i <= getMax(r, c))
		{
			rect ret;
			int _r, _c;
			if(r <= c)
			{
				_r = r;
				_c = c;
			}
			else
			{
				_r = c;
				_c = r;
			}
			init(ret, _r, _c);
			for(int p = 0; p < i; ++p)
				for(int q = 0; q < last / i; ++q)
					ret[p][q] = '.';
			sweep(ret, _r, _c);
			ret[0][0] = 'c';
			if(r == _r)
				return ret;
			else
				return transpose(ret, _r, _c);
		}

	if(last < 8)
		return nil;

	for(int i = 2; i < getMin(r, c); ++i)
	{
		int x = last / (i + 1) + 1;
		if(x <= getMax(r, c) && (last % x >= 2 || (last % x == 1 && last / x > 3) ))
		{
			rect ret;
			int _r, _c;
			if(r <= c)
			{
				_r = r;
				_c = c;
			}
			else
			{
				_r = c;
				_c = r;
			}
			init(ret, _r, _c);
			if(last % x >= 2)
			{
				for(int p = 0; p < i; ++p)
					for(int q = 0; q < x; ++q)
						ret[p][q] = '.';
				for(int q = 0; q < last % x; ++q)
					ret[i][q] = '.';
				sweep(ret, _r, _c);
				ret[0][0] = 'c';
			}
			else
			{
				for(int p = 0; p < i; ++p)
					for(int q = 0; q < x; ++q)
						ret[p][q] = '.';
				ret[0][0] = '*';
				for(int q = 0; q <= last % x; ++q)
					ret[i][q] = '.';
				sweep(ret, _r, _c);
				ret[0][2] = 'c';
			}
			if(r == _r)
				return ret;
			else
				return transpose(ret, _r, _c);
		}
	}

	if(m <= (getMin(r, c) - 2) * (getMin(r, c) - 1) / 2)
	{
		rect ret;
		init(ret, r, c, '.');
		int _m = m;
		ret[0][0] = 'c';
		for(int i = r + c - 2; ; --i)
			for(int j = r - 1; i - j < c; --j)
			{
				ret[j][i - j] = '*';
				if(!--m)
					return ret;
			}
	}

	return nil;
}

void show(rect a, int r, int c)
{
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
			putchar(a[i][j]);
		putchar('\n');
	}
}

int main()
{
	int t;

	freopen("mine.in", "r", stdin);
	freopen("mine.out", "w", stdout);

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		printf("Case #%d:\n", i);
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		rect ret = work(r, c, m);
		if(ret == nil)
			puts("Impossible");
		else
			show(ret, r, c);
	}

	fclose(stdin);
	fclose(stdout);
}
