#pragma comment(linker, "/STACK:300000000")
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <set>
#include <math.h>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996)

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define MOD 1000000007ull
#define INF 999999999

int mult(int a, int b)
{
	int sign1 = (a < 0) ? -1 : 1;
	int sign2 = (b < 0) ? -1 : 1;
	int sign = sign1 * sign2;
	a = abs(a);
	b = abs(b);
	if (a == 1)
		return sign * b;
	if (b == 1)
		return sign * a;
	if (a == b)
		return -1 * sign;
	if (a == 'i')
	{
		if (b == 'j')
			return sign * 'k';
		else
			return -'j' * sign;
	}
	if (a == 'j')
	{
		if (b == 'i')
			return -'k' * sign;
		else
			return 'i' * sign;
	}
	if (a == 'k')
	{
		if (b == 'i')
			return 'j' * sign;
		else
			return -'i' * sign;
	}
}

int power(int a, int b)
{
	if (b % 4 == 1)
		return a;
	else
	if (b % 4 == 2)
		return mult(a, a);
	else
	if (b % 4 == 3)
		return mult(mult(a, a), a);
	else
		return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int l, x;
		cin >> l >> x;
		string s;
		cin >> s;
		unordered_map< int, vector <int> > m;
		int a = s[0];
		bool flag1 = (a == 'i') ? true : false;
		bool flag2 = false;
		for (int i = 1; i < l; i++)
		{
			a = mult(a, s[i]);
			if (a == 'i')
				flag1 = true;
			if (flag1 && a == 'k')
				flag2 = true;
		}
		if (power(a, x) != -1)
		{
			cout << "Case #" << t + 1 << ": NO" << endl;
			continue;
		}
		if (flag1 && flag2)
		{
			cout << "Case #" << t + 1 << ": YES" << endl;
			continue;
		}
		for (int i = 0; i < min(x - 1, 8); i++)
		{
			for (int j = 0; j < l; j++)
			{
				a = mult(a, s[j]);
				if (a == 'i')
					flag1 = true;
				if (flag1 && a == 'k')
					flag2 = true;
			}
		}
		if (flag1 && flag2)
		{
			cout << "Case #" << t + 1 << ": YES" << endl;
		}
		else
			cout << "Case #" << t + 1 << ": NO" << endl;
	}
	//system("PAUSE");
	return 0;
}