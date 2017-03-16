// CodeJam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

#define rep(i, b, n) for(int i=(b); i<(n); ++i)
#define repd(i, b, n) for(int i=(b); i>(n); --i)
#define trav(it, col) for(typeof((col).begin()) it = (col).begin(); it != (col).end(); ++it)
#define clr(pt) memset((pt), 0, sizeof(pt))
#define EPS 1e-8
#define IFD if(DEBUG)
#define dbg(x) DEBUG && cerr << __LINE__ << ": " << x << endl
#define DL cerr << __LINE__ << endl;
#define mp make_pair

#define DEBUG true

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;
typedef stringstream ss;

int INMODE = 0; // 0 specify cases, 1 single run, 2 indefinite runs

bool solve(int cn){
	int n;
	cin >> n;
	cout << "Case #" << cn << ":" << endl;

	int* s = new int[n];
	rep(i,0,n) cin >> s[i];

	map<int,int> sums;
	rep(mask,0,2 << n)
	{
		int sum = 0;
		rep(i,0,n)
		{
			if(mask & 1 << i) sum += s[i];
		}

		if(sums.count(sum))
		{
			rep(i,0,n)
			{
				if(mask & 1 << i) cout << s[i] << " ";
			}
			cout << endl;

			int otherMask = sums.find(sum)->second;
			rep(i,0,n)
			{
				if(otherMask & 1 << i) cout << s[i] << " ";
			}
			cout << endl;
			return 1;
		}

		sums.insert(pii(sum,mask));
	}

	cout << "Impossible" << endl;
    return 1;
}

int main(){
    //cout << setiosflags(ios::fixed) << setprecision(10);
    int cases = 1 << 30;
    if(INMODE == 0) cin >> cases;
    if(INMODE == 1) cases = 1;
    for(int cn = 1; cn <= cases; ++cn)
        if(!solve(cn) && INMODE == 2) break;
    return 0;
}


