#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>


void solve(std::ifstream& input)
{
	double c, f, t;
	input >> c >> f >> t;
	double max =t/2.0;
	
	double current = 0;
	double rate = 2.0;

	while(1) {
		double c_t = c/rate;
		double new_rate = rate + f;
		double new_max = current+ c_t + t/new_rate;
		if(new_max < max) {
			max = new_max;
			current = current + c_t;
			rate = new_rate;
		}
		else {
			break;
		}
	}
	printf("%.8f\n", max);
}
int main(int argc, char* argv[]) 
{
	if(argc < 2) {
		std::cerr << "missing input file\n" ;
		return 1;
	}

	std::ifstream in(argv[1]);
	int c ;
	in  >> c;
	for(int i =1; i <=c;++i) {
		printf("Case #%d: ", i);
		solve(in);
	}
	return 0;
}
