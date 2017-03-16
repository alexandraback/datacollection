
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cstdint>

#include <iostream>
#include <string>
#include <sstream>

#include <map>
#include <vector>
#include <algorithm>

//#include "sparse_array.h"

using namespace std;

class Tribe
{
	public:
		Tribe(int new_d, int new_n, int new_e, int new_w, int new_s, int new_delta_d, int new_delta_p, int new_delta_s)
			: d(new_d), n(new_n), e(new_e), w(new_w), s(new_s), delta_d(new_delta_d), delta_p(new_delta_p), delta_s(new_delta_s)
		{
		
		}
		
		virtual ~Tribe() {}
		
		int d;
		int n;
		int e;
		int w;
		int s;
		int delta_d;
		int delta_p;
		int delta_s;
};

int main(int argc, char ** argv)
{
	// number of cases
	#ifdef DEBUG
	debug_init(argc, argv);
	#endif //DEBUG
	
	uint nCases;
	cin >> nCases;
	// do cases
	for (uint c = 1; c <= nCases; ++c)
	{
		// get stuff
		vector<Tribe*> tribes;
		map<double, int> wall; // maps int to height
		map<double, int> wall_strengthen;
		uint N;
		cin >> N;
		for (uint t = 0; t < N; ++t)
		{
 			int d; int n; int w; int e; int s; int delta_d; int delta_p; int delta_s;
			cin >> d >> n >> e >> w >> s >> delta_d >> delta_p >> delta_s;
			tribes.push_back(new Tribe(d, n, e, w, s, delta_d, delta_p, delta_s));	
		}
		
		//solve case
		int day = 0;
		uint breaches = 0;
		while (true)
		{
			//cerr << "The dawn of the " << day << "th day...\n";
			bool tribes_left = false;
			for (uint i = 0; i < tribes.size(); ++i)
			{
				bool success = false;
				if (tribes[i]->n > 0)
					tribes_left = true;
				
				if (tribes[i]->d == day && tribes[i]->n > 0)
				{
					//cerr << "Tribe["<<i<<"] attacks! Strength: " << tribes[i]->s << " along [" << tribes[i]->e << ", " << tribes[i]->w << "]\n";
					// The tribe attacks today
					for (double x = tribes[i]->e; x <= tribes[i]->w; x+=0.5)
					{
						//cerr << "\t wall["<<x<<"] = " << wall[x] << "\n";
						if (wall[x] < tribes[i]->s)
						{
							success = true;
							if (wall_strengthen[x] < tribes[i]->s)
								wall_strengthen[x] = tribes[i]->s;
						}
					}
					
					if (success)
					{
						breaches += 1;
					}
					
					tribes[i]->e += tribes[i]->delta_p;
					tribes[i]->w += tribes[i]->delta_p;
					tribes[i]->d += tribes[i]->delta_d;
					tribes[i]->s += tribes[i]->delta_s;
					tribes[i]->n -= 1;
				}
			}
			
			// strengthen the wall
			map<double, int>::iterator i = wall_strengthen.begin();
			while (i != wall_strengthen.end())
			{
				wall[i->first] = i->second;
				++i;
			}
			
			if (!tribes_left)
				break;
			
			day++;	
		}

		#ifdef DEBUG_PLOT
		debug_time(c);
		#elif defined DEBUG
		debug_progress(c, nCases);
		#endif //DEBUG_PLOT
		cout << "Case #" << c << ": " << breaches << "\n";
		
		for (uint t = 0; t < N; ++t)
		{
			delete tribes[t];
		}
		tribes.clear();
	}
	
	#ifdef DEBUG
	debug_finish();
	#endif //DEBUG
	return 0;	
}