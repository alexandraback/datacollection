#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;
typedef vector<string> VS;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define fr(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,n)    fr(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

VI vec;
int total;
int E;

int go(int pos, int e, int r, int sum) {
	if (pos == vec.size()) {
		if (total < sum) total = sum;
		return 0;
	}
	for (int spend = 0; spend <= e; spend++) {
		go(pos + 1, min(E, e - spend + r), r, spend * vec[pos] + sum);
	}
	return 0;
}

int main() 
{
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		vec.clear();
		int r, n;
		cin >> E >> r >> n;
		rep(i, n) {
			int tmp;
			cin >> tmp;
			vec.pu(tmp);
		}
		total = 0;
		int ret = go(0, E, r, 0);
		printf("Case #%d: %d\n", tt + 1, total);
	}
	return 0;
}