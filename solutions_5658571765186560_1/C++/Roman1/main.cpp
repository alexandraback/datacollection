#include <algorithm>
#include <cassert>
#include <fstream>
#include <math.h>
#include <vector>

#define MAX_P 1000

int
main(int argc, char **argv)
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		out << "Case #" << t << ": ";

		int X, R, C;

		in >> X >> R >> C;

		bool win = false;

		if (X >= C + 2 || X >= R + 2)
		{
			win = true;
		}
		else if ((X > R * C) ||(R * C) % X != 0)
		{
			win = true;
		}

		out << (win ? "RICHARD" : "GABRIEL") << std::endl;
	}

	in.close();
	out.close();

	return 0;
}