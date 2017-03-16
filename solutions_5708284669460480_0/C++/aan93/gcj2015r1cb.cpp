#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int t,k,l,s;
string a,b;
int main() {
	out.setf(ios::fixed);
	out.precision(7);
	in >> t;
	for (int i=1;i<=t;i++) {
		in >> k >> l >> s;
		in >> a >> b;
		vector <int> z(26,0),c(l,0),x(0);
		vector <double> y(26);
		for (int j=0;j<k;j++) z[a[j]-'A']++;
		for (int j=0;j<26;j++) y[j] = (double)z[j] / k;
		for (int j=0;j<l;j++) {
			bool f = true;
			for (int h=0;f && h<l-j;h++) {
				if (b[j+h] != b[h]) f = false;
			}
			if (f) {
				c[j] = 1;
				x.push_back(j);
			}
		}
		int d = l;
		for (int j=1;d==l && j<l;j++) if (c[j] == 1) d = j;
		bool ps = true;
		for (int j=0;ps && j<l;j++) if (z[b[j]-'A']==0) {
			ps = false;
		}
		if (ps) {
			int g = 1+(s-l)/d;
			vector <double> e0(l+1,0.);
			vector <vector <double> > e(s+1,e0);
			e[0][0] = 1.;
			for (int j=1;j<=s;j++) {

				for (int h=1;h<=l+1;h++) {
					double w = 1.;
					
					int p0;
					if (h == l+1) p0 = 1;
					else p0 = 0;
					for (int p=p0;p<(int)x.size() && x[p]<h-1;p++) {
						bool f = true;

						for (int q=p0;f && q<p;q++) {
							if (b[h-x[p]-1] == b[h-x[q]-1]) {
								f = false;
							}
						}
					
						if (f) {
							e[j][h-x[p]] += e[j-1][h-1] * y[b[h-x[p]-1]-'A'] * w;
							w *= (1. - y[b[h-x[p]-1]-'A']);
						}
					}

					//if (h == l+1) {
						e[j][0] += e[j-1][h-1] * w * (1. - y[b[0]-'A']);
						e[j][1] += e[j-1][h-1] * w * y[b[0]-'A'];
					/*} else {
						e[j][0] += e[j-1][h-1] * w;
					}*/
				}

			}
		
			double u(0.);
			for (int j=1;j<=s;j++) {
				u += e[j][l];
				//for (int h=0;h<=l;h++) cout << i << " " << j << " " << h << " " << e[j][h] << "\n";
			}
			out << "Case #" << i << ": " << (double)g-u << "\n";
		} else {
			out << "Case #" << i << ": " << 0. << "\n";
		}
	}
	return 0;
}
