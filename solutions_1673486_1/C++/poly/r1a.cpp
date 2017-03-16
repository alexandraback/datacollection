#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define gp(ans) {cout << "Case #" << ((test)+1) << ": " << (ans) << endl;}

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;

int main () {
  int test, T;
	
  cin >> T;
  REP (test, T) {
		double memo[100000] = {0};
		int a,b,i,j;
		vector<double> pv;
		cin >> a >> b;
		REP(i,a){
			double d;
			cin >> d;
			pv.push_back(d);
		}
		memo[0] = b+1;
		for(i=1; i<=a; i++){
			double pp=1;
			for (j=0; j<i; j++) {
				pp *= pv[j];
			}
			double e = (b+1-i)*pp + (2*b+2-i)*(1.0-pp);
			//printf("i=%d (%d,%d) pp=%f %f %f %f\n", i, a, b, pp, memo[i-1]+1.0, (double)(b+2.0), e);
			memo[i] = min(min(memo[i-1]+1.0, (double)(b+2.0)), e);
		}
		gp(memo[a]);
  }
  return 0;
}

