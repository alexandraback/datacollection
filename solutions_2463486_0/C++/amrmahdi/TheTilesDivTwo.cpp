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

bool fairSquare[1000 + 5];

bool isPal(int n) {
	int rev = 0;
	int tmp = n;
	while(n) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev == tmp;
}

int main() {

	freopen("in.txt", "r", stdin);

	freopen("out.txt", "w", stdout);

	for(int i = 1; i * i <= 1000; ++i) {
		fairSquare[i * i] = isPal(i * i) && isPal(i);
	}


	int cases;

	cin >> cases;

	for (int c = 1; c <= cases; ++c) {
		int a, b;
		cin >> a >> b;
		int res = 0;
		for(int i = a ; i <= b; ++i) res += fairSquare[i];
		cout << "Case #" << c << ": " << res << endl;
	}

	return 0;
}
