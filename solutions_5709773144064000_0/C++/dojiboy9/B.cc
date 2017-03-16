#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <deque>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

// assume we start with 0 cookies
// and have to reach a value of X
// our current slope is m.
ld solve(ld m, ld C, ld F, ld X) {
	ld time_to_farm = C/m;
	ld time_to_goal = X/m;

	// Compute the "worth it" point (if we take farm)
	ld new_m = (m+F);	// new slope (if we take farm)
	ld t = (new_m*time_to_farm)/(new_m - m);
	assert(t >= time_to_farm);
	
	// Just go to end if it is not worth it to buy farm
	if (time_to_goal <= t)
		return time_to_goal;
		
	// Otherwise, buy the farm.
	return time_to_farm + solve(new_m,C,F,X);
}

int main() {
	int TEST;
	cin >> TEST;
	
	ld C,F,X;
	FORALL(test,1,TEST) {
		cin >> C >> F >> X;
		printf("Case #%d: %0.8Lf\n", test, solve(2,C,F,X));
	}
	
}













