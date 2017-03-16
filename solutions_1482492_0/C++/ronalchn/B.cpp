#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>

using namespace std;

void solve(int test) {
  //string str;
  //getline (cin,str);

  double D;
  int N, A;
  
  cin >> D >> N >> A;
  vector<double> x, t;
  bool done=false;
  //cout << "start" << endl;
  for (int i=0;i<N;i++) {
	double ax, at;
	cin >> at >> ax;
	if (!done) {
	  if (ax>D) {
		//cout << "D " << D << ", ax " << ax << endl;
		if (i>0) {
		  double lt=*t.end();
		  double lx=*x.end();
		  at=lt+(D-lx)*(at-lt)/(ax-lx); // new time slot
		  ax=D;
		}
		else {
		  //at = 0;
		  ax = D;
		}
		done=true;
	  }
	  //cout << at << "," << ax << endl;
	  x.push_back(ax);
	  t.push_back(at);
	}
  }
  printf("Case #%d:\n",test);
  for (int k=0;k<A;k++) {
	double a;
	cin >> a;
	//cout << "acceleration " << a << endl;
	double t0=0; // when to start moving from rest
	for (int i=0;i<N;i++) {
	  //cout << "time to reach " << x[i] << " is " << sqrt(2*x[i]/a) << endl;
	  double ti=t[i]-sqrt(2*x[i]/a);
	  //cout << "new start time is " << ti << endl;
	  if (ti>t0) t0=ti;
	}

	double ans = t0+sqrt(2*D/a);
	cout.precision(15);
	cout << ans << endl;
  }


}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
