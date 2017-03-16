#include <iostream>
#include <stdio.h>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <string.h>
#include <stack>
#include <ctime>
#include <sstream>
#include <typeinfo>
#include <functional>
#include <unordered_map>
using namespace std;

struct file_opener
{
	FILE *in, *out;
	file_opener(string file_name)
	{
		in = freopen((file_name + ".in").c_str(), "r", stdin);
		out = freopen((file_name + ".out").c_str(), "w", stdout);
	}
	file_opener(string input_file, string output_file)
	{
		in = freopen((input_file + ".txt").c_str(), "r", stdin);
		out = freopen((output_file + ".txt").c_str(), "w", stdout);
	}
	~file_opener()
	{
		fflush(out);
		fclose(in);
		fclose(out);
	}
};
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forin(n) for (int i = 0; i < (int)n; i++)
#define foro(i, x, n) for(int i = (int)x; i <= (int)n; i++)
#define forit(i, n) for (auto i = (n).begin(); i != (n).end(); i++)
#define fori(i, n) for (int i = 0; i < (int)n; i++)
#define for_col(i, n) for (auto i : n)
#define m_p(x, y) make_pair(x, y)
typedef long double ldb;
typedef long long llg;

int multiply(int ch1, int ch2)
{
	bool negate = (ch1 < 0) ^ (ch2 < 0);
	ch1 = abs(ch1);
	ch2 = abs(ch2);
	int res = 0;
	if (ch1 == 1)
	{
		if (ch2 == 1)
			res = 1;
		else if (ch2 == 2)
			res = 2;
		else if (ch2 == 3)
			res = 3;
		else 
			res = 4;
	}
	else if (ch1 == 2)
	{
		if (ch2 == 1)
			res = 2;
		else if (ch2 == 2)
			res = -1;
		else if (ch2 == 3)
			res = 4;
		else
			res = -3;
	}
	else if (ch1 == 3)
	{
		if (ch2 == 1)
			res = 3;
		else if (ch2 == 2)
			res = -4;
		else if (ch2 == 3)
			res = -1;
		else
			res = 2;
	}
	else
	{
		if (ch2 == 1)
			res = 4;
		else if (ch2 == 2)
			res = 3;
		else if (ch2 == 3)
			res = -2;
		else
			res = -1;
	}
	if (negate)
		res *= -1;
	return res;
}

int main()
{
#ifdef LOCAL
	file_opener File_closer("input", "output");
#else
	file_opener File_closer("input", "output");
#endif
	cout.setf(cout.fixed);
	cout.precision(10);
	//ios_base::sync_with_stdio(false);
	//------------------------------------------------------------

	int t, l, x, len;
	string s, p;
	cin >> t;
	int res, cur, tcur;
	fori(z, t)
	{
		cin >> l >> x >> s;
		p = "";
		fori(i, l)
			s[i] -= 'g';
		fori(i, x)
			p += s;
		len = l * x;
		res = 1;
		cur = 0;
		for (int i = 0; i < len; i++)
		{
			res = multiply(res, p[i]);
			if (res == 2)
			{
				cur = i + 1;
				res = 1;
				break;
			}
		}
		if (cur == 0)
		{
			cout << "Case #" << z + 1 << ": NO" << endl;
			continue;
		}
		tcur = 0;
		for (int i = cur; i < len; i++)
		{
			res = multiply(res, p[i]);
			if (res == 3)
			{
				tcur = i + 1;
				res = 1;
				break;
			}
		}
		if (tcur == 0)
		{
			cout << "Case #" << z + 1 << ": NO" << endl;
			continue;
		}
		for (int i = tcur; i < len; i++)
			res = multiply(res, p[i]);
		if (res == 4)
			cout << "Case #" << z + 1 << ": YES" << endl;
		else
			cout << "Case #" << z + 1 << ": NO" << endl;
	}


	//------------------------------------------------------------
	return 0;
}