#include <algorithm>
#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdlib.h>
#include <string>

struct p
{
	unsigned int playersize;
	unsigned int motecount;
	unsigned int motes [100];
};

unsigned int minsteps (p &p, unsigned int playersize, unsigned int moteindex)
{
	if (moteindex >= p.motecount) { return 0; }

	if (p.motes [moteindex] < playersize)
	{
		playersize += p.motes [moteindex];
		return minsteps (p, playersize, moteindex + 1);
	}
	else
	{
		if (playersize == 1)
		{
			// cannot add mote
			// remove all the remaining motes.
			return p.motecount - moteindex;
		}

		unsigned int caseA = 1 + minsteps (p, playersize + playersize - 1, moteindex);
		unsigned int caseB = p.motecount - moteindex;

		if (caseA < caseB) { return caseA; }
		return caseB;
	}
}

int main ()
{
	std::ifstream in ("a.in");
	std::ofstream out ("a.out");

	unsigned int testcount;
	in >> testcount;

	for (unsigned int i = 0; i < testcount; i++)
	{
		p p;
		in >> p.playersize;
		in >> p.motecount;
		for (unsigned int j = 0; j < p.motecount; j++)
		{
			in >> p.motes [j];
		}
		std::sort (p.motes, p.motes + p.motecount);

		out << "Case #" << (i + 1) << ": " << minsteps (p, p.playersize, 0);
		out << std::endl;
	}

	return 0;
}

