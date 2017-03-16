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

bool IsPalindromes(const char* str, int len)
{
	bool valid = true;
	for (int i = len >> 1; valid && i < len; ++i)
	{
		valid = (str[i] == str[len - i - 1]);
	}
	return valid;
}

bool valLE(const string& a, const string& b)
{
	return a.size() < b.size() ||
		a.size() == b.size() && a <= b;
}

int cntP = 0;
int cntPS = 0;
string palindromes[20000];
string palindromeSquares[100];

int main(int argc, char* argv[])
{
	//printf("%s\n", BigAdd("2823542346", "02934934").c_str());
	//printf("%s\n", BigMulOneDigit("2823542346", 4).c_str());
	//printf("%s\n", BigMul("2823542346", "02934934").c_str());

	for (int i = 1; i < 10000000; ++i)
	{
		char buf[8];
		sprintf(buf, "%d", i);
		if (IsPalindromes(buf, strlen(buf)))
		{
			palindromes[cntP++] = buf;
			//printf("%s\n", buf);
		}
	}

	//printf("\n");

	for (int i = 0; i < cntP; ++i)
	{
		string ps = BigMul(palindromes[i], palindromes[i]);
		if (IsPalindromes(ps.c_str(), ps.size()))
		{
			palindromeSquares[cntPS++] = ps;
			//printf("%s\n", ps.c_str());
		}
	}

	char filename[2][MAX_STR_NUM];
	sprintf(filename[0], "%s", "C-small-attempt1.in");
	sprintf(filename[1], "%s.out", filename[0]);

	FILE* input = fopen(filename[0], "r");
	FILE* output = fopen(filename[1], "w");

	int T;
	char A[101], B[101];
	fscanf(input, "%d\n", &T);
	for(int i = 1; i <= T; ++i)
	{
		fscanf(input, "%s %s\n", A, B);
		int cntA = 0;
		int cntB = 0;
		for (int i = 0; i < cntPS; ++i)
		{
			cntA += valLE(palindromeSquares[i], A);
			if (palindromeSquares[i] == A)
			{
				--cntA;
			}
			cntB += valLE(palindromeSquares[i], B);
		}

		fprintf(output, "Case #%d: %d\n", i, cntB - cntA);
	}

	fclose(output);
	fclose(input);

	system("pause");
	return 0;
}