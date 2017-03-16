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

bool isVowel(char c)
{
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}

int main() {

  int tn;
  cin >> tn;

  for (int ti = 0; ti < tn; ti++) {

		string s;
    int n = -1;
    cin >> s >> n;
		if (-1 == n) {
			cerr << "ERROR" << endl;
			exit(1);
		}

		cerr << s << " " << n << endl;

		vector<int> v;
		v.reserve(s.size());

		for (int i = 0; i < (int)s.size(); ++i) {
			v.push_back(!isVowel(s[i]));
		}
		//cerr << v << endl;

		ll result = 0;
		int lastVowel = -1;
		int lastFrom = -1;
		set<pair<int, int> > se;
		for (int i = 0; i < (int)s.size(); ++i) {
			//cerr << "i: " << i << " lastVowel: " << lastVowel << endl;
			if (-1 == lastVowel) {
				if (v[i]) {
					lastVowel = i;
				}
			} else {
				if (!v[i]) {
					lastVowel = -1;
				}
			}

			if (v[i]) {
				if (i - lastVowel >= n - 1) {
					int from = i - n + 1;
					int to = from + n;
					ll curr = (from - (lastFrom + 1) + 1) *
										(s.size() - to + 1);
					//cerr << "from: " << from << "  to: " << to << "  " << s.substr(from, n) << "  curr: " << curr << endl;
					result += curr;

					lastFrom = from;

					for (int _a = 0; _a <= from; ++_a) {
						for (int _b = to; _b <= (int) s.size(); ++_b) {
							se.insert(make_pair(_a, _b));
						}
					}
				}
			}
		}


    cerr << "Case #" << ti+1 << ": " << result << endl;
		result = se.size();



    cout << "Case #" << ti+1 << ": " << result << endl;
    cerr << "Case #" << ti+1 << ": " << result << endl;

  }
}

