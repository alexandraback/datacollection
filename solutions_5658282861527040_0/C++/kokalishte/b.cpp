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


string solve() {
	int a, b, k;
	int res = 0;
	cin >> a >> b >> k;
	for (int i = 0; i < k; ++i) 
		for (int j = 0; j < a; ++j)
			for (int t = 0;t < b; ++t) 
				if ((j&t) == i) res++;
	stringstream ss;
	ss << res;
	return ss.str();
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test, solve().c_str());
	}
	//end program
	return 0;
}




