#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int main() {
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		int A, B, K;
		int ret = 0;
		cin >> A >> B >> K;
		for (int i = 0; i < A; i++)
			for (int j = 0; j < B; j++) {
				if ((i & j) < K) ret++;
			}
		cout << ret << endl;
	}
	return 0;
}

