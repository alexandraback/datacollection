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
	int x ;
	int y;
	input >> x>> y;
	char result [502];
	int pos = 0;
	if(x < 0) {
		for(int i = 0; i < (-x) ;++i) {
			result[pos] = 'E';	
			result[pos+1] = 'W';
			pos +=2;
		}
	}
	else {
		for(int i = 0; i < x ;++i) {
			result[pos] = 'W';	
			result[pos+1] = 'E';
			pos +=2;
		}
	}
	
	if(y <0) {
		for(int i = 0; i < (-y) ;++i) {
			result[pos] = 'N';	
			result[pos+1] = 'S';
			pos +=2;
		}
	} 
	else {
		for(int i = 0; i < y ;++i) {
			result[pos] = 'S';	
			result[pos+1] = 'N';
			pos +=2;
		}
	}
	result[pos] = 0;
	printf("%s\n", result);
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
