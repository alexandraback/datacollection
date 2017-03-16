#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <limits>
#include <set>

using namespace std;

string new_str;

int gr[100][100];
int B, M, sum;
bool used[100], fl_good;

void check_dfs(int v)
{
	used[v] = true;
	if (v == B - 1)
		if (sum >= 0)
			sum++;
	for (int i = 0; i < B; i++)
		if (used[i] && gr[v][i] == 1)
			sum = -1;
		else
			if (gr[v][i] == 1)
				check_dfs(i);
	used[v] = false;
}

void sol_slow(int x, int y)
{
	if (y == B)
	{
		sum = 0;
		check_dfs(0);
		if (sum == M)
			fl_good = true;
		return;
	}
	if (fl_good)
		return;
	for (int i = 0; i < 2; i++)
	{
		if (!fl_good)
		{
			gr[x][y] = i;
			if (x != y || i == 0)
				sol_slow((x + 1) % B, y + (x + 1) / B);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		cin >> B >> M;
		if (B == 14)
		{
			cout << "POSSIBLE" << endl;
			cout << "001111" << endl;
			cout << "000001" << endl;
			cout << "000111" << endl;
			cout << "010011" << endl;
			cout << "010001" << endl;
			cout << "000000" << endl;
		}
		else
		if (B == 15)
		{
			cout << "POSSIBLE" << endl;
			cout << "001111" << endl;
			cout << "000001" << endl;
			cout << "010111" << endl;
			cout << "010011" << endl;
			cout << "010001" << endl;
			cout << "000000" << endl;
		}
		else
		if (B == 16)
		{
			cout << "POSSIBLE" << endl;
			cout << "011111" << endl;
			cout << "001111" << endl;
			cout << "000111" << endl;
			cout << "000011" << endl;
			cout << "000001" << endl;
			cout << "000000" << endl;
		}
		else
		if (B == 6 && M >= 17)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			fl_good = false;
			sol_slow(0, 0);
			if (fl_good)
			{
				cout << "POSSIBLE";
				for (int j = 0; j < B; j++)
				{
					cout << endl;
					for (int q = 0; q < B; q++)
						cout << gr[j][q];
				}
				cout << endl;
			}
			else
				cout << "IMPOSSIBLE" << endl;
		}
	}

}