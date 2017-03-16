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

vector <long long> res;

void get_res(int k, int c, int s) {
	res.clear();
	if (s < (k + c - 1) / c) {
		return;
   	}
	
	for (int i = 0; i < (k + c - 1) / c; ++i) {
		long long cur = 0;
		for (int j = c * i; j < min(c * (i + 1), k); ++j) {
			cur = cur * k + j;
		}
		res.pb(cur + 1);
	}
}

int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;

	int k, c, s;
	for (int i = 0; i < tc; ++i) {
		cin >> k >> c >> s;	
	
		get_res(k, c, s);
		
		cout << "Case #" << i + 1 << ": ";
		if (res.empty()) {
			cout << "IMPOSSIBLE";
		} else {
			for (int j = 0; j < sz(res); ++j) {
				cout << res[j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
