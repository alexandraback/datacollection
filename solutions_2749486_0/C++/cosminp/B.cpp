#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

fstream 	f, g;
long long	x, y;

string solve_small(long long x, long long y)
{
	string s = "";
	string sx = (x > 0) ? "WE" : "EW";
	string sy = (y > 0) ? "SN" : "NS";

	if (x < 0) x = -x;
	if (y < 0) y = -y;

	for (int i = 0; i < x; i++)
	{
		s = s + sx;
	}

	for (int i = 0; i < y; i++)
	{
		s = s + sy;
	}

	return s;
}


int main()
{
	int	T;
	f.open("in.txt",  ios :: in);
	g.open("out.txt", ios :: out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> x >> y;
		g << "Case #" << test << ": " << solve_small(x, y) << endl;
	}

	f.close();
	g.close();

	return 0;
}
