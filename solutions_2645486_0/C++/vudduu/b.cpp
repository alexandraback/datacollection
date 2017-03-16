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

LL DP[100][1001]; // N , E
int v[100], E, R, N;

int gen(int it, int e) {
	if(it >= N) return 0;

	LL &r = DP[it][e];
	if(r == -1) {
		LL x= v[it];
		F(i, e+1) {
			LL p = x * LL(i);
			r = max(gen(it+1, min(E, e-i+R)) + p, r);
		}
	}
	return r;
}

void solve() {
	memset(DP, -1, sizeof(DP));
	cin >> E >> R >> N;
	F(i, N) cin >> v[i];
	cout<< gen(0, E) <<endl;
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas=1; cas<=T ;cas++){
		printf("Case #%d: ", cas);
		solve();
	}
}
