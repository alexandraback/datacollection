#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

int get_min_diamond(int row, int col, int k)
{
	if(row <= 2 || col <= 2) return k;

	int sum = 0;
	int sol = -1;
	for(int v = 0; v < (row / 2.0); v++)
	{
		if(v >= (col / 2.0)) break;
		sum += v;

		int total = row * col;


		for(int i = 0; i <= 4; i++)
		{
			if(total - sum * i >= k)
			{
				int new_sol = (2 * col) + (2 * (row - 2)) - i * v;
				if(sol == -1 || new_sol < sol)
				{
					sol = new_sol;
				}
			}
		}
	}

	return sol;
}


int main(int argc, char** argv)
{
	int T;

	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int n, m, k;
		cin >> n >> m >> k;

		int min_sol = -1;
		for(int row = 1; row <= n; row++)
		{
			for(int col = 1; col <= m; col++)
			{
				if(row * col < k) continue;
				int candidate = get_min_diamond(row, col, k);
				//cout << row << "\t" << col << "\t" << k << "\t" << candidate << endl;
				if(min_sol == -1 || min_sol > candidate)
				{
					min_sol = candidate;
				}
			}
		}
		cout << "Case #" << i << ": " << min_sol << endl;
		//cout << n << "\t" << m << "\t" << k << "\t|\t" << min_sol << endl;
	}
	return 0;
}