#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#define rep(x,n) for(int x=0;x<n;++x)
#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
#define mem(a, b) memset(a, b, sizeof(a))

#define mp(x,y) make_pair(x,y)
#define getBit(code, i) (code & (1 << i))
#define setBit(code, i) (code | (1 << i))
#define xetBit(code, i) (code & ~(1 << i))
#define PI acos(-1.0)
#define oo (int)10e7
#define rd(x) scanf("%d", &x)
#define rdfile(x) freopen(x, "r", stdin)
#define wtfile(x) freopen(x, "w", stdout)
using namespace std;

#define negmod(x, mod) ((x + mod) % mod)

bool isPal(long long n) {
	long long rev = 0;
	long long tmp = n;
	while (n) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev == tmp;
}

struct chest {
	int key;
	vector<int> keys;
};

char table[1 << 22];
int k, n;
int start[205];
chest chests[20];

#include<assert.h>

char solve(int mask) {

	if (mask == (1 << n) - 1) {
		return true;
	}

	char &ret = table[mask];

	if (ret != '?') {
		return ret;
	}

	ret = false;
	int tmp[205];
	memset(tmp, 0, sizeof tmp);

	// keys I got

	rep(i, k) {
		tmp[start[i]]++;
	}
	rep(i, n) {
		if (getBit(mask, i)) {
			rep1(j, chests[i].keys) {
				tmp[chests[i].keys[j]]++;
			}
			tmp[chests[i].key]--;
		}
	}

	rep(i, n) {
		if (!getBit(mask, i) && tmp[chests[i].key] > 0) {
			ret |= solve(setBit(mask, i));

		}
	}

	return ret;
}

void build(int mask) {

	if (mask == (1 << n) - 1) {
		return;
	}
	int tmp[205];
	memset(tmp, 0, sizeof tmp);

	// keys I got

	rep(i, k) {
		tmp[start[i]]++;
	}
	rep(i, n) {
		if (getBit(mask, i)) {
			rep1(j, chests[i].keys) {
				tmp[chests[i].keys[j]]++;
			}
			tmp[chests[i].key]--;
		}

	}

	rep(i, n) {
		if (!getBit(mask, i) && tmp[chests[i].key] > 0) {
			if (solve(setBit(mask, i)) == true) {
				cout << " " << i + 1;
				build(setBit(mask, i));
				break;
			}
		}
	}
}

vector<int> open[205];

int main() {

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

	int cases;

	cin >> cases;

	for (int c = 1; c <= cases; ++c) {

		cin >> k >> n;

		rep(i, 205) {
			open[i].clear();
		}

		rep(i, k) {
			cin >> start[i];
		}

		rep(i, n) {

			cin >> chests[i].key;
			int tmp, ki;
			chests[i].keys.clear();
			open[chests[i].key].push_back(i);
			cin >> ki;
			rep(j, ki) {
				cin >> tmp;
				chests[i].keys.push_back(tmp);
			}
		}

		memset(table, '?', sizeof table);
		cout << "Case #" << c << ":";
		bool sol = false;

		vector<int> vec;
		rep(i, k) {
			rep1(j, open[start[i]]) {
				vec.push_back(open[start[i]][j]);
			}
		}

		sort(vec.begin(), vec.end());
		rep1(i, vec) {
			if (solve(setBit(0, vec[i])) == true) {
				sol = true;
				cout << " " << vec[i] + 1;
				build(setBit(0, vec[i]));
				break;
			}
		}

		if (!sol) {
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}

	return 0;
}
