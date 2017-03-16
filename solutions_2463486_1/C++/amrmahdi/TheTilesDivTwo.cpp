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

set<long long> fs;
bool isPal(long long n) {
	long long rev = 0;
	long long tmp = n;
	while (n) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev == tmp;
}

int main() {

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

	long long mx = 1e14;
	for (long long i = 1; i * i <= mx; ++i) {
		if (isPal(i) && isPal(i * i)) {
			fs.insert(i * i);
		}
	}

	int cases;

	cin >> cases;

	for (int c = 1; c <= cases; ++c) {
		long long a, b;
		cin >> a >> b;
		int res = 0;
		for(set<long long>::iterator i = fs.begin(); i != fs.end(); ++i) {
			res += (*i >= a && *i <= b);
		}
		cout << "Case #" << c << ": " << res << endl;
	}

	return 0;
}
