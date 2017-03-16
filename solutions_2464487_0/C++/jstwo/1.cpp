#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include <gmpxx.h>

void solve(int case_num, std::ifstream& input)
{
	std::string start, total;
	input >> start >> total;
	mpz_class a, b, c, d;
	b = start;
	b = b* 2 -1;
	a = 2;
	c = total;
	std::cout << "Case #" << case_num << ": " << (sqrt(b* b + 4 * a * c) - b) / (2 * a) << "\n";
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
		solve(i, in);
	}
	return 0;
}
