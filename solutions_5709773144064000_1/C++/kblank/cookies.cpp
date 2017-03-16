#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  int T; 
  double C, F, X, besttime, curtime;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cin >> C >> F >> X;
    besttime = X / 2; //0 factories
    double daily = 2;
		curtime = 0;
    for (;;) {
			double time_new_factory = C/daily + curtime;
			daily = daily + F;
			double time = X/daily + time_new_factory;
			curtime = time_new_factory;
			if (time <= besttime)
							besttime = time;
			else 
							break;
    };
    cout << "Case #" << i << ": " << setprecision(7) << fixed << besttime << endl;
  };
};
