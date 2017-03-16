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

int main (){
#ifndef ONLINE_JUDGE
	freopen ("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif
	int dd =  1 ;
	int t ;
	cin >> t ;

	while (t--) {
		double r, m ;
		cin >> r >> m ;

		int cnt = 0 ;

		while (m > 0) {
			double Larea = ((r+1) * (r+1) * PI) ;
			double Sarea = (r * r * PI) ;
			double cur = (Larea - Sarea) / PI ;

			if (dcmp (cur, m) == 1)
				break ;

			m -= cur ;
			cnt ++ ;
			r += 2 ;
		}
		cout << "Case #" << dd++ << ": " << cnt << endl;
	}
	return 0;
}
