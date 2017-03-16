//
// a.cpp -- A
//
// Siwakorn Sriakaokul - ping128
// Written on Saturday, 13 April 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>

using namespace std;

void reset(){
	// reset values for the each testcase
	
}

typedef long long LL;

bool good(LL num, LL r, LL t){
	LL used = 2 * r * num;
	if(used < 0) return false;
	used += (2 * num - 1) * (num);
	if(used < 0) return false;
	return (used <= t);
}

void solve(){
	reset();
	LL r, t;
	cin >> r >> t;
	LL left = 0, right = min((1000000000LL), 2 * t / r);
	while(left <= right){
		LL mid = (left + right) / 2;
		if(good(mid, r, t))
			left = mid + 1;
		else 
			right = mid - 1;
	}

	cout << right << endl;
}


int main()
{
	int test;
	cin >> test;
	for(int tt = 0; tt < test; tt++ ){
		printf("Case #%d: ", tt + 1);
		solve();

	}
	return 0;
}
