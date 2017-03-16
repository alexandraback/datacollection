/*
 * A.cpp
 *
 *  Created on: Apr 27, 2013
 *      Author: Marwan
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstring>
#include <sstream>
#include <complex>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <climits>
#include <set>
#include <map>

using namespace std;

const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
#define MP make_pair
#define SZ(x) (int)x.size()

int dcmp (double a, double b){
	return (fabs(a-b) <= eps) ? 0 : (( a < b ) ? -1 : 1) ;
}

typedef long long ll;
typedef pair<int,int> pii;


double r, m ;

bool valid (ll x) {
	ll val = (ll) 2*x + 2 * r + 1 ;
	return val <= m / (x + 1) ;
}
int main (){
#ifndef ONLINE_JUDGE
	freopen ("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
	freopen ("output2.txt", "wt", stdout);
#endif
	int dd =  1 ;
	int t ;
	cin >> t ;

	while (t--) {
		cin >> r >> m ;

		ll lo = 0 , hi = (ll)(1e18) + 10 ;
		while (lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2 ;
			if (valid (mid))
				lo = mid ;
			else
				hi = mid-1 ;
		}
		cout << "Case #" << dd++ << ": " << lo+1 << endl;
	}
	return 0;
}
