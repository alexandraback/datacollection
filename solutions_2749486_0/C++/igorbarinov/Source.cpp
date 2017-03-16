#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("file.in");
ofstream fout("file.out");

int map[1000][1000];
int from[1000][1000];

int main()
{
	int t;
	fin >> t;
	int i;
	int x, y;
	char result[500];

	for (i = 0; i < t; i++)
	{
		fin >> x >> y;

		// x
		int pos = 0;
		int step = 1;
		int rpos = 0;
		if (x < 0) step = -1;
		while (pos != x)
		{
			pos += step;
			if (step > 0)
			{
				result[rpos] = 'E';
				step++;
			}
			if (step < 0)
			{
				result[rpos] = 'W';
				step--;
			}
			step = -step;
			rpos ++;
		}
		pos = 0;
		if (y > 0 && step > 0)
			step = -step;
		if (y < 0 && step < 0)
			step = -step;

		while (pos != y)
		{
			pos += step;
			if (step > 0)
			{
				result[rpos] = 'N';
				step++;
			}
			if (step < 0)
			{
				result[rpos] = 'S';
				step--;
			}
			step = -step;
			rpos ++;
		}

		result[rpos] = 0;
		fout << "Case #" << (i+1) << ": " << result << endl;
	}
}