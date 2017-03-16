#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool canEliminate(const vector<double>& v, int i, double vd) {
	double needed = 0;
	for(int j=0; j<v.size(); j++) if(j!=i) needed += max(0.0, v[i]+vd-v[j]);
	return needed+vd < 1;
}

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		int N;
		cin >> N;
		vector<double> s(N);
		int st=0;
		for(int i=0; i<N; i++) { cin >> s[i]; st+=s[i]; }
		for(int i=0; i<N; i++) s[i]/=st;
		cout << "Case #" << ts << ":";
		for(int i=0; i<N; i++) {
			double ret = 0;
			double lo=0, hi=1;
			while(lo<hi-1e-8) {
				double mid = (lo+hi)/2;
				if(canEliminate(s,i,mid)) lo=mid;
				else hi=mid;
			}
			printf(" %.8lf", 50*(lo+hi));
		}
		cout << endl;
	}
}
