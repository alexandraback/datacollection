#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int N;
double ss[1024];
bool test(int n, double f) {
	double r = 1-f;
	double h = ss[n] + f;
	for(int i=0; i<N; ++i) {
		if (i==n) continue;
		double need = h - ss[i];
		if (need<0) continue;
		if (need>r) return 1;
		r -= need;
	}
	return 0;
}
int main() {
	int t;cin>>t;
	for(int a=1; a<=t; ++a) {
		cin>>N;
		double sum=0;
		for(int i=0; i<N; ++i) cin>>ss[i], sum+=ss[i];
		for(int i=0; i<N; ++i) ss[i] /= sum;
		cout<<"Case #"<<a<<": ";
		for(int i=0; i<N; ++i) {
			double low=0,hi=1;
			for(int j=0; j<100; ++j) {
				double m = .5*(low+hi);
				if (test(i,m)) {
					hi = m;
				} else {
					low = m;
				}
			}
			cout<<' '<<fixed<<setprecision(15)<<100*low;
		}
		cout<<'\n';
	}
}
