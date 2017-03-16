#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using P = complex<int>;

template <class F, class T> void cvt(const F &f, T &t){ stringstream ss; ss << f; ss >> t; }



vector<int> ary(1000010, 1010101);

ll rev(ll n){
	string str;
	cvt(n, str);
	reverse(begin(str), end(str));
	cvt(str, n);
	return n;
}

void init(){
	ary[1] = 1;
	int n = ary.size();
	for(int i=1;i<n;i++){
		if(ary[i] != -1){
			int j = rev(i);
			if(j < n) ary[j] = min(ary[j], ary[i] + 1);
			if(i+1 < n) ary[i+1] = min(ary[i+1], ary[i] + 1);
		}
	}
	//for(int i=0;i<1000;i++) cerr<<i<< " : "<< ary[i]<< endl;
	return;
}

bool solve(){
	ll n;
	cin>> n;

	ll ans = ary[n];
	cout<< ans<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed); cout.precision(10);
	init();

	int n;
	cin>> n;
	for(int i=0;i<n;i++){
		cout<< "Case #"<< i+1<< ": ";
		solve();
	}
	return 0;
}
