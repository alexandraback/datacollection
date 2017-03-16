#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int t;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	double farmcost;
	double farmspeed;
	double total;

	fout.precision(7);
	fin >> t;
	for (int test = 0; test < t; test++)
	{
		double farmtime = 0;
		double speed = 2;
		double mintime = 0;
		double time;

		fin >> farmcost >> farmspeed >> total;
		mintime = total / speed;
		while (1)
		{
			farmtime += farmcost / speed;
			speed += farmspeed;
			time = farmtime + total / speed;
			if (time > mintime)
				break;
			else
				mintime = time;
		}

		fout << "Case #" << (test + 1) << ": " << fixed << mintime << endl;
	}
}