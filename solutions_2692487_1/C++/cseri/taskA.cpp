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



int main() {

  int tn;
  cin >> tn;

  for (int ti = 0; ti < tn; ti++) {

    int a = -1;
    int n = -1;
    cin >> a >> n;
		cerr << "ti: " << ti << " a: " << a << " n: " << n << endl;

		std::vector<int> opponents(n);
		for (int i = 0; i < n; ++i) {
			cin >> opponents[i];
		}
		sort(opponents.begin(), opponents.end());

		cerr << opponents << endl;

		int result;
		int minstepsplace = -1;
		if (1 == a) {
			result = n;
		} else {

			std::vector<int> steps(n);

			ll curr = a;
			for (int i = 0; i < n; ++i) {
				//try to eat
				if (i) {
					steps[i] = steps[i - 1];
				}
				while (curr <= opponents[i]) {
					//insert
					++steps[i];
					curr = 2*curr - 1;
				}
				curr += opponents[i];
			}
			
			int minsteps = n;
			minstepsplace = -1;
			for (int i = 0; i < n; ++i) {
				int currsteps = (steps[i] + (n-1-i));
				if (currsteps < minsteps) {
					minsteps = currsteps;
					minstepsplace = i;
				}
			}
      result = minsteps;
		}




    cout << "Case #" << ti+1 << ": " << result << endl;
    cerr << "Case #" << ti+1 << ": " << result << "  @" << minstepsplace << endl;

  }
}

