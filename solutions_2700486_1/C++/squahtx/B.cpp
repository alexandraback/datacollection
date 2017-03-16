#include <assert.h>
#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdlib.h>
#include <string>

double choosecache [4096] [4096];

double choose (int n, int r)
{
	if (n < 0) { return 0; }
	if (r < 0) { return 0; }
	if (r > n) { return 0; }

	if (choosecache [n] [r] == 0)
	{
		choosecache [n] [r] = choose (n - 1, r - 1) + choose (n - 1, r);
	}
	return choosecache [n] [r];
}

int main ()
{
	std::ifstream in ("b.in");
	std::ofstream out ("b.out");

	for (unsigned int n = 0; n < 4096; n++)
	{
		for (unsigned int r = 0; r < 4096; r++)
		{
			choosecache [n] [r] = 0;
		}
	}
	choosecache [0] [0] = 1;

	unsigned int testcount;
	in >> testcount;

	for (unsigned int i = 0; i < testcount; i++)
	{
		unsigned int diamondcount;
		in >> diamondcount;
		int x;
		int y;
		in >> x;
		in >> y;

		unsigned int pointmanhattandistance = y;
		if (x < 0) { pointmanhattandistance += -x; }
		else { pointmanhattandistance += x; }

		// Reduce.
		unsigned int triangleside = 1;
		unsigned int layerdiamondcount = triangleside * 2 - 1;
		while (layerdiamondcount <= diamondcount)
		{
			diamondcount -= layerdiamondcount;
			triangleside += 2;
			layerdiamondcount = triangleside * 2 - 1;
		}

		// Last attempt to strip off a layer was unsuccessful
		//   --> last layer side length
		triangleside -= 2;

		// Filled triangle spans from
		// (+/-(triangleside - 1), 0) to (0, triangleside - 1)
		unsigned int filledmanhattandistance = triangleside - 1;

		double p = 0;
		if (pointmanhattandistance <= filledmanhattandistance)
		{
			p = 1;
		}
		else if (pointmanhattandistance > filledmanhattandistance + 2)
		{
			p = 0;
		}
		else
		{
			// layer-being-filled side length
			triangleside += 2;

			// Point lies in the region with trickier-to-calculate diamond probability
			// y gives the number of diamonds that must be below the point
			// UNLESS the point's the tip of the triangle

			if (y + 1 == triangleside)
			{
				assert (diamondcount < triangleside * 2 - 1);
				p = 0;
			}
			else if (diamondcount <= (unsigned int) y)
			{
				// Too few diamonds that it's definitely impossible for this point to be filled.
				p = 0;
			}
			else if (diamondcount >= y + triangleside)
			{
				// So many diamonds that it's impossible for this point to not be filled.
				p = 1;
			}
			else
			{
					// We have diamondcount diamonds
					// We want at least n = y + 1 to go in our direction
					// Let's call our direction left. (symmetry!)

					// X = number of diamonds that went left
					// We want P (X >= n) = P (X = n) + P (X = n + 1) + ... + P (X = diamondcount)

					p = 0;
					unsigned int wantright = y + 1;
					for (unsigned int j = wantright; j <= diamondcount; j++)
					{
						p += choose (diamondcount, j) * pow (0.5, (double) diamondcount);
					}
			}
		}

		out.precision (8);
		out << "Case #" << (i + 1) << ": " << p;
		out << std::endl;
	}

	return 0;
}

