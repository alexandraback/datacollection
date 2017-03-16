#include <iostream>
#include <fstream>
#include <queue>
#include <stddef.h>
#include <stdlib.h>
#include <string>

// std::ofstream dbg ("dbg.out");
#define BIG 1e308

double ceils [100] [100];
double floors [100] [100];
double mint [100] [100];
int w;
int h;
double initialwater;

double waterlevel (double t)
{
	return initialwater - 10 * t;
}

// returns t
double solvewaterlevel (double level)
{
	return (initialwater - level) / 10;
}

struct path
{
	double t;
	int x;
	int y;
};

class pathcomp
{
public:
	bool operator () (const path &a, const path &b) const
	{
		return a.t > b.t;
	}
};

int dirx [] = { -1,  1,  0,  0 };
int diry [] = {  0,  0, -1,  1 };

double djikstra ()
{
	std::priority_queue<path, std::vector<path>, pathcomp> q;
	path init = { 0, 0, 0 };
	q.push (init);

	while (true)
	{
		path cur = q.top ();
		q.pop ();
		
		// dbg << "at " << cur.x << ", " << cur.y << ": t=" << cur.t << std::endl;
		if (cur.x == w - 1 && cur.y == h - 1) { break; }

		for (unsigned int i = 0; i < 4; i++)
		{
			int newx = cur.x + dirx [i];
			int newy = cur.y + diry [i];
			if (newx < 0 || newy < 0) { continue; }
			if (newx >= w || newy >= h) { continue; }
			
			if (ceils [newy] [newx] < floors [cur.y] [cur.x] + 50) { continue; } // always impossible
			if (floors [newy] [newx] > ceils [cur.y] [cur.x] - 50) { continue; } // always impossible
			if (ceils [newy] [newx] - floors [newy] [newx] < 50) { continue; } // always impossible

			// possible (if water level permits)

			path next;
			next.t = cur.t;
			next.x = newx;
			next.y = newy;

			double wlevel = waterlevel (cur.t);
			if (ceils [newy] [newx] > wlevel + 50)
			{
				// possible at curtime
				if (cur.t != 0)
				{
					double rwlevel = wlevel - floors [cur.y] [cur.x];
					if (rwlevel >= 20)
					{
						next.t += 1;
					}
					else
					{
						next.t += 10;
					}
				}
			}
			else
			{
				// gotta wait
				double twlevel = ceils [newy] [newx] - 50;
				double targt = solvewaterlevel (twlevel);
				double rwlevel = twlevel - floors [cur.y] [cur.x];
				next.t = targt;
				if (rwlevel >= 20)
				{
					next.t += 1;
				}
				else
				{
					next.t += 10;
				}
			}

			if (next.t < mint [newy] [newx])
			{
				mint [newy] [newx] = next.t;
				q.push (next);
				
				// dbg << "\tpush (" << cur.x << ", " << cur.y << ") to (" << newx << ", " << newy << "): t=" << next.t << std::endl;
			}
			else
			{
				// dbg << "\tslow (" << cur.x << ", " << cur.y << ") to (" << newx << ", " << newy << "): t=" << next.t << std::endl;
			}
		}
	}

	return mint [h - 1] [w - 1];
}

int main ()
{
	std::ifstream in ("b.in");
	std::ofstream out ("b.out");
	out.precision (10);

	unsigned int tests;
	in >> tests;

	for (unsigned int i = 0; i < tests; i++)
	{
		in >> initialwater;
		in >> h;
		in >> w;

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				in >> ceils [y] [x];
				mint [y] [x] = BIG;
			}
		}

		mint [0] [0] = 0;

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				in >> floors [y] [x];
			}
		}

		out << "Case #" << (i + 1) << ": " << djikstra () << std::endl;
	}

	return 0;
}