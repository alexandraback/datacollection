/*
 * B.cpp
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

int E, R, N;
int v[10009] ;
int mem[10009][100] ;

int calc (int idx, int rem) {
	if (idx == N)
		return 0 ;

	int & r = mem[idx][rem] ;
	if (r != -1)
		return r;

	r = 0 ;
	for (int j=0 ; j <= rem ; j++)
		r = max (r, calc (idx+1, min (E, rem - j + R)) + j*v[idx]) ;

	return r ;
}


int main (){
#ifndef ONLINE_JUDGE
	freopen ("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif
	int T ;
	cin >> T ;

	for (int tt = 1 ; tt <= T ; tt++){
		cout << "Case #" << tt << ": " ;

		cin >> E >> R >> N ;
		for (int i=0 ; i < N ; i++)
			cin >> v[i] ;

		memset (mem, -1, sizeof mem) ;
		cout << calc (0, E) << endl ;
	}
	return 0;
}
