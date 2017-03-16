/*
 * $File: b.cc
 * $Date: Sat Apr 12 10:12:41 2014 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cstdio>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void solve(int case_id) {
	printf("Case #%d: ", case_id);
	double C, F, X;
	cin >> C >> F >> X;
	double ans = std::numeric_limits<double>::max();

	double time = 0;
	double cur_speed = 2.0;
	while (ans > time) {
		double time_new_farm = C / cur_speed;
		double time_wait = X / cur_speed;
		ans = min(ans, time + time_wait);
//        if (time_wait >= time_new_farm)
//            break;

		// wait for a new farm
		time += time_new_farm;
		cur_speed += F;
	}
	printf("%.7f\n", ans);
}


int main() {
	int T;
	cin >> T;
	for (int case_id = 1; case_id <= T; case_id ++)
		solve(case_id);
	return 0;
}

/*
 * vim: syntax=cpp11.doxygen foldmethod=marker
 */

