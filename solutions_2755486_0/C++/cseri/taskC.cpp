#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <stdexcept>

#include "prettyprint.hpp"

using namespace std;

typedef long long int ll;

struct attack
{
	int tribe;
	int day;
	int n;
	int west;
	int east;
	int s;
	int delta_day;
	int delta_pos;
	int delta_s;
};

struct comp {
	bool operator()(const attack&a1, const attack&a2) {
		return a1.day < a2.day || (a1.day == a2.day && a1.tribe < a2.tribe);
	}
};

ostream &operator<<(ostream &o, const attack &a)
{
	o << "(";
			o<<a.day<< " ";
			o<<a.n<< " ";
			o<<a.west<< " ";
			o<<a.east<< " ";
			o<<a.s<< " ";
			o<<a.delta_day<< " ";
			o<<a.delta_pos<< " ";
			o<<a.delta_s<< " ";
	o << ")";
	return o;
}

bool check(const vector<int> &wall, const int westmin, const attack & a) {
	for (int i = a.west -westmin; i <= a.east -westmin; ++i) {
		if (wall[i] < a.s) {
			return true;
		}
	}
	return false;
}

void build(vector<int> &wall, const int westmin, const attack & a) {
	for (int i = a.west -westmin; i <= a.east -westmin; ++i) {
		if (wall[i] < a.s) {
			wall[i] = a.s;
		}
	}
}

int main() {

  int tn;
  cin >> tn;

  for (int ti = 0; ti < tn; ti++) {
vector<attack> v;

    int n = -1;
    cin >> n;

		for (int i = 0; i < n; ++i) {
			attack a;
			a.tribe = i;
			cin>>a.day;
			cin>>a.n;
			cin>>a.west;
			cin>>a.east;
			cin>>a.s;
			cin>>a.delta_day;
			cin>>a.delta_pos;
			cin>>a.delta_s;

			a.west *= 2;
			a.east *= 2;
			a.delta_pos *= 2;

			while (a.n) {
				v.push_back(a);
				a.day += a.delta_day;
				a.west += a.delta_pos;
				a.east += a.delta_pos;
				a.s += a.delta_s;
				--a.n;
			}
		}

		sort(v.begin(), v.end(), comp());

		//cerr << v << endl;

		int westmin = v[0].west;
		int eastmax = v[0].east;
		for (int i = 0; i < (int) v.size(); ++i)
		{
			if (westmin > v[i].west) westmin = v[i].west;
			if (eastmax < v[i].east) eastmax = v[i].east;
		}
		++ ++ ++eastmax;

		cerr << "westmin: " << westmin << endl;
		cerr << "eastmax: " << eastmax << endl;


		vector<int> wall(eastmax-westmin);

		int lastTimeChange = 0;
		int result = 0;
		for (int i = 0; i < (int) v.size(); ++i)
		{
			if (i && v[i-1].day < v[i].day) {
				for (int j = lastTimeChange; j < i; ++j) {
					build(wall, westmin, v[j]);
				}
				lastTimeChange = i;
			}
			/*cerr << "step " << i << "  day " << v[i].day << endl;
			cerr << wall << endl;
			cerr << "attack pos: " << v[i].west << " " << v[i].east << endl;
			cerr << "attack s: " << v[i].s << endl;*/
			if (check(wall, westmin, v[i])) {
				++result;
				cerr << "  breach!" << endl;
			}
		}



    cout << "Case #" << ti+1 << ": " << result << endl;
    cerr << "Case #" << ti+1 << ": " << result << endl;

  }
}

