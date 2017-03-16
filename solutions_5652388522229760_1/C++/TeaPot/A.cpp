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

bool used[10];
int cnt_used;

void get_digits (int x) {
	while (x > 0) {
		if (!used[x % 10]) {
			used[x % 10] = true;
			cnt_used++;
		}
		x /= 10;
	}
}

int get_res (int x) {
	if (x == 0) {
		return -1;
	}

	for (int i = 0; i < 10; ++i) {
		used[i] = false;
	}
	cnt_used = 0;

	for (int cur = x; ; cur += x) {
		get_digits(cur);
		if (cnt_used == 10) {
			return cur;
		}
	}
}


int main () {
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tc;
	cin >> tc;

	int n;
	for (int i = 0; i < tc; ++i) {
		cin >> n;
		
		int res = get_res(n);
		
		cout << "Case #" << i + 1 << ": ";
		if (res == -1) {
			cout << "INSOMNIA";
		} else {
			cout << res;
		}
        cout << endl;
	}

	return 0;
}
