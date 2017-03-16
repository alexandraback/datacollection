// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

typedef std::pair<int, int> Point;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream in("B.in");

	int T;
	in >> T;

	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		int X, Y;
		in >> X >> Y;


		std::vector<Point> wave;
		std::map<Point, Point> g;
		
		Point F(X, Y);
		wave.push_back(Point(0, 0));

		int step = 1;
		while (!wave.empty())
		{
			std::vector<Point> newWave;

			for (int i = 0; i < wave.size(); ++i)
			{
				Point p = wave[i];

				Point d[] = { Point(p.first + step, p.second), Point(p.first - step, p.second), Point(p.first, p.second + step), Point(p.first, p.second - step) };
				for (int k = 0; k < 4; ++k)
				{
					if (g.find(d[k]) == g.end())
					{
						g[d[k]] = p;
						if (d[k] == F) 
						{
							newWave.clear();
							wave.clear();
							break;
						}

						newWave.push_back(d[k]);
					}
				}
			}
			wave = newWave;
			step += 1;
		}

		std::string r;
		while (F != Point(0, 0))
		{
			Point p = g[F];
			if (p.first != F.first)
				r += p.first > F.first ? 'W' : 'E';
			else
				r += p.second > F.second ? 'S' : 'N';
			F = p;
		}
		std::reverse(r.begin(), r.end());


		std::cout << "Case #" << testNumber << ": " << r << "\n";

	}

	return 0;
}

