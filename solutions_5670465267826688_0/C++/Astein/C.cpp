#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// -1, -i, -j, -k, 1, i, j, k
int mat[8][8] = {
	{ 4, 5, 6, 7, 0, 1, 2, 3 },
	{ 5, 0, 7, 2, 1, 4, 3, 6 },
	{ 6, 3, 0, 5, 2, 7, 4, 1 },
	{ 7, 6, 1, 0, 3, 2, 5, 4 },
	{ 0, 1, 2, 3, 4, 5, 6, 7 },
	{ 1, 4, 3, 6, 5, 0, 7, 2 },
	{ 2, 7, 4, 1, 6, 3, 0, 5 },
	{ 3, 2, 5, 4, 7, 6, 1, 0 } };

string calc(string s, int X)
{
	int n = s.size();

	vector<int> v(n, 0);
	vector<int> left(n, 0);
	vector<int> right(n + 1, 0);
	for (int i = 0; i < n; ++i)
		v[i] = s[i] - 'i' + 5;

	int pat;
	// precalc
	{
		pat = 4;
		for (int i = 0; i < n; ++i)
			pat = mat[pat][v[i]];

		int state;
		// left
		state = 4;
		for (int i = 0; i < n; ++i)
		{
			state = mat[state][v[i]];
			left[i] = state;
		}

		state = 4;
		// right
		for (int i = n - 1; i >= 0; --i)
		{
			state = mat[v[i]][state];
			right[i] = state;
		}
		right[n] = 4;
	}

	int cycle = 4;
	if (pat == 4) cycle = 1;
	if (pat == 0) cycle = 2;

	/// brute
	int x, y;
	bool found_x, found_y;

	int lpat = 4;
	for (int a = 0; a < cycle; ++a)
	{
		found_x = false;
		for (x = 0; x < n; ++x)
		{
			if (mat[lpat][left[x]] == 5)
			{
				found_x = true;
				break;
			}
		}

		if (found_x)
		{
			int rpat = 4;
			for (int c = 0; c < cycle; ++c)
			{
				found_y = false;
				for (y = n - 1; y >= 0; --y)
				{
					if (mat[right[y + 1]][rpat] == 7)
					{
						found_y = true;
						break;
					}
				}
				if (found_y)
				{
					if (x + 1 <= y)
					{
						// left
						int mpat = 4;
						for (int i = x + 1; i <= y; ++i)
						{
							mpat = mat[mpat][v[i]];
						}
						int ypat = 4;
						for (int i = y + 1; i < n; ++i) ypat = mat[ypat][v[i]];
						for (int i = 0; i < y + 1; ++i) ypat = mat[ypat][v[i]];
						for (int b = 0; b < cycle; ++b)
						{
							if (mpat == 6)
							{
								if (a + b + c <= X - 1 && (X - 1 - (a + b + c)) % cycle == 0) return "Yes";
							}
							mpat = mat[mpat][ypat];
						}
					}
					else
					{
						int mpat = 4;
						for (int b = 0; b < cycle; ++b)
						{
							if (mat[mat[right[x + 1]][mpat]][left[y]] == 6)
							{
								if (a + b + c <= X - 2 && (X - 2 - (a + b + c)) % cycle == 0) return "Yes";
							}
							mpat = mat[mpat][pat];
						}
					}
				}
				rpat = mat[rpat][pat];
			}
		}
		lpat = mat[lpat][pat];
	}
	return "No";
}

int main(int argc, char** argv)
{
	if (argc == 3)
	{
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn)
	{
		int L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		string ret = calc(s, X);
		printf("Case #%d: %s\n", cn, ret.c_str());
	}
	return 0;
}
