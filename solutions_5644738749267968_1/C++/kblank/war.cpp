#include<iostream>
#include<set>
#include<iomanip>
using namespace std;
int T, N;
double naomi[2000], ken[2000];
set<double> kenset, kenset_dec, naomiset;
int main(){
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		for (int i = 0; i < N; ++i) { cin >> naomi[i]; naomiset.insert(naomi[i]);};
		for (int i = 0; i < N; ++i) { cin >> ken[i]; kenset.insert(ken[i]); kenset_dec.insert(ken[i]); };
		int decent=0, war=0;
		//war
		for (int i = 0; i < N; ++i){
		  double x = naomi[i];
		  auto it = kenset.lower_bound(x);
		  if (it==kenset.end()) it=kenset.begin();
		  double y = (*it);
		  if (x>y) ++war;
		  kenset.erase(it);
		};
		//decent war
		for (int i = 0; i < N; ++i){
			double x, y, xtrue;
		  if (*(naomiset.rbegin()) > *(kenset_dec.begin())) {
		    x = 0.99999999999999;
		    y = *(kenset_dec.begin());
		    kenset_dec.erase(kenset_dec.begin());
		    xtrue = *(naomiset.lower_bound(y));
		    naomiset.erase(naomiset.lower_bound(y));
		  } else {
		    x = *(kenset_dec.rbegin()) -0.0000000001;
		    y = *(kenset_dec.rbegin());
		    xtrue = *(naomiset.begin());
		    kenset_dec.erase(kenset_dec.lower_bound(y)); //rbegin());
		    naomiset.erase(naomiset.begin());
		  };
		//  cout << setprecision(10) << fixed << "naomi=" << xtrue << " x=" << x << " ken=" << y << endl;
		  if (x>y) ++decent;
		};
		cout << "Case #" << t+1 << ": " << decent << " " << war << endl;
	};
};
