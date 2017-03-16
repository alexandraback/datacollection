#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("C-small-1-attempt0.in");
	ofstream fout("output.txt");
	int T, a, n, ans;
	fin >> T;
	int p[10];
	double t[10];
	for (int k=0; k<T; k++) {
		fin >> n;
		if (n==1) {
			fin >> p[0] >> a >> t[0];
			if (a==2) {
				t[1] = t[0]+1;
				n = 2;
			}
		}
		else
			for (int i=0; i<n; i++) {
				fin >> p[i] >> a >> t[i];
			}
		if (n>1)
			if (p[0] > p[1]) {
				int temp = p[0]; p[0] = p[1]; p[1] = temp;
				temp = t[0]; t[0] = t[1]; t[1] = temp;
			}
		if (n==1) ans = 0; else {
			double t0 = (double)((double)(360-p[0])/360.0)*(double)t[0];
			double t1 = (double)((double)(360-p[1])/360.0)*(double)t[1];
			if (t1<t0) {
				if (t1+t[1]>t0) ans = 0;  else ans = 1;   
			}
			if (t0<t1) {
				if (t0+t[0]>t1) ans = 0; else ans = 1;
			}
			if (t0==t1) ans = 0;
		}
		fout << "Case #" << k+1 << ": " << ans << endl;
		
	}
	fin.close();
	fout.close();
	return 0;
}
