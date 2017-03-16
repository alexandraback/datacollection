#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <iomanip>

using namespace std;

struct carpos
{
	double time;
	double pos;
};

static double freefall_vel(double vel, double acc, double t)
{
	return vel + acc * t;
}

static double freefall_pos(double vel, double initpos, double acc, double t)
{
	return initpos + vel*t + acc*t*t / 2;
}

double remaining_time(double v0, double a, double dist)
{
	return (-v0 + sqrt(v0*v0 + 2. * a * dist))/a;
}

double solve_b(double dist, vector<carpos> &poslist, double accel)
{
	double vel = 0;
	double pos = 0;
	double elapsed = 0;
	for(int i=0; i<poslist.size(); i++) {
		carpos &car = poslist[i];
		if (car.pos > dist) {
			double v = 0;
			if (i > 0) {
				v = (car.pos - poslist[i-1].pos)/(car.time - poslist[i-1].time);
			}
			car.time = elapsed + (dist-pos)/v;
			car.pos = dist;
		}
		double time = car.time;
		double p0 = freefall_pos(vel, pos, accel, time-elapsed);
		double v0 = freefall_vel(vel, accel, time-elapsed);
		if (p0 > car.pos) {
			pos = car.pos;
			if (i > 0) {
				vel = (car.pos - poslist[i-1].pos)/(car.time - poslist[i-1].time);
			} else {
				vel = 0;
			}
		} else {
			pos = p0;
			vel = v0;
		}
		elapsed = time;
	}
	return elapsed + remaining_time(vel, accel, dist-pos);
}

int main(int argc, char *argv[]) {
	std::ifstream ifs(argv[1]);
	if (!ifs.is_open()) return -1;
	std::string ofilename = std::string(argv[1]) + ".out";
	std::ofstream ofs(ofilename.c_str());
	int num;
	ifs >> num;
	for(int c=1; c<=num; c++) {
		double D;
		int numN, numA;
		ifs >> D >> numN >> numA;
		vector<carpos> poslist(numN);
		for(int i=0; i<numN; i++) {
			ifs >> poslist[i].time;
			ifs >> poslist[i].pos;
		}
		cout << "Solving " << c << std::endl;
		ofs << "Case #" << c << ": " << std::endl;
		for(int i=0; i<numA; i++) {
			double a;
			ifs >> a;
			double ans = solve_b(D, poslist, a);
			ofs << std::setprecision(20) << ans << std::endl;
		}
	}

	return 0;
}
