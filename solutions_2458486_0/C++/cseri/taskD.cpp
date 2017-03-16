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

int n;
std::vector<int> chestopen;
std::vector<std::vector<int>> chestkeys;

std::set<std::pair<std::vector<bool>,std::multiset<int>>> visited;

std::vector<int> solution;

long long reksteps = 0;
bool tryopen(const std::multiset<int> &mykeys, const vector<bool> &opened)
{
	auto pair = make_pair(opened, mykeys);
	if (visited.count(pair)) {
		return false;
	}
	visited.insert(pair);

	++reksteps;
	if (0 == reksteps % 100000) cerr << reksteps << endl;
	//cerr << mykeys << opened << endl;
	{
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (!opened[i]) {
				ok = false;
				break;
			}
		}
		if (ok) return true;
	}
	for (int i = 0; i < n; ++i) {
		//check if it has been opened
		if (!opened[i]) {
			//try to open
			int keyneeded = chestopen[i];
			//check for keys
			if (mykeys.count(keyneeded)) {
				//found key, open chest!
				std::multiset<int> mykeyscopy = mykeys;
				mykeyscopy.erase(mykeyscopy.find(keyneeded));
				for (const int newkey: chestkeys[i]) {
					mykeyscopy.insert(newkey);
				}
				std::vector<bool> openedcopy = opened;
				openedcopy[i] = true;
				bool b = tryopen(mykeyscopy, openedcopy);
				if (b) {
					solution.push_back(i);
					return true;
				}
			}
		}
	}
	return false;
}

ostream &printsol(ostream &o)
{
	if (solution.size()) {
		for (auto it = solution.rbegin(); it != solution.rend(); ++it) {
			o << (*it)+1 << " ";
		}
	} else {
		o << "IMPOSSIBLE";
	}
	return o;
}

int main() {

  int tn;
  cin >> tn;

  for (int ti = 0; ti < tn; ti++) {

    int k;
    cin >> k >> n;
    
		cerr << "ti: " << ti << " n: " << n << endl;

		chestkeys.clear();
		chestopen.clear();
		chestkeys.resize(n);
		chestopen.resize(n);
		visited.clear();
		solution.clear();

		std::multiset<int> mykeys;
		for (int ki = 0; ki < k; ++ki) {
			int currkey;
			cin >> currkey;
			mykeys.insert(currkey);
		}

		for (int i = 0; i < n; ++i) {
			cin >> chestopen[i];
			int currnumber;
			cin >> currnumber;
			for (int ii = 0; ii < currnumber; ++ii) {
				int currkey;
			  cin >> currkey;
				chestkeys[i].push_back(currkey);
			}
		}

		cerr << "initkeys " << mykeys << endl;
		cerr << "chestkeys " << chestkeys << endl;
		cerr << "chestopen " << chestopen << endl;

		vector<bool> opened;
		opened.resize(n);

		tryopen(mykeys, opened);



    cout << "Case #" << ti+1 << ": ";
		printsol(cout) << endl;
    cerr << "Case #" << ti+1 << ": ";
		printsol(cerr) << endl;

  }
}

