
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <list>
#include <unordered_map>

#define FIRST_DONE 100000000


using namespace std;

int main() {
	cout.precision(20);
	cerr.precision(20);

	int tn;
	cin >> tn;

	for (int ti = 0; ti < tn; ti++) {

		int n;
		cin >> n;

		list<pair<int, int> > s;
		for (int i = 0; i < n; ++i)
		{
			pair<int, int> i;
			cin >> i.first >> i.second;
			s.push_back(i);
		}

		int stars = 0;
		int stepcount = 0;
		while (s.size())
		{
			bool solved = false;

			//solve/upgrade 2*
			for (list<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it)
			{
				if (it->second <= stars)
				{
					s.erase(it);
					solved = true;
					++stepcount;
					++stars;
					if (it->first != FIRST_DONE) ++stars;
					break;					
				}
			}
			if (solved) continue;

			//solve the best 1*
			list<pair<int, int> >::iterator best = s.end();
			int best_second = -1;
			for (list<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it)
			{
				if (it->first <= stars)
				{
					if (it->second > best_second)
					{
						best_second = it->second;
						best = it;
					}
				}
			}
			if (best != s.end())
			{
				//cerr << best->first << ", " << best->second << endl;
				best->first = FIRST_DONE;
				solved = true;
				++stepcount;
				++stars;
			}
			if (solved) continue;

			break;
		}

		if (s.size())
		{
			cout << "Case #" << ti+1 << ": " << "Too Bad" << endl;
			cerr << "Case #" << ti+1 << ": " << "Too Bad" << endl;
		}
		else
		{
			cout << "Case #" << ti+1 << ": " << stepcount << endl;
			cerr << "Case #" << ti+1 << ": " << stepcount << endl;
		}
	}
}

