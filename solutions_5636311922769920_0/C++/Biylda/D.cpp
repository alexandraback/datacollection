#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

typedef unsigned long long ULL;

string fractal(string &base, string &gold, int C)
{
	string s = base;
	for (int i = 1; i < C; ++i)
	{
		string r = "";
		for (string::iterator it = s.begin(); it != s.end(); ++it)
		{
			if (*it == '1')
				r += gold;
			else
				r += base;
		}
		s = r;
	}
	return s;
}

string fractal(string &base, int C)
{
	string gold = "";
	for (string::iterator it = base.begin(); it != base.end(); ++it)
	{
		gold += '1';
	}
	return fractal(base, gold, C);
}

string binary(int x, int K)
{
	string bin = "";
	for (; K > 0; --K)
	{
		bin += '0' + ((x >> (K-1)) & 1);
	}
	return bin;
}

int main(int argc, char **argv)
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);
		//for (int i = (1<<K)-1; i >= 0; --i)
		//{
		//	string bin = binary(i, K);
		//	cout << bin << " ";
		//	cout << fractal(bin, C) << endl;
		//}
		printf("Case #%d: ", t+1);
		ULL mul = 1;
		for (int i = 1; i < C; ++i)
			mul *= K;
		for (int i = 0; i < K; ++i)
			printf("%llu%c", i * mul + 1, i == K-1 ? '\n' : ' ');
	}
	return 0;
}
