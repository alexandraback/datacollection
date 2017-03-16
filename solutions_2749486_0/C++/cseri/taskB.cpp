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

//#include "prettyprint.hpp"

using namespace std;

typedef long long int ll;



int main() {

  int tn;
  cin >> tn;

  for (int ti = 0; ti < tn; ti++) {

		int x, y;
    cin >> x >> y;
		cerr << x << " " << y << endl;

		string s;

		while (y < 0) {
			s += "NS";
			++y;
		}
		while (y > 0) {
			s += "SN";
			--y;
		}
		while (x < 0) {
			s += "EW";
			++x;
		}
		while (x > 0) {
			s += "WE";
			--x;
		}




		string &result = s;


    cout << "Case #" << ti+1 << ": " << result << endl;
    cerr << "Case #" << ti+1 << ": " << result << endl;

  }
}

