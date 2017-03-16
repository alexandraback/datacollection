#include <iostream>
#include <fstream>
#include <map>
#include <math.h>

double l;
double t[2000];
double d[2000];
int n,m;
double min_t;
double min_err = 0.000000001;

void init() {
}

void find_min() {
	double s = 0;
	double off =0;
	for(int i =0; i < n;++i) {
		if(d[i] >=l) {
			if(t[i] - s > min_err) {
				t[i] = s+ (l - off) / ((d[i] - off) /( t[i] -s));
				d[i] = l;
			}
			return;
		}
		s = t[i];
		off = d[i];
	}
}

void solve(double a) {
	double s = 0;
	double off =0;
	double max_wait = 0;
	for(int i =0; i < n && (d[i] - l <= min_err);++i) {
		double tmp = sqrt(d[i]* 2 / (a));
		if(max_wait + tmp < t[i]) {
			max_wait = t[i] - tmp;
		}
	}
	printf("%.7f\n", max_wait +  sqrt(l* 2 / (a)));
}
int main(int argc , char** argv)
{
	init();
	std::ifstream in(argv[1]);
	int count;
	in >> count;
	for(int i = 1; i <=count;++i) 
	{
		std::cout << "Case #" << i << ":\n";
		in >> l;
		in >>n;
		in >> m;
		for(int j =0; j < n;++j) {
			in >> t[j] >> d[j];
		}

		find_min();
		double a;

		for(int j = 0; j < m;++j) {
			in >> a;
			solve(a);
		}
	}
	return 0;
}

