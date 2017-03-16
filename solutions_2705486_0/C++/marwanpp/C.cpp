/*
 * C.cpp
 *
 *  Created on: May 4, 2013
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
#include <fstream>

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

vector <vector <string> > dic ;

void ReadDic () {
	ifstream file ;
	file.open("garbled_email_dictionary.txt");
	dic.clear() ;
	dic.resize(11) ;
	string s ;
	while (file >> s)
		dic[SZ(s)].push_back(s) ;
}

string s ;

int min_Cost (int idx, int sz) {
	vector <string> & vs = dic[sz] ;

	int res = sz ;
	for (int i=0 ; i < SZ(vs) ; i++) {
		int cnt = 0  ;
		for (int j=0 ; j < sz ; j++)
			cnt += (s[idx+j] != vs[i][j]) ;
		res = min (res, cnt) ;
	}

	return res ;
}

int mem[50] ;
int calc (int idx) {
	if (idx > SZ(s))
		return oo ;

	if (idx == SZ(s))
		return 0 ;

	int & r = mem[idx];
	if (r != -1)
		return r ;

	r = oo ;
	for (int sz = 1; sz < SZ(dic); sz++)
		r = min (r, calc (idx+sz) + min_Cost(idx, sz)) ;

	return r ;
}

int main (){
	ReadDic();

#ifndef ONLINE_JUDGE
	freopen ("in.in", "rt", stdin);
//	freopen ("input.txt", "rt", stdin);
//	freopen ("output.txt", "wt", stdout);
#endif
	int T ;
	cin >> T ;

	for (int t = 0; t < T ; t++){
		cout << "Case #" << t+1 << ": " ;

		cin >> s ;
		memset (mem, -1, sizeof mem);
		cout << calc (0) << endl ;
	}
	return 0;
}
