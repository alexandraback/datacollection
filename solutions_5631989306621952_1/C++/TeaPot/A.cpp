#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

string get_res (string s, int n) {
	string res = "";
	if (n == 0) {
		return res;
	}

	int ind = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] > s[ind]) {
			ind = i;
		}
	}

	res = get_res (s, ind);
	string tmp = "";
	for (int i = ind; i < n; ++i) {
		if (s[i] == s[ind]) {
			tmp.pb(s[i]);
		} else {
			res.pb(s[i]);
		}
	}

	res = tmp + res;
	return res;
}


int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;

	string s;
	for (int i = 0; i < tc; ++i) {
		cin >> s;
		
		string res = get_res(s, s.length());
		
		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}
