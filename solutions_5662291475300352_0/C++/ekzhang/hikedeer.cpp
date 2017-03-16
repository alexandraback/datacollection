#include <bits/stdc++.h>
using namespace std;

const double EPSILON = 0.000000000000001;

int main() {
	ifstream in("hikedeer.in");
	ofstream out("hikedeer.out");
	int T, N, foo;
	in >> T;
	for (int tc = 1; tc <= T; tc++) {
		out << "Case #" << tc << ": ";
		in >> N;
		if (N == 1) {
			in >> foo >> foo >> foo;
			out << 0 << endl;
		}
		else {
			int pos1, pos2, t1, t2;
			double s1, s2;
			in >> pos1 >> foo >> t1;
			in >> pos2 >> foo >> t2;
			s1 = 360.0 / t1;
			s2 = 360.0 / t2;
			if (t1 == t2) {
				out << 0 << endl;
			}
			else if (s1 > s2) {
				double overtake = ((pos2 - pos1 + 360) % 360) / (s1 - s2);
				double x1 = (360 - pos1) / s1;
				double x2 = (360 - pos2) / s2;
				if (overtake < x1 + EPSILON) {
					overtake += 360 / s1;
				}
				if (overtake < x2 + EPSILON) {
					out << 1 << endl;
				}
				else out << 0 << endl;
			}
			else {
				double overtake = ((pos1 - pos2 + 360) % 360) / (s2 - s1);
				double x1 = (360 - pos1) / s1;
				double x2 = (360 - pos2) / s2;
				if (overtake < x2 + EPSILON) {
					overtake += 360 / s2;
				}
				if (overtake < x1 + EPSILON) {
					out << 1 << endl;
				}
				else out << 0 << endl;
			}
		}
	}
	return 0;
}
