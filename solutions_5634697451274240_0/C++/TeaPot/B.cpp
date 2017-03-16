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

int get_res (string &s) {
	s.push_back('+');
	int n = s.length();

	int res = 0;
	for (int i = 0; i + 1 < n; ++i) {
		res += (int) (s[i] != s[i + 1]);
	}

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

		int res = get_res(s);
		
		cout << "Case #" << i + 1 << ": " << res << endl;
	}

	return 0;
}
