#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

int main() {
	int T, n, s, p, x, pode, need, cnt, podem;
	cin >> T;
	REP(tc, T) {
		cin >> n >> s >> p;
		podem = 0, cnt = 0;
		REP(i, n) {
			cin >> x;
			need = 1;
			pode = 0;
			for (int i = 0; i <= 30; i++) for (int j = i; j <= 30 && j-i <= 2; j++) for (int k = j; k <= 30 && k-i <= 2; k++) {
				if (i+j+k == x && k >= p) {
					if (k - i <= 1) need = 0;
					pode = 1;
				}
			}
			
			if (pode && !need) cnt++;
			else if (pode) podem += need;
		}
		cnt += min(podem, s);
		printf("Case #%d: %d\n", tc+1, cnt);
	}
	
	return 0;
}
