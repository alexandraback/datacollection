#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

double eps = 0.0000001;

double absd(double x) {
	if (x < 0) return -x;
	return x;
}


int main() {
	cout.setf(ios::fixed);
	cout.precision(8);
	
	int T;
	cin >> T;
	int caso = 1;
	while (caso <= T) {
		double D;
		int N, A;
		cin >> D >> N >> A;
		double to, xo, tf, xf;
		to = xo = tf = xf = 0.0;
		//cin >> to >> xo;
		bool cont = true;
		vector<double> x(N);
		vector<double> t(N);
		cin >> t[0] >> x[0];
		to = t[0];
		xo = x[0];
		for (int e = 1; e < N; ++e) {
			cin >> t[e] >> x[e];
			tf = t[e];
			xf = x[e];
			if (xf >= D) cont = false;
			if (cont) {
				xo = xf;
				to = tf;
			}			
		}
		/*cout << "D = " << D << endl;
		cout << "ori = " << to <<  ' ' << xo << endl;
		cout << "fin = " << tf <<  ' ' << xf << endl;*/
		vector<double> va(A);
		for (int e = 0; e < A; ++e) {
			cin >> va[e];
		}
		
		
		
		cout << "Case #" << caso << ":" << endl;
		for (int i = 0; i < A; ++i) {
			double dpen, tpen;
			dpen = 0.0;
			tpen = 0.0;
			for (int j = 0; j < N; ++j) {
				if (x[j] < D and sqrt(2*x[j]/va[i]) < t[j]) {
					dpen = x[j];
					tpen = t[j];
				}
				
			}
			
			//cout << "tmax ori = " << sqrt(2*(D)/va[i]) << endl;
			//cout << "dpen = " << dpen << " tpen = " << tpen << endl;
			
			double tmax = sqrt(2*abs(D - dpen)/va[i]) + tpen;
			double dist = D - xo;
			double pro = dist/(xf - xo);
			double tc;
			tc = to + (tf-to)*pro;
			
			
			/*
			if (absd(xf - D) < eps) tc = tf;
			else {
				double vel = (xf-xo) / (tf - to);
				double text = dist/vel;
				tc = to + text;
			}*/
			
			//double tc = to + (tf-to)*dist/(xf - xo);
			//cout << tmax << ' ' << tc << endl;
			if (tc > tmax) cout << tc << endl;			
			else cout << tmax << endl;
		}
		
		caso++;
	}
}