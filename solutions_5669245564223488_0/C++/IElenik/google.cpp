// google.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "algorithm"
#include "vector"
#include "string"
using namespace std;

FILE * in, * out;
int ri()
{
	int r;
	fscanf(in,"%d", &r);
	return r;
}

__int64 nod(__int64 p, __int64 q)
{
	while (p != 0)
	{
		q = q%p;
		swap(p, q);
	}
	return q;
}

int pt(__int64 q)
{
	int r = 0;
	while (q > 1) { r++; q /= 2; }
	return r;
}

void findrp(vector<string>& cars, vector<int> &o, int p, int & op, int &os)
{
	bool found = false;
	for (int i = 0; i < o.size(); i++)
	{
		for (int j = 0; j < cars[o[i]].size(); j++)
		{
			if (cars[o[i]][j] == p)
				found = true;
			else
			{
				if (found)
				{
					op = i;
					os = j;
					return;
				}
			}
		}
	}
	op = o.size();
	os = 100000;
}

bool canAdd(vector<string>& cars, vector<int> &o, int p)
{
	for (int i = 0; i < o.size(); i++) if (o[i] == p) return false;
	o.push_back(p);
	for (int i = 0; i < cars[p].size(); i++)
	{
		int op, os;
		findrp(cars, o, cars[p][i], op, os);
		if (op < o.size() - 1 || os < i)
		{
			o.pop_back();
			return false;
		}
	}
	o.pop_back();
	return true;
}

int countValid(vector<string>& cars, int pos, vector<int> &o)
{
	if (o.size() == cars.size()) return 1;
	int count = 0;
	for (int i = 0; i < cars.size(); i++)
	{
		if (canAdd(cars, o, i))
		{
			o.push_back(i);
			count += countValid(cars, pos + 1, o);
			o.pop_back();
		}
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	in = fopen("4.in", "rt");
	out = fopen("out.txt", "wt");
	int T = ri();

	for (int tc = 1; tc <= T; tc++)
	{
		int n = ri();
		vector<string> cars;
		printf("%d/%d\r", tc, T);
		for (int i = 0; i < n; i++)
		{
			char str[256];
			char * ptr = str;
			while ((*ptr = getc(in)) == '\n' || ptr[0] == '\r');
			ptr++;
			while (!feof(in) && (*ptr = getc(in)) != ' ' && *ptr != '\n')
			{
				if (ptr[0] != ptr[-1]) ptr++;
			}
			if (feof(in)) ptr++;
			*ptr = 0;

			cars.push_back(str);
		}
		vector<int> o;
		int c = countValid(cars, 0, o);

		fprintf(out, "Case #%d: %d\n", tc, c);
	}

	return 0;
}

