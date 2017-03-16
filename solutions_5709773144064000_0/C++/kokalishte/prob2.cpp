#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};
ld start_time,end_time;

string solve() {
	ld c, f, x;
	cin >> c >> f >> x;

	ld rate = 2.0;
	
	ld curMin = x/rate;
	ld nextMin = 0.0;
	ld atm = 0.0;
	while (true) {
		atm += c/rate;
		rate += f;
		nextMin = atm + x/rate;

		if (nextMin+.000000001 < curMin) {
			curMin = nextMin;
		} else break;
	}
	
	stringstream ss;
	ss << fixed << setprecision(7);
	ss << curMin;
	return ss.str();
}



int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//start_time = get_time();
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test ,solve().c_str()); 
	}


	//end program
	//end_time=get_time()-start_time;
	return 0;
}




