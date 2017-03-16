
#include <iostream>

using namespace std;

const int MAX = 50;

struct field
{
	int r, c;
	char data[MAX*MAX];

	char get(int i, int j)
	{
		if (i < 0 || j < 0 || i >= r || j >= c) return -1;
		return data[i*MAX + j];
	}

	void set(int i, int j, char c)
	{
		if (i < 0 || j < 0 || i >= r || j >= c) return;
		data[i*MAX + j] = c;
	}

	void setcol(int j, char c)
	{
		if (j < 0 || j >= c) return;
		for (int i = 0; i < r; i++) data[i*MAX + j] = c;
	}

	field* transpose()
	{
		swap(r, c);
		for (int i = 0; i < MAX-1; i++)
		for (int j = i+1; j < MAX; j++)
		{
			swap(data[i*MAX + j], data[j*MAX + i]);
		}
		return this;
	}

	void print()
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << get(i, j);
			}
			cout << endl;
		}
	}

	field(int _r, int _c)
	{
		r = _r;
		c = _c;

		for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			set(i, j, 'N');
		}
	}
};

field* fill1(int c, int m)
{
	int e = c - m;

	field *f = new field(1, c);
	f->set(0, 0, 'c');
	for (int i = 1; i < e; i++) f->set(0, i, '.');
	for (int i = e; i < c; i++) f->set(0, i, '*');
	return f;
}

field* fill2(field *fi, int c, int m)
{
	int e = 2*c - m;
	if (e > 1 && e < 4) return 0;
	if (e > 1 && e % 2 == 1) return 0;

	field *f = fi;
	if (f == 0) f = new field(2, c);
	f->set(0, 0, 'c');

	int b = e/2;
	if (e == 1)
	{
		f->set(1, 0, '*');
		b = 1;
	} else
	{
		f->set(1, 0, '.');
	}

	for (int i = 1; i < b; i++) f->setcol(i, '.');
	for (int i = b; i < c; i++) f->setcol(i, '*');
	return f;
}

field* fill(field *fi, int r, int c, int m)
{
	if (r > c)
	{
		field *res = fill(0, c, r, m);
		return (res == 0) ? 0 : res->transpose();
	}

	if (r == 1) return fill1(c, m);
	if (r == 2) return fill2(0, c, m);

	int e = r*c - m;
	if (e == 2 || e == 3 || e == 5 || e == 7) return 0;

	field *f = fi;
	if (f == 0) f = new field(r, c);
	f->set(0, 0, 'c');

	int b;
	if (e == 1)
	{
		for (int i = 1; i < r; i++) f->set(i, 0, '*');
		b = 1;
	} else if (e == 4)
	{
		f->set(1, 0, '.');
		f->set(0, 1, '.');
		f->set(1, 1, '.');
		for (int i = 2; i < r; i++)
		{
			f->set(i, 0, '*');
			f->set(i, 1, '*');
		}
		b = 2;
	} else if (e == 6)
	{
		f->set(1, 0, '.');
		f->set(2, 0, '.');
		f->set(0, 1, '.');
		f->set(1, 1, '.');
		f->set(2, 1, '.');
		for (int i = 3; i < r; i++)
		{
			f->set(i, 0, '*');
			f->set(i, 1, '*');
		}
		b = 2;
	} else if (r > 3 && e <= 3*c)
	{
		f->r = 3;
		fill(f, 3, c, 3*c - e);
		f->r = r;

		for (int i = 3; i < r; i++) for (int j = 0; j < c; j++) f->set(i, j, '*');
		return f;
	} else
	{
		b = e/r;
		int m = e%r;

		for (int i = 1; i < r; i++) f->set(i, 0, '.');
		for (int i = 1; i < b; i++) f->setcol(i, '.');

		if (m == 1)
		{
			for (int i = 0; i < m+1; i++) f->set(i, b, '.');
			for (int i = m+1; i < r; i++) f->set(i, b, '*');

			f->set(r-1, b-1, '*');
		} else
		{
			for (int i = 0; i < m; i++) f->set(i, b, '.');
			for (int i = m; i < r; i++) f->set(i, b, '*');
		}

		b++;
	}

	for (int i = b; i < c; i++) f->setcol(i, '*');
	return f;
}

int main()
{
	int T, C, R, M;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> C >> R >> M;
		cout << "Case #" << (t+1) << ":" << endl;
		field *f = fill(0, C, R, M);
		if (f == 0)
		{
			cout << "Impossible" << endl;
		} else
		{
			f->print();
			delete f;
		}
	}

	return 0;
}


