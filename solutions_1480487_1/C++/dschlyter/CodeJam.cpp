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

	int sum = 0;
	vector<int> scores;
	vector<double> votes;
	vector<pdi> work;
	rep(i,0,n)
	{
		int tmp;
		cin >> tmp;
		scores.push_back(tmp);
		votes.push_back(0);
		work.push_back(pdi(tmp,i));
		sum += tmp;
	}

	sort(work.begin(), work.end());
	double votesLeft = sum;

	rep(i,1,n)
	{
		double rem = 0;
		rep(j,0,i) rem += (work[i].first - work[j].first);
		rep(j,0,i)
		{
			if(rem < votesLeft)  work[j].first = work[i].first;
			else work[j].first += votesLeft / i;
		}
		votesLeft -= rem;
		if(votesLeft < 0) break;
	}

	if(votesLeft > 0) rep(i,0,n) work[i].first += votesLeft / n;
	rep(i,0,n) votes[work[i].second] = work[i].first;

	cout << "Case #" << cn << ": ";
	rep(i,0,n) cout << ((votes[i] - scores[i]) / sum)*100 << " ";
	cout << endl;

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


