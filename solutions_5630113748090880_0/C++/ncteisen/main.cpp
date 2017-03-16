// very useful, common imports
#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
#include <cassert>
#include <climits>
#include <cctype>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>

// bost library for printing out complex data structs. useful for debugging
// can be found http://louisdx.github.io/cxx-prettyprint/
#include "../common/prettyprint.h"

#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()

using namespace std;

using pii = pair<int, int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vd = vector<double>;
using vii = vector<vector<int> >;


void solve(int n)
{
	int nn;
	cin >> nn;

	int lines = (2*nn)-1;

	map<int, int> data;

	//cout << lines << " " << nn << "\n";

	rep(i, lines) {

		rep (j, nn) {
			int x;
			cin >> x;

			if (data.find(x) == data.end()) {
				data[x] = 1;
			}
			else {
				data[x] += 1;
			}
		}

	}

	//cout << data << "\n";

	vi final;

	for (auto it = data.begin(); it != data.end(); ++it) {

		if (it->second % 2) {
			final.pb(it->first);
		}


	}

	sort(all(final));

	cout << "Case #" << n << ": ";
	for (int i = 0; i < final.size(); ++i) {
		cout << final[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		solve(i+1);
	}
}