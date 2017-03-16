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

using namespace std;

#define REP(i, n) for(int i = 0; i<(n); i++)
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define inf 2000000001
typedef vector<int> VI;
typedef vector<string> VS;

typedef long long i64;
typedef unsigned long long u64;

void go() {
	int A, B, K;
	cin >> A >> B >> K;
	int ret = 0;
	REP(i, A) REP(j, B) {
		if ((i & j) < K) {
			ret++;
		}
	}
	cout << ret;
}

int main() {
  int T;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
	go();
	cout << endl;
  }
}
