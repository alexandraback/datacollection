#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 2000000007
#define y1 uu1
#define y2 uu2
#define hash mash
const double EPS = 1E-12;
const double PI = acos(-1.0);
const LL mod = 1000000007;

using namespace std;

string s;

void solve() {
	cin >> s;
	string s0 = "";
	s0 += s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] >= s0[0]) {
			s0 = s[i] + s0;
		} else {
			s0 = s0 + s[i];
		}
	}
	cout << s0 << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  int tt;
  cin >> tt;

  FOR(t,tt) {
  	cout << "Case #" << t+1 << ": ";
  	solve();
  }

  return 0;
}
