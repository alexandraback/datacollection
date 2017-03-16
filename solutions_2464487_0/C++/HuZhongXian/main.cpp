#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if(a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if(a < b) return a; else return b; }
template <class T> T ABS(T a) { if(a < 0) return -a; else return a; }

#define MAX_STR_NUM 256

using namespace std;
string BigAdd(const string& a, const string& b)
{
	string ret = "";
	int jw = 0;
	int la = a.size(), lb = b.size();
	for (int i = 0; i < MAX(la, lb); ++i)
	{
		int ia = la - i - 1, ib = lb - i - 1;
		int cd =	(ia >= 0 ? a[ia] - '0' : 0) +
					(ib >= 0 ? b[ib] - '0' : 0) +
					jw;
		ret += char((cd % 10) + '0');
		jw = cd / 10;
	}
	if (jw)
	{
		ret += char(jw + '0');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

string BigMulOneDigit(const string& a, int c)
{
	string ret = "";
	int jw = 0;
	int la = a.size();
	for (int i = 0; i < la; ++i)
	{
		int ia = la - i - 1;
		int cd = (a[ia] - '0') * c + jw;
		ret += char((cd % 10) + '0');
		jw = cd / 10;
	}
	if (jw)
	{
		ret += char(jw + '0');
	}
	int len = ret.size();
	while (len > 0 && ret[len - 1] == '0')
	{
		--len;
	}
	ret = ret.substr(0, len);
	reverse(ret.begin(), ret.end());
	return ret;
}

string BigMul(const string& a, const string& b)
{
	string ret = "";
	int jw = 0;
	int lb = b.size();
	for (int i = 0; i < lb; ++i)
	{
		int ib = lb - i - 1;
		ret = BigAdd(ret, BigMulOneDigit(a + string(i, '0'), b[ib] - '0'));
	}
	return ret;
}

bool valLE(const string& a, const string& b)
{
	return a.size() < b.size() ||
		a.size() == b.size() && a <= b;
}

int main(int argc, char* argv[])
{
	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "A-small-attempt0.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T;
	char r[30], t[30], n[30];
	fscanf(input, "%d\n", &T);
	for (int i = 1; i <= T; ++i)
	{
		fscanf(input, "%s %s\n", r, t);

		double tr, tt;
		sscanf(r, "%lf", &tr);
		sscanf(t, "%lf", &tt);
		
		long long tn = (sqrt((2 * tr - 1) * (2 * tr - 1) + 8 * tt) - (2 * tr - 1)) * 0.25;
		bool search = false;
		for (int off = 2; !search && (off >= -2); --off)
		{
			if ((tn + off) >= 0)
			{
				sprintf(n, "%lld", tn + off);
				string useArea = BigAdd(BigMul(BigMul("2", n), n), BigMul(BigMul("2", r), n));
				if (valLE(useArea, BigAdd(t, n)))
				{
					fprintf(output, "Case #%d: %lld\n", i, tn + off);
					search = true;
				}
			}
		}
		if (!search)
		{
			fprintf(output, "Case #%d: %lld\n", i, tn);
		}
	}

	fclose(output);
	fclose(input);

	//system("pause");
	return 0;
}
