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

const int MAXP = 100;

vector<int> p;
vector<vector<int> > res;
vector<vector<int> > d;

void get_res (int n, int num) {
	res.clear();
	d.clear();

	vector<int> cur(n, 0);
	cur[0] = cur[n - 1] = 1;
    
    vector <int> cur_d;

    bool key = true;
	while (key) {
		cur_d.clear();
		bool key_good = true;
		for (int i = 2; i <= 10; ++i) {
			long long cur_num = 0;
			for (int j = 0; j < n; ++j) {
				cur_num = min((long long) inf, cur_num * i + cur[j]);
			}

			bool key_find = false;
			for (int j = 0; j < sz(p); ++j) {
				int mod = 0;
				for (int k = 0; k < n; ++k) {
					mod = (mod * i + cur[k]) % p[j];	
				}
				if (mod == 0 && cur_num != p[j]) {
					key_find = true;
			   		cur_d.pb(p[j]);
			   		break;
			   	}
			}

			if (!key_find) {
				key_good = false;
				break;
			}
		}

		if (key_good) {
        	res.pb(cur);
			d.pb(cur_d);
		    
			if (sz(res) >= num) {
		    	return;
		    }
		}

		key = false;
		for (int i = n - 2; i >= 0; --i) {
			if (cur[i] == 0) {
				cur[i] = 1;
				for (int j = i + 1; j < n - 1; ++j) {
					cur[j] = 0;
				}
				key = true;
				break;
			}
		}
	}
}

int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	for (int i = 2; i < MAXP; ++i) {
		bool key = true;
		for (int j = 0; j < sz(p) && p[j] * p[j] <= i; ++j) {
			if (i % p[j] == 0) {
				key = false;
				break;
			}
		}
		if (key) {
			p.pb(i);
		}
	}

	int tc;
	cin >> tc;

	int n, num;
	for (int i = 0; i < tc; ++i) {
		cin >> n >> num;
		
		get_res(n, num);

		cout << "Case #" << i + 1 << ":" << endl;
		assert(sz(res) >= num);
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << res[i][j];
			}
			for (int j = 0; j < 9; ++j) {
				cout << " " << d[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
