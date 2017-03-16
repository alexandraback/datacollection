#include <iostream>
#include <fstream>
#include <map>
#include <stddef.h>
#include <stdlib.h>
#include <string>
#include <vector>

// number -> (set item, remainder)
std::map<unsigned long long, std::pair<unsigned long long, unsigned long long> > decomp;
bool impossible;
unsigned int n;
unsigned long long nums [500];

void printset (std::ofstream &out, unsigned long long ptr, unsigned long long lastadd)
{
	std::vector<unsigned long long> v;
	v.push_back (lastadd);
	while (ptr)
	{
		v.push_back (decomp [ptr].first);
		ptr = decomp [ptr].second;
	}
	for (int i = v.size () - 1; i >= 0; i--)
	{
		if (i != v.size () - 1)
		{
			out << " ";
		}
		out << v [i];
	}
	out << std::endl;
}

void solve (std::ofstream &out)
{
	impossible = false;
	decomp.clear ();
	decomp [0] = std::make_pair (0, 0);

	for (unsigned int i = 0; i < n; i++)
	{
		unsigned long long num = nums [i];
		std::map<unsigned long long, std::pair<unsigned long long, unsigned long long> >::iterator iter = decomp.begin ();
		while (iter != decomp.end ())
		{
			if (iter->first == num) { break; }
			unsigned long long newtot = iter->first + num;
			if (!decomp [newtot].first)
			{
				// new
				decomp [newtot] = std::make_pair (num, iter->first);
			}
			else
			{
				// found a pair
				// curr + num
				printset (out, iter->first, num);
				printset (out, decomp [newtot].second, decomp [newtot].first);
				return;
			}
			++iter;
		}
	}
	out << "Impossible" << std::endl;
}

int main ()
{
	std::ifstream in ("c.in");
	std::ofstream out ("c.out");

	unsigned int tests;
	in >> tests;
	for (unsigned int i = 0; i < tests; i++)
	{
		in >> n;
		for (unsigned int j = 0; j < n; j++)
		{
			in >> nums [j];
		}

		out << "Case #" << (i + 1) << ":" << std::endl;
		solve (out);
	}

	return 0;
}