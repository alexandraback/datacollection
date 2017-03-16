#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class War {
public:
	void go(istream &in, ostream &out) {
		int t, n;

		in >> t;

		for (int i = 1; i <= t; ++i) {
			in >> n;

			double temp;
			vector<double> naomi, ken;

			for (int j = 0; j < n; ++j) {
				in >> temp;
				naomi.push_back(temp);
			}
			for (int j = 0; j < n; ++j) {
				in >> temp;
				ken.push_back(temp);
			}

			sort(naomi.begin(), naomi.end());
			sort(ken.begin(), ken.end());

			int s_w = 0, s_d = 0, d = 0, u = n-1, v = n-1;
			while(u >= 0 || v >= 0) {
				if (u == -1 || (v >= 0 && naomi[u] < ken[v])) {
					--v;
					--d;
					if (d < s_d)
						s_d = d;
				} else {
					--u;
					++d;
					if (d > s_w)
						s_w = d;
				}
			}

			out << "Case #" << i << ": " << (n + s_d) << " " << s_w << endl;
		}
	}
};