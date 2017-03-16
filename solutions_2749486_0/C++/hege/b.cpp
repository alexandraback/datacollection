#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <list>
#include <numeric>

using namespace std;

class Solver
{
	struct State
	{
		int x;
		int y;
		int l;
		char d;
	};
public:
	string Solve()
	{
		int X, Y;
		cin >> X >> Y;

		if ( X == 0 && Y == 0 )
			return "";

		char ret[501];
		vector<State> states;
		states.reserve(500);
		
		for ( int depth = 1; depth <= 500; ++depth )
		{
			states.clear();
			State sts = { 0, 0, 0, 0 }, ns;
			states.push_back(sts);

			const int ml = depth * (depth - 1) / 2;

			while ( !states.empty() )
			{
				State s = states.back();
				states.pop_back();
				if ( s.d )
					ret[s.l-1] = s.d;
				// win check
				if ( s.x == X && s.y == Y ) {
					ret[s.l] = '\0';
					return ret;
				}

				// cut
				if ( s.l == depth )
					continue;
				if ( abs(X - s.x) + abs(Y - s.y) > ml - (s.l * (s.l - 1)) / 2 )
					continue;

				// spread
				ns = s;
				++ns.l;
				ns.y += ns.l;
				ns.d = 'N';
				states.push_back(ns);
				ns = s;
				++ns.l;
				ns.y -= ns.l;
				ns.d = 'S';
				states.push_back(ns);
				ns = s;
				++ns.l;
				ns.x += ns.l;
				ns.d = 'E';
				states.push_back(ns);
				ns = s;
				++ns.l;
				ns.x -= ns.l;
				ns.d = 'W';
				states.push_back(ns);
			}
		}

		return "IMPOSSIBLE";
	}
};

int main()
{
	int T;
	cin >> T;
	for ( int t = 0; t < T; ++t )
	{
		cout << "Case #" << (t+1) << ": " << Solver().Solve() << endl;
	}
	return 0;
}
