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

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

void solve()
{
	int N, S, p;
	cin >> N >> S >> p;
	vector<int> ti(N);
	int ok=0, maybe=0, fail=0;
	REP(i,N) {
		cin >> ti[i];
		int avg=ti[i]/3;
		int rem=ti[i]%3;
		if(rem==0) {
			if(avg>=p)
				ok++;
			else if(((avg+1)>=p) && (avg>=1))
				maybe++;
			else
				fail++;
		}else if(rem==1) {
			if((avg+1)>=p)
				ok++;
			else
				fail++;
		}else{
			if((avg+1)>=p)
				ok++;
			else if((avg+2)>=p)
				maybe++;
			else
				fail++;
		}
		//cout << ok << " " << maybe << " " << fail << endl;
	}
	cout << ok+MIN(maybe,S);
}

int main()
{
  int T;
  cin >> T;
  for(int i=0;i<T;i++) {
    cout << "Case #" << (i+1) << ": ";
    solve();
    cout << endl;
  }
}
