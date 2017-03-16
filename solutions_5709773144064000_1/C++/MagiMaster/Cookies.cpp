#include <iostream>
#include <iomanip>
using namespace std;

class Cookies {
public:
	void go(istream &in, ostream &out) {
		int t;
		double c, f, x;
		
		in >> t;

		for (int i = 1; i <= t; ++i) {
			in >> c >> f >> x;

			double total = 100000.0, prev;
			double time = 0.0;
			double rate = 2.0;
			double f_time = 0.0;
			double x_time = 0.0;
			
			for (int n = 0;; ++n) {
				prev = total;

				time += f_time;

				rate = 2.0 + f * n;
				f_time = c / rate;
				x_time = x / rate;

				total = time + x_time;
				if (total > prev) {
					out << "Case #" << i << ": " << setprecision(20) << prev << endl;
					break;
				}
			}
		}
	}
};