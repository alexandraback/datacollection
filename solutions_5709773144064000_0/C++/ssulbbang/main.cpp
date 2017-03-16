#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<double> c, f, x;

void read_data(char* filename)
{
	ifstream fin(filename);
	fin >> n;

	c.resize(n);
	f.resize(n);
	x.resize(n);
	for(int i = 0; i < n; i++)
	{
		fin >> c[i] >> f[i] >> x[i];
	}
	fin.close();
}

void process()
{
	for(int i = 0; i < n; i++)
	{
		double cur_time = 0;
		double num_farms = 0;
		double min_time = x[i] / 2.0;
		while(cur_time < min_time)
		{
			double end_time;

			cur_time += (c[i] / (2.0 + num_farms * f[i]));
			num_farms++;
			end_time = cur_time + (x[i] / (2.0 + num_farms * f[i]));
			if(end_time < min_time) min_time = end_time;
		}

		printf("Case #%d: %.7lf\n", i + 1, min_time);
	}
}

int main(int argc, char **argv)
{

	read_data(argv[1]);
	process();
}