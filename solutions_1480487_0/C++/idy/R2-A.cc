#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define eps 1e-10
bool lt(double a, double b) { return a<b-eps; }
bool gt(double a, double b) { return a>b+eps; }
bool check(int x, const vector<int>& s, int S, double p) {
	double q=1-p;
	double score = s[x]+S*p;
	for(int i=0; i<s.size(); ++i) {
		if(i==x) continue;
		double tp=(score-s[i])/S;
		if(lt(tp, 0)) continue;
		if(gt(tp, q)) return true;
		q-=tp;
	}
	if(gt(q, 0)) return false;
	return true;
}
int main() {
	int T, CAS=1;
	cin>>T;
	while(T--) {
		vector<int> s;
		vector<double> res;
		int N;
		int mins;
		int S=0;
		cin>>N;
		for(int i=0; i<N; ++i) {
			int t;
			cin >> t;
			s.push_back(t);
			S+=t;
		}
		mins=s.back();
		for(int i=0; i<N; ++i) mins=min(mins, s[i]);
		
		for(int i=0; i<N; ++i) {
			double lp=0, rp=1;
			while(lt(lp, rp)) {
				// cout << lp << " " << rp << endl;
				double mp = (lp+rp)/2;
				if(check(i, s, S, mp)) rp=mp;
				else lp=mp;
			}
			res.push_back(lp);
		}
		cout << "Case #" << CAS++ << ":";
		for(int i=0; i<res.size(); ++i) printf(" %.7f", res[i]*100);
		cout << endl;
	}
	return 0;
}
