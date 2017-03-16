#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	int t;
	int i, r;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	fin >> t;
	int x, y, m;
	int used, left;
	char map[50][50];

	for (int test = 0; test < t; test++)
	{
		fin >> x >> y >> m;
		used = 0;
		left = 0;

		for (i = 0; i < x; i++)
			for (r = 0; r < y; r++)
				map[i][r] = '.';
		map[0][0] = 'c';


		if (m >= x * y)
		{
			left = 1;
		}
		else if (m == 0)
		{
			left = 0;
		}
		else if (m == x * y - 1) // special case 1
		{
			for (i = 0; i < x; i++)
				for (r = 0; r < y; r++)
				{
					if (i == 0 && r == 0) continue;
					map[i][r] = '*';
				}
		}
		else if (x == 1 || y == 1) // special case 2
		{
			left = m;
			if (m >= x * y)
				left = 1;
			else {
				for (i = x - 1; i >= 0; i--)
				{
					for (r = y - 1; r >= 0; r--)
					{
						if (i == 0 && r == 0) continue;
						map[i][r] = '*';
						left--;
						if (left == 0) break;
					}
					if (left == 0) break;
				}
			}
		} 
		else if (x == 2 || y == 2) // special case 3
		{
			left = m;
			if (m % 2 != 0 || m > (x * y - 4))
			{
				left = 1;
			}
			else {
				if (x == 2)
				{
					for (i = y - 1; i >= 0; i--)
					{
						map[0][i] = '*';
						map[1][i] = '*';
						left -= 2;
						if (left == 0) break;
					}
				}
				else {
					for (i = x - 1; i >= 0; i--)
					{
						map[i][0] = '*';
						map[i][1] = '*';
						left -= 2;
						if (left == 0) break;
					}
				}
			}
		}
		else {
			int qx = x - 2;
			int qy = y - 2;
			if (m <= qx * qy)
			{
				for (i = x - 1; i > 1; i--)
				{
					for (r = y - 1; r > 1; r--)
					{
						map[i][r] = '*';
						used++;
						if (used == m)
							break;
					}
					if (used == m)
						break;
				}
			}
			else {
				for (i = x - 1; i > 1; i--)
					for (r = y - 1; r > 1; r--)
					{
						map[i][r] = '*';
						used++;
					}
				left = m - used;

				if (left > (qx - 1) * 2)
				{
					for (i = x - 1; i > 2; i--)
					{
						map[i][0] = '*';
						map[i][1] = '*';
						left -= 2;
					}
				}
				else {
					for (i = x - 1; i > 2; i--)
					{
						map[i][0] = '*';
						map[i][1] = '*';
						left -= 2;
						if (left <= 0)
							break;
					}
					if (left < 0)
					{
						map[2][2] = '.';
						left++;
					}
				}
				
				if (left >(qy - 1) * 2)
				{
					for (i = y - 1; i > 2; i--)
					{
						map[0][i] = '*';
						map[1][i] = '*';
						left -= 2;
					}
				}
				else if (left > 0) {
					
					for (i = y - 1; i > 2; i--)
					{
						map[0][i] = '*';
						map[1][i] = '*';
						left -= 2;
						if (left <= 0)
							break;
					}
					if (left < 0)
					{
						map[2][2] = '.';
						left++;
					}
				}

				if (left >= 2)
				{
					map[0][2] = '*';
					map[1][2] = '*';
					left -= 2;
				}
				if (left >= 2)
				{
					map[2][0] = '*';
					map[2][1] = '*';
					left -= 2;
				}
				if (left == 3)
				{
					map[1][0] = '*';
					map[0][1] = '*';
					map[1][1] = '*';
					left = 0;
				}
			}
		}


		fout << "Case #" << (test + 1) << ":" << endl;
		if (left > 0)
			fout << "Impossible" << endl;
		else {
			for (i = 0; i < x; i++)
			{
				for (r = 0; r < y; r++)
				{
					fout << map[i][r];
				}
				fout << endl;
			}
		}
	}

	return 0;
}