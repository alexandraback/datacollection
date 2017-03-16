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
#include <string>
#include <deque>

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
	string word;
	cin >> word;

	string sorted = word;
	sort(all(sorted), greater<char>());

	//cout << sorted << "\n";

	deque<char> final;

	final.push_back(word[0]);

	for (int i=1; i < word.length(); ++i) {

		if (word[i] >= final[0]) {
			final.push_front(word[i]);
		}
		else {
			final.push_back(word[i]);
		}

	}

	string out(all(final));

	cout << "Case #" << n << ": "  << out      << "\n";
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		solve(i+1);
	}
}