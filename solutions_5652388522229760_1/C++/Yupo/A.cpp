#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

#define INSOMNIA "INSOMNIA"

int main(int argc, char **argv) {
	ll T, N;
	cin >> T;
	REP(i, T) {
		cin >> N;
		cout << "Case #" << (i + 1) << ": ";
		if (N == 0) {
			cout << INSOMNIA << endl;
		}
		else {
			bool a[10];
			CLEAR(a);
			ll v, m = 1;
			while (!(a[0] && a[1] && a[2] && a[3] && a[4] && a[5] && a[6] && a[7] && a[8] && a[9])) {
				v = m * N;
				while (v > 0) {
					a[v % 10] = true;
					v /= 10;
				}
				++m;
			}
			cout << ((m - 1) * N) << endl;
		}
	}
	return 0;
}
