#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
using namespace std;

enum Multiplier {
	ONE = 0,
	I,
	J,
	K
};

int M[4][4] = { 
	{ 0, 1, 2, 3 },
	{ 1, 0, 3, 2 },
	{ 2, 3, 0, 1 },
	{ 3, 2, 1, 0 }
};

int Sign[4][4] = {
	{ 1, 1, 1, 1 },
	{ 1, -1, 1, -1 },
	{ 1, -1, -1, 1 },
	{ 1, 1, -1, -1 }
};

map<char, int> Convert = {
	{ 'i', 1 },
	{ 'j', 2 },
	{ 'k', 3 },
};

void Solve()
{
	int L, X;
	cin >> L >> X;
	string s;
	cin >> s;
	string bigs;
	bigs.reserve(L * X);
	for (int i = 0; i < X; ++i)
	{
		bigs += s;
	}
	vector<bool> canI(L * X, false);
	{
		int sign = 1;
		int current = 0;
		for (int i = 0; i < L * X; ++i)
		{
			int symbol = Convert[bigs[i]];
			int prev = current;
			current = M[prev][symbol];
			sign = sign * Sign[prev][symbol];
			canI[i] = (current == 1 && sign == 1);
			//cout << canI[i];
		}
	}
	//cout << " ";
	vector<bool> canIJ(L * X, false);
	{
		for (int i = 0; i < L * X; ++i)
		{
			if (canI[i])
			{
				int sign = 1;
				int current = 0;
				for (int j = i + 1; j < L * X; ++j)
				{
					int symbol = Convert[bigs[j]];
					int prev = current;
					current = M[prev][symbol];
					sign = sign * Sign[prev][symbol];
					canIJ[j] = canIJ[j] || (current == 2 && sign == 1);
				}
			}
			//cout << canIJ[i];
		}
	}
	//cout << " ";
	vector<bool> canIJK(L * X, false);
	{
		for (int i = 0; i < L * X; ++i)
		{
			if (canIJ[i])
			{
				int sign = 1;
				int current = 0;
				for (int j = i + 1; j < L * X; ++j)
				{
					int symbol = Convert[bigs[j]];
					int prev = current;
					current = M[prev][symbol];
					sign = sign * Sign[prev][symbol];
					canIJK[j] = canIJK[j] || (current == 3 && sign == 1);
				}
			}
			//cout << canIJK[i];
		}
	}
	//cout << " ";
	cout << (canIJK[L * X - 1] ? "YES" : "NO");
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}