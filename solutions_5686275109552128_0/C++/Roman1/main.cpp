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
	for (int t = 0; t < T; t++)
	{
		out << "Case #" << (t + 1) << ": ";

		int D;
		in >> D;

		std::vector<int> plates (MAX_P + 1);
		int max_cakes = 0;
		for (int i = 0; i < D; i++)
		{
			int cakes;
			in >> cakes;

			max_cakes = std::max(max_cakes, cakes);

			plates[cakes]++;
		}

		int min = max_cakes;
		int steps = 0;

		for (int i = max_cakes; i > 1; i--)
		{
			if (i > 3)
			{
				int s = (int)(sqrt(i));

				steps += plates[i] * (s - 1);
				plates[i / s] += plates[i] * (s - 1);
				plates[i - i / s] += plates[i];
				plates[i] = 0;
			}
			else if (plates[i] != 0)
			{
				break;
			}

			if (steps + i - 1 < min)
			{
				min = steps + i - 1;
			}
		}

		out << min << std::endl;
	}

	in.close();
	out.close();

	return 0;
}