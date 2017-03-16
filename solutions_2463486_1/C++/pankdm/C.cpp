#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;
typedef long long i64;


typedef vector <i64> vi;
typedef vector <vi> vvi;


const i64 nx = 10000000;
vi nums;

string int2str(i64 x) {
	ostringstream o;
	o << x;
	return o.str();
}

bool is_palindrome(i64 x) {
	string s = int2str(x);
	string t = s;
	reverse(all(t));
	return s == t;
}

void prepare() {
	for (i64 i = 0; i <= nx; ++i) {
		if (is_palindrome(i)) {
			i64 n2 = i * i;
			if (is_palindrome(n2)) {
				cerr << "added " << i << " " << n2 << endl;
				nums.pb(n2);
			}
		}
	}
}

void solve() {
	i64 A, B;
	cin >> A >> B;
	int res = 0;
	for (int i = 0; i < sz(nums); ++i) {
		i64 X = nums[i];
		if (A <= X && X <= B) {
			++res;
		}
	}
	cout << res << endl;
}



int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
	//std::ios::sync_with_stdio(false);

	prepare();

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve();
	}

    return 0;
}

