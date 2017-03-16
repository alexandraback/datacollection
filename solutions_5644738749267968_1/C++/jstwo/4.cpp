#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>
#include <algorithm>
#include <assert.h>
#include <deque>

int deceitful_war(std::deque<double> x, std::deque<double> y)
{
	int c = 0;
	while(!x.empty()) {
		if(*x.begin() > *y.begin()) {
			++c;
			x.pop_front();
			y.pop_front();
			continue;
		}
		if(*x.begin() > *y.rbegin()) {
			++c;
		}
		x.pop_front();
		y.pop_back();
	}
	return c;
}
int war(std::deque<double> x, std::deque<double> y)
{
	int c = 0;
	while(!x.empty()) {
		if(*x.rbegin() > *y.rbegin()) {
			++c;
			x.pop_back();
			y.pop_front();
		}
		else {
			x.pop_back();
			y.pop_back();
		}
	}
	return c;

}

void solve(std::ifstream& input)
{
	std::deque<double> x, y;
	int c;
	input >> c;
	double tmp;
	for(int i =0; i < c;++i) {
		input >> tmp;
		x.push_back(tmp);
	}
	for(int i =0; i < c;++i) {
		input >> tmp;
		y.push_back(tmp);
	}
	std::sort(x.begin(), x.end());
	std::sort(y.begin(), y.end());
	std::cout << deceitful_war(x, y) << " " << war(x, y) << "\n";
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
