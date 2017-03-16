#include <assert.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <stddef.h>
#include <stdlib.h>
#include <string>
#include <vector>

struct chest
{
	bool opened;
	unsigned int locktype;
	std::vector<unsigned int> contents;
};

struct problem
{
	unsigned int keys [201];
	unsigned int chestcount;
	chest chests [200];

	std::vector<unsigned int> openedchests;
};

void push_chest (problem &p, unsigned int chestid)
{
	assert (!p.chests [chestid].opened);
	assert (p.keys [p.chests [chestid].locktype] > 0);
	
	p.chests [chestid].opened = true;
	p.keys [p.chests [chestid].locktype]--;

	for (unsigned int i = 0; i < p.chests [chestid].contents.size (); i++)
	{
		p.keys [p.chests [chestid].contents [i]]++;
	}

	p.openedchests.push_back (chestid);
}

void pop_chest (problem &p)
{
	unsigned int chestid = p.openedchests [p.openedchests.size () - 1];

	p.chests [chestid].opened = false;
	p.keys [p.chests [chestid].locktype]++;
	
	for (unsigned int i = 0; i < p.chests [chestid].contents.size (); i++)
	{
		p.keys [p.chests [chestid].contents [i]]--;
	}

	p.openedchests.pop_back ();
}

bool reachpossible (const problem &p)
{
	bool reached [200];
	for (unsigned int i = 0; i < 200; i++)
	{
		reached [i] = p.chests [i].opened;
	}

	// bfs
	std::queue<unsigned int> q;

	// initial queue population
	for (unsigned int i = 0; i < 201; i++)
	{
		if (!p.keys [i]) { continue; }
		for (unsigned int j = 0; j < p.chestcount; j++)
		{
			if (p.chests [j].locktype == i)
			{
				reached [j] = true;
				q.push (j);
			}
		}
	}

	while (!q.empty ())
	{
		unsigned int chestid = q.front ();
		q.pop ();

		// foreach key in the chest
		for (unsigned int i = 0; i < p.chests [chestid].contents.size (); i++)
		{
			// foreach chest
			for (unsigned int j = 0; j < p.chestcount; j++)
			{
				if (p.chests [j].locktype == p.chests [chestid].contents [i] && !reached [j])
				{
					reached [j] = true;
					q.push (j);
				}
			}
		}
	}

	// check
	for (unsigned int i = 0; i < p.chestcount; i++)
	{
		if (!reached [i])
		{
			return false;
		}
	}
	return true;
}

bool dfs (problem &p)
{
	if (p.openedchests.size () == p.chestcount) { return true; }
	if (!reachpossible (p)) { return false; }

	for (unsigned int i = 0; i < p.chestcount; i++)
	{
		if (!p.chests [i].opened &&
			p.keys [p.chests [i].locktype])
		{
			push_chest (p, i);
			bool success = dfs (p);
			if (success) { return true; }
			pop_chest (p);
		}
	}

	return false;
}

bool keyspossible (const problem &p)
{
	unsigned int totalkeys [201];
	unsigned int neededkeys [201];

	for (unsigned int i = 0; i < 201; i++)
	{
		totalkeys [i] = p.keys [i];
		neededkeys [i] = 0;
	}

	for (unsigned int i = 0; i < p.chestcount; i++)
	{
		neededkeys [p.chests [i].locktype]++;
		for (unsigned int j = 0; j < p.chests [i].contents.size (); j++)
		{
			totalkeys [p.chests [i].contents [j]]++;
		}
	}

	// check
	for (unsigned int i = 0; i < 201; i++)
	{
		if (neededkeys [i] > totalkeys [i])
		{
			return false;
		}
	}
	return true;
}

int main ()
{
	std::ifstream in ("d.in");
	std::ofstream out ("d.out");

	unsigned int testcount;
	in >> testcount;

	for (unsigned int i = 0; i < testcount; i++)
	{
		problem p;

		unsigned int initialkeycount;
		in >> initialkeycount;
		in >> p.chestcount;

		for (unsigned int j = 0; j < sizeof (p.keys) / sizeof (*p.keys); j++)
		{
			p.keys [j] = 0;
		}

		std::vector<unsigned int> initialkeys;
		for (unsigned int j = 0; j < initialkeycount; j++)
		{
			unsigned int key;
			in >> key;
			p.keys [key]++;
		}

		for (unsigned int j = 0; j < p.chestcount; j++)
		{
			p.chests [j].opened = false;

			in >> p.chests [j].locktype;
			unsigned int keycount;
			in >> keycount;
			p.chests [j].contents.clear ();
			for (unsigned int k = 0; k < keycount; k++)
			{
				unsigned int key;
				in >> key;
				p.chests [j].contents.push_back (key);
			}
		}

		if (keyspossible (p) && reachpossible (p))
		{
			dfs (p);
		}
		
		out << "Case #" << (i + 1) << ":";
		if (p.openedchests.size () > 0)
		{
			for (unsigned int j = 0; j < p.openedchests.size (); j++)
			{
				out << " " << (p.openedchests [j] + 1);
			}
		}
		else
		{
			out << " IMPOSSIBLE";
		}
		out << std::endl;
	}

	return 0;
}

