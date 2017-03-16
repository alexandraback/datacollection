#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

ifstream in("B-large.in.txt");
ofstream out("B-large-out");
//#define in cin
//#define out cout

int main()
{
	int T;
	double C, F, X;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> C >> F >> X;
		int N = floor((F * X / C - F - 2) / F);
		if (N < 0) N = 0;
		else N++;
		double res = 0;
		for (int i = 0; i < N; i++) {
			res += (C / (2+i*F));
		}
		res += X / (2+N*F);
		out << "Case #" << cnt << ": " << fixed << setprecision(7) << res << endl;
	}
	return 0;
}

/*
// A
int main()
{
	int T;
	bool flag[17];
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		memset(flag, 0, sizeof(flag));
		int a1, a2, t;
		in >> a1;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				in >> t;
				if (a1 == i) flag[t] = true;
			}
		}
		in >> a2;
		int hit = 0, res;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				in >> t;
				if (a2 == i && flag[t] == true) {
					hit++;
					res = t;
				}
			}
		}
		out << "Case #" << cnt << ": ";
		if (hit == 1) out << res;
		else if (hit == 0) out << "Volunteer cheated!";
		else out << "Bad magician!";
		out << endl;
	}
	return 0;
}
*/