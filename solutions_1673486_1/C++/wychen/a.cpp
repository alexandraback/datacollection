#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#define D 0

void solve(bool skip)
{
	int A, B;
	cin >> A >> B;
	vector<double> pro(B), totpro(B);
	REP(i,A) {
		cin >> pro[i];
		if(i==0) {
			totpro[i] = pro[i];
		} else {
			totpro[i] = totpro[i-1] * pro[i];
		}
		if(D) cerr << totpro[i] << " ";
	}
	if(skip) return;

	// enter
	double ans = B+2;
	for(int i=0; i<A; i++) {
		// i is back steps
		double good = (B-A+1+i*2) * totpro[A-1-i];
		double bad = (B-A+1+i*2 + B+1) * (1-totpro[A-1-i]);
		if(D) {
			cerr << "good= " << good << ", bad = " << bad << endl;
		}
		double tot=good+bad;
		if(tot < ans) {
			ans = tot;
		}
	}
	cout << ans;
}

int main(int argc, char **argv)
{
  int T;
  cin >> T;
  int pick = 0;
  if(argc==2) pick = atoi(argv[1]);
  cout.precision(10);
  for(int i=0;i<T;i++) {
    bool skip = pick && (pick!=i+1);
    if(!skip) {
      cout << "Case #" << (i+1) << ": ";
    }
    solve(skip);
    if(!skip) {
      cout << endl;
    }
  }
}
