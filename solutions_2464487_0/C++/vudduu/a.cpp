#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define MP          make_pair
typedef long long   LL;

void solve() {
	LL r, t, black;
	cin >> r >> t;
	int c = 0, it = 0;
	while(t > 0) {
		r++;
		if((++it)&1) {
			black = r*r - (r-1LL)*(r-1LL);
			if(black > t) break;
			t -= black;
			c++;
		}
	}
	cout << c << endl;
}

int main(){
	// freopen("in.in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++){
		printf("Case #%d: ", cas);
		solve();
	}
}
